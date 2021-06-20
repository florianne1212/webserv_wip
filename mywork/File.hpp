#ifndef FILE_HPP
# define FILE_HPP

#include <string>
#include <sys/stat.h>
#include <dirent.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <list>
#include <iterator>
#include <iostream>
#include <fstream> 

class File{

	private:
		std::string _path;
		struct stat _stats;


	public:
	    File(/* args */);
		File(std::string path);
		// File(File const & copy);
		~File();
		// File& operator=(File const & ope);

		bool isPresent();
		bool isFile();
		bool isDirectory();
		bool fileDelete();
		bool fileCreate(std::string filename);
		std::list<std::string> listDirFiles();
		std::string find_content();


};

#endif