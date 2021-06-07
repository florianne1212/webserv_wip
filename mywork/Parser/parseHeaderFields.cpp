#include "parseHeaderFields.hpp"
#include <stdio.h>
#include <iostream>

ParseHeaderFields::ParseHeaderFields():
_state(S_FIELD)
{
}

// ParseHeaderFields::ParseHeaderFields(ParseHeaderFields const & copy)
// {

// }

ParseHeaderFields::~ParseHeaderFields()
{
}

// ParseHeaderFields& ParseHeaderFields::operator=(ParseHeaderFields const & ope)
// {

// }

void ParseHeaderFields::parse(char c)
{
	switch(_state)
	{
		case S_FIELD:
		{
			if(c == ' ')
			{
				if(_field.empty())
					throw ("there is some space before field");
				else
					throw ("there is some space before fields");
				   
			}
			else if(c == ':')
				 _state=S_COLON;
			else
				_field += c;

			break;
		}
		case(S_COLON):
		{
			std::cout << _field;
			if(c == ' ')
				_state = S_SPACES_BEFORE_VALUE;
			
			break;
		}
		case(S_SPACES_BEFORE_VALUE):
		{

			if(c != ' ')
			{
				_state = S_VALUE;
				_value += c;
			}
			break;
		}
		case(S_VALUE):
		{
			if(c == ' ')
				_state = S_SPACES_AFTER_VALUE;
			else  
				_value += c;
			break;
		}
		case(S_SPACES_AFTER_VALUE):
		{
			// if(c == '\n')
			// 	_state=S_END;
			// else if(c == '\r')
			// 	_state=S_END;
			// else if(c == ' ')
			// {
			// 	_value +=c;
			// 	_state = S_VALUE;
			// }
			_state = S_END;
			break;
		}
		// case (S_END_R):
		// {

		// }
		// case (S_END):
		// {
			
		// }

		// case(S_END_R):
		// {
		// 	if(c != '\n')
		// 		throw ("expected return line (\\n)");
		// 	else
		// 		_state = S_HTTP_END_N;
			
		// 	break;
		// }

		// case(S_END_N):
		// {
		// 	if(c == '\n')
		// 		_state = S_HTTP_END_N;
		// 	else if(c == '\r')
		// 		_state = S_END;
		// 	else
		// 	{
		// 		_state = S_HEADER_FIELDS;
		// 		_parseHeaderFields.parse(c);
		// 	}

		// 	break;
		// }

		case(S_END):
			break;
		// case(S)
	}
}
