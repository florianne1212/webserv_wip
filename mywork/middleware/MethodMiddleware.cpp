#include <iostream>
#include "MethodMiddleware.hpp"
#include "../request.hpp"
#include "MiddlewareChain.hpp"

MethodMiddleware::~MethodMiddleware() {
}

void MethodMiddleware::handle(Client &client, Request &request, Response &response, MiddlewareChain &next) {
	std::string file = request.getUrl();

	if (exists(file)) {
		if (isFile(file)) {
			response.body(open(file));
		} else if (isDir(file)) {
			response.body(listFiles(file))
		}
	}

	

	std::cout << request.getUrl() << std::endl;

	next();
}