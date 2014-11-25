#include "FileProc.h"

FileProc::FileProc(file_it _begin, file_it _end) : curr_file (_begin), last_file(_end)
{
	create_log();
	threads_init();
}

FileProc::~FileProc()
{
	log_file.close();
	for (auto th : threads) // delete every thread
	{
		th->join();
		delete th;
	}
}

void FileProc::create_log()
{
	if (CreateDirectory(L"C:\\Avid_the_best\\", NULL) != 0 || GetLastError() == ERROR_ALREADY_EXISTS) 
	{
		log_file.open(L"C:\\Avid_the_best\\log_file.log", std::ofstream::app); // open file and add information to it
		if (!log_file.is_open()) 
		{
			throw std::exception("Log file problems!\n"); // exception if problems with file
		}
	}
	else
	{
		throw std::exception("Log file problems!\n"); // exception if problems with file
	}
}

void FileProc::threads_init()
{
	threads_number = std::thread::hardware_concurrency(); // get maximum number of threads
}

bool FileProc::proc()
{
	set<AvidFile>::iterator first_file = curr_file; // it's important for writing to log file

	for (unsigned int i = 0; i < threads_number; ++i) 
	{
		threads.push_back(new std::thread(&FileProc::exec, this));
	}
	std::unique_lock<std::mutex> lck(mtx);

	while (first_file != last_file)
	{
		while (!(*first_file).isReady()) // we are waiting for file, while it isn't ready
		{
			cond_item_ready.wait(lck);
		}
		log_file << (*first_file).Show(); // writing info about file
		++first_file;
	}

	return true;
}

void FileProc::exec()
{
	while (curr_file != last_file) 
	{
		mut.lock();
		file = const_cast<AvidFile*>(&(*curr_file));
		++curr_file;
		mut.unlock();
		file->get_info(); // get information about file
		cond_item_ready.notify_all();
	}
}
