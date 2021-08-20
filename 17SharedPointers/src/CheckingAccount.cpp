#include <iostream>
#include "CheckingAccount.h"

CheckingAccount::CheckingAccount(std::string ChckAccName, double ChckAccSaldo) 
    :Account{ChckAccName, ChckAccSaldo} {}

bool CheckingAccount::Deposit(double Amount){
    return Account::Deposit(Amount);
}

bool CheckingAccount::Withdraw(double Amount){
    Amount += Amount + WithdrawFee;
    return Account::Withdraw(Amount);
}

void CheckingAccount::Print(std::ostream &os) const{
    os << "[Checking Account: " << Name << " Saldo: " << Saldo << "]";
}