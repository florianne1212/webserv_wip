#include "IMiddleware.hpp"

class MethodMiddleware : public IMiddleware {

	public:
		virtual ~MethodMiddleware();

		virtual void handle(Client &client, Request &request, Response &response, MiddlewareChain &next);

};
