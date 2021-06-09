#include <list>
#include "IMiddleware.hpp"

class MiddlewareChain {

	private:
		std::list<IMiddleware*> m_middlewares;
		Client *m_client;
		Request *m_request;
		Response *m_response;

	public:
		MiddlewareChain(const std::list<IMiddleware*> &middlewares, Client &client, Request &request, Response &response);
		~MiddlewareChain(void);

	public:
		void operator ()();

};
