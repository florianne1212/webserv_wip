#include "parseHeaderFields.hpp"

ParseHeaderFields::ParseHeaderFields(/* args */)
{
}

ParseHeaderFields::ParseHeaderFields(ParseHeaderFields const & copy)
{

}

ParseHeaderFields::~ParseHeaderFields()
{
}

ParseHeaderFields& ParseHeaderFields::operator=(ParseHeaderFields const & ope)
{

}

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
            if(c == ' ')
                S_SPACES_BEFORE_VALUE;
            
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
            if(c == '\n')
            else if(c == '\r')
            else if(c == ' ')
            {
                _value +=c
                _state = S_VALUE;
            }
			break;
		}
        case 
		// case(S)
	}
}