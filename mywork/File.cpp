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