#include "AvidContextMenu.h"

extern HINSTANCE g_hInst;
extern long g_cDllRef;

AvidContextMenu::AvidContextMenu() : m_cRef(1), 
	m_pszMenuText(L"Avid show information"),
	m_pszVerb("avidshow"),
	m_pwszVerb(L"avidshow"),
	m_pszVerbCanonicalName("AvidFileShow"),
	m_pwszVerbCanonicalName(L"AvidFileShow"),
	m_pszVerbHelpText("Display File Name (C++)"),
	m_pwszVerbHelpText(L"Display File Name (C++)")
{
	InterlockedIncrement(&g_cDllRef);
}

AvidContextMenu::~AvidContextMenu()
{
	InterlockedDecrement(&g_cDllRef);
}

void AvidContextMenu::OnVerbDisplayFileName(HWND hWnd)
{
	try // try to get info
	{
		FileProc proc(all_files.begin(), all_files.end());
		if (proc.proc()) // if processing had success 
		{
			int j; // for items_to_display number of elements in MessageBox
			std::wstring full_text; // text in message box
			std::set<AvidFile>::iterator start; // starting iterator for every MessageBox
			for (unsigned int i = 0; i < all_files.size(); i += items_to_display) // dispaly items_to_display elements
			{
				if (i == 0) // if the first MessageBox we start from begin of container
				{
					start = all_files.begin();
				}
				j = 0;
				full_text = L""; // empty text at the start
				std::set<AvidFile>::iterator it;
				for (it = start; j < items_to_display && it != all_files.end(); ++it, ++j)
				{
					full_text += (*it).Show();
				}
				MessageBox(hWnd, full_text.c_str(), L"Avid information", MB_OK);
				start = it;
			}
		}
		else
		{
			throw std::exception("Problems with proc function!\n");
		}
	}
	catch (std::exception &e) 
	{
		int mes_length =  MultiByteToWideChar( CP_UTF8 , 0 , e.what() , -1, NULL , 0 );
		wchar_t* mes_error = new wchar_t[mes_length];
		MultiByteToWideChar( CP_UTF8 , 0 , e.what() , -1, mes_error, mes_length);
		MessageBox(hWnd, mes_error, L"Avid information", MB_OK);
		delete[] mes_error;
	}
	catch (...)
	{
		MessageBox(hWnd, L"Unknown exception occurred!\n", L"Avid information", MB_OK);
	}
}

IFACEMETHODIMP AvidContextMenu::QueryInterface(REFIID riid, void **ppv)
{
	static const QITAB qit[] = { QITABENT(AvidContextMenu, IContextMenu), QITABENT(AvidContextMenu, IShellExtInit), { 0 } };
	return QISearch(this, qit, riid, ppv);
}

IFACEMETHODIMP_(ULONG) AvidContextMenu::AddRef()
{
	return InterlockedIncrement(&m_cRef);
}

IFACEMETHODIMP_(ULONG) AvidContextMenu::Release()
{
	ULONG cRef = InterlockedDecrement(&m_cRef);
	if (cRef == 0)
	{
		delete this;
	}

	return cRef;
}

IFACEMETHODIMP AvidContextMenu::Initialize(LPCITEMIDLIST pidlFolder, LPDATAOBJECT pDataObj, HKEY hKeyProgID)
{
	if (pDataObj == NULL)
	{
		return E_INVALIDARG;
	}

	HRESULT hr = E_FAIL;
	FORMATETC fe = { CF_HDROP, NULL, DVASPECT_CONTENT, -1, TYMED_HGLOBAL };
	STGMEDIUM stm;

	if (SUCCEEDED(pDataObj->GetData(&fe, &stm)))
	{
		HDROP hDrop = static_cast<HDROP>(GlobalLock(stm.hGlobal));
		if (hDrop != NULL)
		{
			UINT nFiles = DragQueryFile(hDrop, 0xFFFFFFFF, NULL, 0);
			hr = E_FAIL;
			for (unsigned int i = 0; i < nFiles; ++i)
			{
				if (!DragQueryFile(hDrop, i, m_szSelectedFile, ARRAYSIZE(m_szSelectedFile)))
				{
					continue;
				}
				AvidFile temp(m_szSelectedFile);			
				all_files.insert(temp);
				hr = S_OK;
			}
			GlobalUnlock(stm.hGlobal);
		}
		ReleaseStgMedium(&stm);
	}
	return hr;
}

IFACEMETHODIMP AvidContextMenu::QueryContextMenu(HMENU hMenu, UINT indexMenu, UINT idCmdFirst, UINT idCmdLast, UINT uFlags)
{
	if (CMF_DEFAULTONLY & uFlags)
	{
		return MAKE_HRESULT(SEVERITY_SUCCESS, 0, USHORT(0));
	}

	MENUITEMINFO sep = { sizeof(sep) };
	sep.fMask = MIIM_TYPE;
	sep.fType = MFT_SEPARATOR;

	MENUITEMINFO mii = { sizeof(mii) };
	mii.fMask = MIIM_STRING | MIIM_FTYPE | MIIM_ID | MIIM_STATE;
	mii.wID = idCmdFirst + IDM_DISPLAY;
	mii.fType = MFT_STRING;
	mii.dwTypeData = m_pszMenuText;
	mii.fState = MFS_ENABLED;

	if (!InsertMenuItem(hMenu, indexMenu, TRUE, &sep) || !InsertMenuItem(hMenu, indexMenu + 1, TRUE, &mii) || !InsertMenuItem(hMenu, indexMenu + 2, TRUE, &sep))
	{
		return HRESULT_FROM_WIN32(GetLastError());
	}

	return MAKE_HRESULT(SEVERITY_SUCCESS, 0, USHORT(IDM_DISPLAY + 1));
}

IFACEMETHODIMP AvidContextMenu::InvokeCommand(LPCMINVOKECOMMANDINFO pici)
{
	BOOL fUnicode = FALSE;

	if (pici->cbSize == sizeof(CMINVOKECOMMANDINFOEX))
	{
		if (pici->fMask & CMIC_MASK_UNICODE)
		{
			fUnicode = TRUE;
		}
	}

	if (!fUnicode && HIWORD(pici->lpVerb))
	{
		if (StrCmpIA(pici->lpVerb, m_pszVerb) == 0)
		{
			OnVerbDisplayFileName(pici->hwnd);
			return S_OK;
		}
	}
	else if (fUnicode && HIWORD(((CMINVOKECOMMANDINFOEX*)pici)->lpVerbW))
	{
		if (StrCmpIW(((CMINVOKECOMMANDINFOEX*)pici)->lpVerbW, m_pwszVerb) == 0)
		{
			OnVerbDisplayFileName(pici->hwnd);
			return S_OK;
		}
	}
	else
	{
		if (LOWORD(pici->lpVerb) == IDM_DISPLAY)
		{
			OnVerbDisplayFileName(pici->hwnd);
			return S_OK;
		}
	}
	return E_FAIL;
}