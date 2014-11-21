#include "ClassFactory.h"
#include "registry.h"

HINSTANCE g_hInst = NULL;
long g_cDllRef = 0;

// GUID for Avid the best: {CF23BECA-7628-4b50-AB9A-A34F91A8A334}
static const GUID CLSID_Avid_the_best = { 0xfaac23b3, 0xc327, 0x41ee, { 0x9d, 0xe3, 0x92, 0xf, 0x2, 0x9d, 0x5, 0x14 } };

BOOL APIENTRY DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
	case DLL_PROCESS_ATTACH:
		g_hInst = hModule;
		DisableThreadLibraryCalls(hModule);
		break;
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

/*	
	Function for creating class factory
	Input parameters:
	rclsid - The CLSID that will associate the correct data and code.
	riid - A reference to the identifier of the interface that the caller is to use to communicate with the class object.
	ppv - The address of a pointer variable that receives the interface pointer requested in riid. Upon successful return, *ppv contains the 
	requested interface pointer. If an error occurs, the interface pointer is NULL. 
*/
STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void **ppv)
{
	HRESULT hr = CLASS_E_CLASSNOTAVAILABLE;

	if (IsEqualCLSID(CLSID_Avid_the_best, rclsid))
	{
		hr = E_OUTOFMEMORY;
		ClassFactory *pClassFactory;

		try
		{
			pClassFactory = new ClassFactory();
		}
		catch(std::bad_alloc &e)
		{
			OutputDebugString(reinterpret_cast<LPCWSTR> (e.what()));
			return hr;
		}

		hr = pClassFactory->QueryInterface(riid, ppv); // get interface from class factory
		pClassFactory->Release(); // decrement number of class factory usage
	}
	return hr;
}

// Function for component deleting ability. It can be deleted if no one is using this component
STDAPI DllCanUnloadNow()
{
	return g_cDllRef > 0 ? S_FALSE : S_OK;
}

// Function to register component 
STDAPI DllRegisterServer()
{
	HRESULT hr;

	wchar_t szModule[MAX_PATH];
	if (GetModuleFileName(g_hInst, szModule, ARRAYSIZE(szModule)) == 0)
	{
		hr = HRESULT_FROM_WIN32(GetLastError());
		return hr;
	}

	// Register the component.
	hr = RegisterInprocServer(szModule, CLSID_Avid_the_best, 
		L"Avid_the_best.AvidContextMenu Class", 
		L"Apartment");
	if (SUCCEEDED(hr))
	{
		// Register the context menu handler. The context menu handler is 
		// associated with the .cpp file class.
		hr = RegisterShellExtContextMenuHandler(L"*", 
			CLSID_Avid_the_best, 
			L"Avid_the_best.AvidContextMenu");
	}

	return hr;
}


//
// Function to unregister component 
STDAPI DllUnregisterServer()
{
	HRESULT hr = S_OK;

	wchar_t szModule[MAX_PATH];
	if (GetModuleFileName(g_hInst, szModule, ARRAYSIZE(szModule)) == 0)
	{
		hr = HRESULT_FROM_WIN32(GetLastError());
		return hr;
	}

	// Unregister the component.
	hr = UnregisterInprocServer(CLSID_Avid_the_best);
	if (SUCCEEDED(hr))
	{
		// Unregister the context menu handler.
		hr = UnregisterShellExtContextMenuHandler(L"*", CLSID_Avid_the_best);
	}

	return hr;
}