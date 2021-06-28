#ifndef PARSEBODY_HPP
#define PARSEBODY_HPP

#include <string>
#include <map>

class ParseBody
{

public:
	enum State
	{
		S_PARSE,
		S_END,
	};
private:
	std::string _Body;
	State _state;
public:
    ParseBody();
	ParseBody(std::string ParseBody);
    ParseBody(ParseBody const & copy);
    ~ParseBody();
    ParseBody & operator=(ParseBody const & ope);

public:
	void parse(char c, std::map<std::string, std::string> _headers);
	void parse_chunked(char c);
	void parse_identity(char c);
	std::string get_Body()
	{
		return(_Body);
	}
	State get_state()
	{
		return(_state);
	}

};

// GET 
// POST
// DELETE

#endif