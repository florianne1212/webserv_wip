#ifndef PARSEREQUEST_HPP
#define PARSEREQUEST_HPP

#include <string>

class ParseRequest
{
	public:
		enum State
		{
			S_NOT_STARTED = 0,
			S_METHOD,
			S_SPACES_BEFORE_PATH,
			S_PATH,
			S_HTTP_START,
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
			S_BODY,
			S_BODY_DECODE,
			S_END_R,
			S_END,
		};
	private:
		std::string _method;
		int _major;
		int _minor;
		State _state;



	public:
		ParseRequest();
		ParseRequest(ParseRequest const & copy);
		~ParseRequest();
		ParseRequest& operator=(ParseRequest const & ope);

		void parse(char c);
};

//

#endif