#ifndef PARSEHEADERFIELDS_HPP
#define PARSEHEADERFIELDS_HPP

#include <string>

class ParseHeaderFields
{
	public:
		enum State
		{
			S_FIELD,
			S_COLON,
			S_SPACES_BEFORE_VALUE,
			S_VALUE,
			S_SPACES_AFTER_VALUE,
			// S_END_R,
			// S_END_N,
			S_END,
		};
	private:
		std::string _field;
		std::string _value;
		State _state;



	public:
		ParseHeaderFields();
		ParseHeaderFields(ParseHeaderFields const & copy);
		~ParseHeaderFields();
		ParseHeaderFields& operator=(ParseHeaderFields const & ope);

		void parse(char c);

		State get_state()
		{
			return(_state);
		}

		std::string get_field()
		{
			return(_field);
		}
};

//

#endif