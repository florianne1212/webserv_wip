#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <string>
#include <map>
#include <vector>

class Request
{
	private:
		std::string _methods;
		std::string _url;
		std::string _version;
		std::map<std::string, std::string> headers;
		

	public:
		Request();
		Request (Request const & copy);
		~Request();
		Request& operator=(Request const & ope);

		std::vector<std::string> createMethods();
		std::string getMethods();
		std::string getUrl();
		std::string getVersion();

		void setMethods(std::string str);
		void setUrl(std::string str);
		void setVersion(std::string str);
};

//methods
//url
//headers
//page

#endif