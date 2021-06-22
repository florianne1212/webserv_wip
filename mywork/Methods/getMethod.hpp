#ifndef GETMETHOD_HPP
# define GETMETHOD_HPP
#include "../request.hpp"
#include "../response.hpp"
#include "../Client.hpp"
#include "../File.hpp"
#include <iostream>
#include <sstream> 

class GetMethod
{
	public:
		GetMethod();
		GetMethod(GetMethod const & copy);
		~GetMethod();
		GetMethod& operator=(GetMethod const & ope);

		void handleGet(Client &client, Request &request, Response &response);
		void setHeader(Response &response, File &fileGet);
};

#endif

