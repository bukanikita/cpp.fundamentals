#ifndef FILE_PROC_H_
#define FILE_PROC_H_

#include "includes.h"
#include "AvidFile.h"

using std::set;

class FileProc
{
private:
	typedef set<AvidFile>::iterator file_it;

	FileProc(const FileProc &); // we hide copy constructor
	FileProc &operator=(const FileProc &); // we hide assign operation

	AvidFile *file; // pointer to file, which is processing
	file_it curr_file; // current file in process 
	file_it last_file; // last file to process
	std::wofstream log_file; // file for log writing

	std::list<std::thread*> threads; // list of threads
	std::mutex mut, mtx; //mutexex
	mutable std::condition_variable cond_item_ready; // conditional variable to indicate if last file was processed
	unsigned int threads_number; // number of threads

	void create_log(); // function for creation of log file
	void threads_init(); // threads initialization
	void exec(); // execution function in every thread
public:
	FileProc(file_it, file_it); // constructor with iterator to start and to end
	~FileProc(); 
	bool proc(); // function, which should be called to start processing
};

#endif;