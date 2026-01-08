#include <stdexcept>
#include <iostream>
#include "bankingException.h"

using namespace std;
class AuthenticationFailedException : public BankingException
{
    public:
    AuthenticationFailedException() : BankingException("Authentication failed. Invalid credentials.");
    //Todo: Write the exception function
};