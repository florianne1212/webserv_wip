#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>
#include <map>
#include <vector>

class Request
{
	private:
		std::string _methods;
		std::string url;
		std::string version;
		std::map<std::string, std::string> headers;
		

	public:
		Request();
		Request (Request const & copy);
		~Request();
		Request& operator=(Request const & ope);

		std::vector<std::string> createMethods();
		std::string getMethods();

		void setMethods(std::string str);
};

//methods
//url
//headers
//page

#endif