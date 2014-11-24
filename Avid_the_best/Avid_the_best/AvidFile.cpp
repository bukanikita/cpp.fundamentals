#include "AvidFile.h"

AvidFile::AvidFile(const wstring &_name)
{
	name = _name;
	all_info = L"Name: " + name.substr(name.find_last_of(L"/\\") + 1) + L"; ";
	get_info();
}

void AvidFile::get_info()
{
	HANDLE hFile = CreateFile(
					name.c_str(),
					FILE_READ_DATA,
					FILE_SHARE_READ | FILE_SHARE_WRITE,
					NULL,
					OPEN_EXISTING,
					FILE_ATTRIBUTE_NORMAL,
					NULL);
	if (hFile != INVALID_HANDLE_VALUE)
	{
		get_size(hFile);
		get_date(hFile);
		CloseHandle(hFile);
	}
	else
	{
		all_info += L"Size: undefined; Creation date: undefined; ";
	}
	get_checksum();
}

bool AvidFile::operator<(const AvidFile &av_file) const
{
	return name < av_file.name;
}

void AvidFile::get_size(const HANDLE &_hFile)
{
	const int bytes_num = 4;
	un_l_l temp;
	const un_l_l bytes_val[bytes_num] = {1, 1 << 10, 1 << 20, 1 << 30};
	const wstring bytes_names[bytes_num] = {L"B", L"KB", L"MB", L"GB"};
	DWORD file_size = 0;
	file_size = GetFileSize(_hFile, NULL);
	if (file_size)
	{
		all_info += L"Size:";
		for (int i = bytes_num - 1; i >= 0; --i)
		{
			temp = file_size / bytes_val[i];
			if (temp)
			{
				file_size %= bytes_val[i];
				all_info += L" " + std::to_wstring(temp) + bytes_names[i];
			}
		}
		all_info += L"; ";
	}
	else
	{
		all_info += L"Size: undefined; ";
	}
}

void AvidFile::get_date(const HANDLE &_hFile)
{
	FILETIME date_of_creation;
	SYSTEMTIME sys_time_creation;
	if (GetFileTime(_hFile, &date_of_creation, NULL, NULL) && FileTimeToSystemTime(&date_of_creation, &sys_time_creation))
	{
		all_info += L"Creation date: "
				 + std::to_wstring(sys_time_creation.wDay)
				 + L"." 
				 + std::to_wstring(sys_time_creation.wMonth)
				 + L"." 
				 + std::to_wstring(sys_time_creation.wYear)
				 + L" " 
				 + std::to_wstring(sys_time_creation.wHour)
				 + L":" 
				 + std::to_wstring(sys_time_creation.wMinute)
				 + L":" 
				 + std::to_wstring(sys_time_creation.wSecond)
				 + L"; ";
	}
	else
	{
		all_info += L"Creation date: undefined; ";
	}
}

void AvidFile::get_checksum()
{
	std::ifstream file (name, std::ios::binary);
	char c;
	un_l_l per_byte_sum = 0;

	if (file.is_open())
	{
		while(file.read(&c, sizeof(char)))
		{
			per_byte_sum += static_cast<un_l_l> (c);
		}
		file.close();
		all_info += L"Per byte sum: " + std::to_wstring(per_byte_sum) + L";";
	}
	else
	{
		all_info += L"Per byte sum: undefined;";
	}
}