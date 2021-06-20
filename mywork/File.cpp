#include "File.hpp"

File::File()
{

}

File::File(std::string path):
_path(path)
{

}

// File::File(File const & copy)
// {

// }

File::~File()
{

}

// File& File::operator=(File const & ope)
// {

// }

bool File::isPresent()
{
	if(::stat(_path.c_str(), &_stats) == -1)
		return (false);
	else 
		return (true);
}

bool File::isFile()
{
	return(S_ISREG(_stats.st_mode));
}

bool File::isDirectory()
{
	return(S_ISDIR(_stats.st_mode));
}

bool File::fileDelete()
{
	if (remove(_path.c_str()) == 0)
		return (true);
	else
		return (false);
}

bool File::fileCreate(std::string filename)
{
	int fd;

	fd = open(filename.c_str(), O_CREAT);

	close(fd);

	return(true);

}

std::list<std::string> File::listDirFiles()
{
	DIR *d;
	struct dirent *dir;
	std::list<std::string> files_list;

	d = opendir(_path.c_str());
	if(d)
	{
		while ((dir = readdir(d)) != NULL)
		{
			files_list.push_back(dir->d_name);
		}
		closedir(d);
	}
	
	return(files_list);
}

std::string File::find_content()
{
	// int fd;
	// std::string content;

	std::ifstream ifs(_path.c_str());
	std::string content( (std::istreambuf_iterator<char>(ifs) ),
						(std::istreambuf_iterator<char>()) );

	return(content);
	
}