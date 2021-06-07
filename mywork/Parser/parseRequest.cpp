
#include "parseRequest.hpp"

ParseRequest::ParseRequest(/* args */):
_state(S_NOT_STARTED)
{
}

// ParseRequest::ParseRequest(ParseRequest const & copy)
// {

// }

ParseRequest::~ParseRequest()
{
}

// ParseRequest& ParseRequest::operator=(ParseRequest const & ope)
// {

// }

void ParseRequest::parse(char c)
{
	switch(_state)
	{
		
		case S_NOT_STARTED:
		{
			printf("hey !");
			if(c == '\r' || c == '\n')
				break;
			else
				_state = S_METHOD;
		}
		case(S_METHOD):
		{
			if(c == ' ')
			{
				if(_state == S_NOT_STARTED)
					throw ("there is no method");
				_state = S_SPACES_BEFORE_PATH;
			}
			else
			{
				if(islower(c))
					throw ("method is supposed to be uppercase");
				if(_method.length() > 15)
					throw ("method can't be that long");
			}
			_method += c;
		}
		case(S_SPACES_BEFORE_PATH):
		{
			if(c != ' ')
			{
				if(c == '/')
					_state = S_PATH;
				else
					throw ("method can't be that long");
			}
			break;
		}
		case(S_PATH):
		{
			if(c != ' ')
				_method += c;
			else
				_state = S_HTTP_START;
		}
		case(S_HTTP_START):
		{
			if(c != 'H')
				throw ("wrong charachter must be : H");
			_state = S_HTTP_H;
			break;
		}
		case(S_HTTP_H):
		{
			if(c != 'T')
				throw ("wrong charachter must be : T");
			_state = S_HTTP_HT;
			break;
		}
		case(S_HTTP_HT):
		{
			if(c != 'T')
				throw ("wrong charachter must be : T");
			_state = S_HTTP_HTT;
			break;
		}
		case(S_HTTP_HTT):
		{
			if(c != 'P')
				throw ("wrong charachter must be : P");
			_state = S_HTTP_HTTP;
			break;
		}
		case(S_HTTP_HTTP):
		{
			if(c != '/')
				throw ("wrong charachter must be : /");
			_state = S_HTTP_SLASH;
			break;
		}
		case(S_HTTP_SLASH):
		{
			if(c != '/')
				throw ("wrong charachter must be : /");
			_state = S_HTTP_MAJOR;
			break;
		}
		case(S_HTTP_MAJOR):
		{
			if(!isdigit(c))
				throw ("http version major must be a number");
			if(c != 1)
				throw ("wrong version only HTTP/1.1 is supported");
			_major = c - '0';
			_state = S_HTTP_DOT;
			break;
		}
		case(S_HTTP_DOT):
		{
			if(!isdigit(c != '.'))
				throw ("wrong character must be : .");
			_state = S_HTTP_MINOR;
			break;
		}
		case(S_HTTP_MINOR):
		{
			if(!isdigit(c))
				throw ("http version minor must be a number");
			if(c != 1)
				throw ("wrong version only HTTP/1.1 is supported");
			_minor = c - '0';
			_state = S_HTTP_END_R;
			break;
		}

		case(S_HTTP_END_R):
		{
			if(c != '\n')
				throw ("expected return line (\\n)");
			else
				_state = S_HTTP_END_N;
			
			break;
		}

		case(S_HTTP_END_N):
		{
			if(c == '\n')
				_state = S_HTTP_END_N;
			else if(c == '\r')
				_state = S_END;
			else
			{
				_state = S_HEADER_FIELDS;
				_parseHeaderFields.parse(c);
			}

			break;
		}

		case(S_END):
			break;

		case(S_HEADER_FIELDS):
		{
			_parseHeaderFields.parse(c);
			if(_parseHeaderFields.get_state() == ParseHeaderFields::S_END)
				_state = S_END;
		}
	}
}