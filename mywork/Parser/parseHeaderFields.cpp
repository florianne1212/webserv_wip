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
				std::cout << "pouet";
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
			std::cout << "field :" << _field << "\n";
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
		// case(S_VALUE):
		// {
		// 	if(c == '\n')
		// 		_state=S_END_N;
		// 	else if(c == '\r')
		// 		_state=S_END_R;
		// 	else if (c == ' ')
		// 		_state = S_SPACES_AFTER_VALUE;
		// 	else  
		// 		_value += c;
		// 	break;
		// }
		// case(S_SPACES_AFTER_VALUE):
		// {
		// 	std::cout << "value :"<< _value << "\n";
		// 	if(c == '\n')
		// 		_state=S_END_N;
		// 	else if(c == '\r')
		// 		_state=S_END_R;
		// 	else if (c == ' ')
		// 		_state = S_SPACES_AFTER_VALUE;
		// 	else
		// 	{
		// 		_value +=c;
		// 		_state = S_VALUE;
		// 	}
		// 	break;
		// }

		// case (S_END_R):
		// {
		// 	if(c != '\n')
		// 		printf("%s\n", "expected return line (\\n)");
		// 	else
		// 		_state = S_END_N;
			
		// 	break;
		// }

		// case (S_END_N):
		// {
		// 	break;
		// }

		

		// case(S_END):
		// 	break;
		

		case S_VALUE:
		{
			if (c == ' ')
				_state = S_END;
			else if (c == '\r')
			{
				add_header();
				_state = S_END_R;
			}
			else if (c == '\n')
			{
				add_header();
				_state = S_END_N;
			}
			else
				_value += c;

			break;
		}

		case S_SPACES_AFTER_VALUE:
		{
			std::cout << "value : " << _value << "\n" ;
			if (c == ' ')
			{
				_state = S_SPACES_AFTER_VALUE;
			}
			else if (c == '\n')
			{
				add_header();
				_state = S_END_N;
			}
			else if (c == '\r')
			{
				add_header();
				_state = S_END_N;
			}
			else
			{
				_value += ' ';
				_value += c;
				_state = S_VALUE;
			}

			break;
		}

		case S_END_R:
		{
			if (c == '\n')
				_state = S_END_N;
			else
				printf("%s\n","Expected a \\n");

			break;
		}

		case S_END_N:
		{
			if (c == '\r')
				_state = S_END_R2;
			else if (c == '\n')
				_state = S_END;
			else
			{
				_state = S_FIELD;
			}

			break;
		}

		case S_END_R2:
		{
			if (c == '\n')
				_state = S_END;
			else
				throw printf("%s\n","Expected a \\n");

			break;
		}

		case S_END:
			return;
	}
}

void ParseHeaderFields::add_header()
{
	_headers.insert(std::pair<std::string, std::string>(_field, _value));
	std::cout << "value before clear: " << _value << "\n" ;
	_field.clear();
	_value.clear();
}
