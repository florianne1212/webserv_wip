#ifndef PARSEREQUEST_HPP
#define PARSEREQUEST_HPP

#include <string>
#include "parseHeaderFields.hpp"
#include "stdio.h"
#include "Message.hpp"

class ParseRequest
{
	public:
		enum State
		{
			S_NOT_STARTED = 0,
			S_METHOD,
			S_SPACES_BEFORE_PATH,
			S_PATH,
			// S_HTTP_START,
			S_HTTP_H,
			S_HTTP_HT,
			S_HTTP_HTT,
			S_HTTP_HTTP,
			S_HTTP_SLASH,
			S_HTTP_MAJOR,
			S_HTTP_DOT,
			S_HTTP_MINOR,
			S_HTTP_END_R,
			S_HTTP_END_N,
			S_HEADER_FIELDS,
			// S_BODY,
			// S_BODY_DECODE,
			// S_END_R,
			S_END,
		};
	private:
		std::string _method;
		std::string _path;
		int _major;
		int _minor;
		State _state;
		ParseHeaderFields _parseHeaderFields;



	public:
		ParseRequest();
		ParseRequest(ParseRequest const & copy);
		~ParseRequest();
		ParseRequest& operator=(ParseRequest const & ope);

		void parse(char c);
		void parse_path(char c);

		std::string get_method()
		{
			return(_method);
		}

		std::string get_path()
		{
			return(_path);
		}

		int get_major()
		{
			return(_major);
		}

		int get_minor()
		{
			return(_minor);
		}

		ParseHeaderFields get_parserfields()
		{
			return(_parseHeaderFields);
		}
		 
};

//

#endif