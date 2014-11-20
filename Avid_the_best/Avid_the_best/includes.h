#ifndef INCLUDES_H_
#define INCLUDES_H_

#include <windows.h>
#include <Guiddef.h>
#include <exception>
#include <new>
#include <Shlwapi.h>
#include <strsafe.h>

#pragma comment(lib, "shlwapi.lib")

STDAPI DllGetClassObject(REFCLSID, REFIID, void **);
STDAPI DllCanUnloadNow();
STDAPI DllRegisterServer();
STDAPI DllUnregisterServer();

#endif