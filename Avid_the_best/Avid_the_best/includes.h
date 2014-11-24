#ifndef INCLUDES_H_
#define INCLUDES_H_

#include <windows.h>
#include <Guiddef.h>
#include <exception>
#include <new>
#include <Shlwapi.h>
#include <shlobj.h>
#include <set>
#include <atlstr.h>
#include <strsafe.h>
#include <fstream>
#include <string>
#include <thread>

#pragma comment(lib, "shlwapi.lib")

STDAPI DllGetClassObject(REFCLSID, REFIID, void **);
STDAPI DllCanUnloadNow();
STDAPI DllRegisterServer();
STDAPI DllUnregisterServer();

#endif