#ifndef FILE_HPP
# define FILE_HPP

#include <string>
#include <sys/stat.h>
#include <stdio.h>
#include <unistd.h>

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


};

#endif