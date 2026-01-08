#include <stdexcept>
#include <iostream>
#include "bankingException.h"

using namespace std;
class InsufficientFundsException : public BankingException
{
public:
   InsufficientFundsException(): BankingException("Insufficient balance for withdrawal");
// TODO: Write execetion function
};