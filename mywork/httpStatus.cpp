#include "HttpStatus.hpp"
#include <map>

std::map<int, std::string> status_error;

status_error[100]="Continue";
status_error[101]="Switching Protocol";
status_error[103]="Processing";
status_error[200]="OK";
status_error[201]="Created";
status_error[202]="Accepted";
status_error[203]="Non-Authoritative Information";
status_error[204]="No Content";
status_error[205]="Reset Content";
status_error[206]="Partial Content";
status_error[207]="Multi-Status";
status_error[208]="Already Reported";
status_error[226]="IM Used";
status_error[300]="Multiple Choice";
status_error[301]="Moved Permanently";
status_error[302]="Found";
status_error[303]="See Other";
status_error[304]="Not Modified";
status_error[305]="Use Proxy";
status_error[306]="unused";
status_error[307]="Temporary Redirect";
status_error[400]="Bad Request";
status_error[401]="Unauthorized";
status_error[402]="Payment Required ";
status_error[403]="Forbidden";
status_error[404]="Not Found";
status_error[405]="Method Not Allowed";
status_error[406]="Not Acceptable";
status_error[407]="Proxy Authentication Required";
status_error[408]="Request Timeout";
status_error[409]="Conflict";
status_error[410]="Gone";
status_error[411]="Length Required";
status_error[412]="Precondition Failed";
status_error[413]="Payload Too Large";
status_error[414]="URI Too Long";
status_error[415]="Unsupported Media Type";
status_error[416]="Range Not Satisfiable";
status_error[417]="Expectation Failed";
status_error[418]="I'm a teapot";
status_error[421]="Misdirected Request";
status_error[422]="Unprocessable Entity";
status_error[423]="Locked";
status_error[424]="Failed Dependency";
status_error[425]="Too Early";
status_error[426]="Upgrade Required";
status_error[428]="Precondition Required";
status_error[429]="Too Many Requests";
status_error[431]="Request Header Fields Too Large";
status_error[451]="Unavailable For Legal Reasons";
status_error[500]="Internal Server Error";
status_error[501]="Not Implemented";
status_error[502]="Bad Gateway";
status_error[503]="Service Unavailable";
status_error[504]="Gateway Timeout";
status_error[505]="HTTP Version Not Supported";
status_error[506]="Variant Also Negotiates";
status_error[507]="Insufficient Storage";
status_error[508]="Loop Detected";
status_error[510]="Not Extended";
status_error[511]="Network Authentication Required";




HttpStatus::HttpStatus():
_code(0),
_message()
{
}

HttpStatus::HttpStatus(int code, std::string message):
_code(code),
_message(message)
{

}

HttpStatus::HttpStatus(HttpStatus const & copy)
{
	*this = copy;
}

HttpStatus::~HttpStatus()
{
}

HttpStatus& HttpStatus::operator=(const HttpStatus & ope)
{
    if(this != ope)
	{
		_message = ope._message;
		_code = ope._code;
	}
	return(*this)
}

std::string HttpStatus::find_message(int code)
{
	std::string message = status_error.find(code)->second;
	return(message);
}

int HttpStatus::get_code()
{
	return(_code);
}

std::string HttpStatus::get_message()
{
	return(_message);
}
