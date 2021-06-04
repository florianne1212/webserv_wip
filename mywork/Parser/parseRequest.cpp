
#include "ParseRequest.hpp"

ParseRequest::ParseRequest(/* args */)
{
}

ParseRequest::ParseRequest(ParseRequest const & copy)
{

}

ParseRequest::~ParseRequest()
{
}

ParseRequest& ParseRequest::operator=(ParseRequest const & ope)
{

}

void ParseRequest::parse(char c)
{
	switch(_state)
	{
		case S_NOT_STARTED:
		{
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
	}
}