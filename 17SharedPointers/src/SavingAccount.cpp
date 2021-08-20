#include <iostream>
#include "SavingAccount.h"

SavingAccount::SavingAccount(std::string SavAccName, double SavAccSaldo, double IntRate)
    :Account{SavAccName, SavAccSaldo}, IntRate{IntRate} {}

bool SavingAccount::Deposit(double Amount){
    Amount += Amount*(IntRate/100);
    return Account::Deposit(Amount);
}

bool SavingAccount::Withdraw(double Amount){
    return Account::Withdraw(Amount);
}

void SavingAccount::Print(std::ostream &os) const{
    os << "[Saving Account: " << Name << " Saldo: " << Saldo << " Int.Rate: " << IntRate << "]";
}