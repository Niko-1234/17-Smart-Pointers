#include "I_Account.h"
#include "Account.h"
#include <iostream>
#include <vector>


void Display(const std::vector <Account *> &Accounts);
void Deposit(std::vector <Account *> &Accounts, double Amount);
void Withdraw(std::vector <Account *> &Accounts, double Amount);