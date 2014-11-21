#ifndef REGISTER_H_
#define REGISTER_H_

#include "includes.h"

/*   
	Function for adding component to the registry.
	Input parameters:
	pszModule - Path of the module that contains the component
	clsid - Class ID of the component
	pszFriendlyName - Friendly name
	pszThreadModel - Threading model
*/
HRESULT RegisterInprocServer(PCWSTR, const CLSID&, PCWSTR, PCWSTR);

/*
	Function for creating HKEY_CLASSES_ROOT key and set value of registry
	Input parameters:
	pszSubKey - the registry key in HKEY_CLASSES_ROOT.
	pszValueName - the registry value in HKEY_CLASSES_ROOT.
	pszData - data of the registry value in HKEY_CLASSES_ROOT.
*/
HRESULT SetHKCRRegistryKeyAndValue(PCWSTR, PCWSTR, PCWSTR);

/*
	Function for registration of handler of context menu.
	Input parameters:
	pszFileType - The file type that the context menu handler is associated with.
	clsid - Class ID of the component
	pszFriendlyName - Friendly name
*/
HRESULT RegisterShellExtContextMenuHandler(PCWSTR, const CLSID&, PCWSTR);

/*
	Function for getting data from HKEY_CLASSES_ROOT registry key if it exists.
	Input parameters:
	pszSubKey - specifies the registry key under HKCR. If the key does not exist, the function returns an error.
	pszValueName - specifies the registry value to be retrieved. If pszValueName is NULL, the function will get the default value.
	pszData - a pointer to a buffer that receives the value's string data.
	cbData - specifies the size of the buffer in bytes.
*/
HRESULT GetHKCRRegistryKeyAndValue(PCWSTR pszSubKey, PCWSTR pszValueName, PWSTR pszData, DWORD cbData);

/*
	Function for unregister component.
	Input parameters:
	clsid - Class ID of the component
*/
HRESULT UnregisterInprocServer(const CLSID&);

/*
	Function for unregister of handler of context menu.
	Input parameters:
	pszFileType - The file type that the context menu handler is associated with.
	clsid - Class ID of the component
*/
HRESULT UnregisterShellExtContextMenuHandler(PCWSTR, const CLSID&);

#endif