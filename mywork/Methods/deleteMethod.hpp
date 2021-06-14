#ifndef DELETEMETHOD_HPP
# define DELETEMETHOD_HPP
#include "../request.hpp"
#include "../response.hpp"
#include "../Client.hpp"
#include <iostream>

class DeleteMethod
{
private:
    /* data */
public:
    DeleteMethod(/* args */);
    // DeleteMethod (DeleteMethod const & copy);
    ~DeleteMethod();
    // DeleteMethod& operator=(DeleteMethod const & ope);

	void handleDelete(Client client, Request request, Response reponse);
};

#endif