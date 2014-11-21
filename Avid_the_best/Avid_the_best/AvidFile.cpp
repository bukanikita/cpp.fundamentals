#include "AvidFile.h"

AvidFile::AvidFile(wchar_t *_name)
{
	name = _name;
	all_info = "Name: " + name + ";";
	get_info();
}

void AvidFile::get_info()
{
	HANDLE hFile = CreateFile(
					name,
					FILE_READ_DATA,
					FILE_SHARE_READ | FILE_SHARE_WRITE,
					NULL,
					OPEN_EXISTING,
					FILE_ATTRIBUTE_NORMAL,
					NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		DWORD file_size = 0;
		FILETIME date_of_creation;
		SYSTEMTIME sys_time_creation;
		file_size = GetFileSize(hFile, NULL);
		if (file_size)
		{
			all_info.Format(L"%s Size: %ul;", all_info, file_size);
		}
		else
		{
			all_info.Format(L"%s Size: undefined;", all_info);
		}
		if (GetFileTime(hFile, &date_of_creation, NULL, NULL) && FileTimeToSystemTime(&date_of_creation, &sys_time_creation))
		{
			all_info.Format(L"%s Creation date: %hu.%hu.%hu %hu:%hu:%hu;", all_info, 
															   sys_time_creation.wDay, 
															   sys_time_creation.wMonth, 
															   sys_time_creation.wYear, 
															   sys_time_creation.wHour,
															   sys_time_creation.wMinute,
															   sys_time_creation.wSecond);
		}
		else
		{
			all_info.Format(L"%s Creation date: undefined;", all_info);
		}

	}
	else
	{
		all_info.Format(L"%s Size: undefined; Creation date: undefined;", all_info);
	}
}

bool AvidFile::operator<(const AvidFile &av_file)const
{
	return name < av_file.name;
}