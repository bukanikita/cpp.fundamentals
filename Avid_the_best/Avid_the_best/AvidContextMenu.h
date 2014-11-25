#ifndef AVID_CONTEXT_MENU_H_
#define AVID_CONTEXT_MENU_H_

#include "includes.h"
#include "AvidFile.h"
#include "FileProc.h"

class AvidContextMenu : public IShellExtInit, public IContextMenu
{
private:
	static const int items_to_display = 20;
	static const int IDM_DISPLAY = 0;
	long m_cRef; // Reference count of component.
	wchar_t m_szSelectedFile[MAX_PATH]; // The name of the selected file.
	std::set<AvidFile> all_files;
	void OnVerbDisplayFileName(HWND); // The method that handles the "display" verb.
	PWSTR m_pszMenuText;
	PCSTR m_pszVerb;
	PCWSTR m_pwszVerb;
	PCSTR m_pszVerbCanonicalName;
	PCWSTR m_pwszVerbCanonicalName;
	PCSTR m_pszVerbHelpText;
	PCWSTR m_pwszVerbHelpText;
protected:
	~AvidContextMenu();

public:
	AvidContextMenu();
    IFACEMETHODIMP QueryInterface(REFIID, void **);// Query to the interface the component supported.
    IFACEMETHODIMP_(ULONG) AddRef();// Increase the reference count for an interface on an object.
    IFACEMETHODIMP_(ULONG) Release();// Decrease the reference count for an interface on an object.
    IFACEMETHODIMP Initialize(LPCITEMIDLIST, LPDATAOBJECT, HKEY);// Initialize the context menu handler.
    IFACEMETHODIMP QueryContextMenu(HMENU, UINT, UINT, UINT, UINT); // Function for adding items in context menu
    IFACEMETHODIMP InvokeCommand(LPCMINVOKECOMMANDINFO); // method for running command, when user clicks item
	IFACEMETHODIMP GetCommandString(UINT_PTR idCommand, UINT uFlags, UINT *pwReserved, LPSTR pszName, UINT cchMax) { return S_OK; };
};

#endif