#ifndef GETMETHOD_HPP
# define GETMETHOD_HPP
#include "../request.hpp"
#include "../response.hpp"


class GetMethod
{
private:
    /* data */
public:
    GetMethod(/* args */);
    GetMethod(GetMethod const & copy);
    ~GetMethod();
    GetMethod& operator=(GetMethod const & ope);

    handleGet(Client client, Request reauest, Response reponse);
};

#endif

