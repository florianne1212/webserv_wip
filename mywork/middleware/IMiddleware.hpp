#ifndef IMIDDLEWARE_HPP
# define IMIDDLEWARE_HPP

class Client;
class Request;
class Response;
class MiddlewareChain;

class IMiddleware {

	public:
		virtual ~IMiddleware();

		virtual void handle(Client &client, Request &request, Response &response, MiddlewareChain &next) = 0;

};

#endif