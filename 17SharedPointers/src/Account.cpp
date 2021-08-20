#include <iostream>
#include "Account.h"

//Constructor
Account::Account(std::string AccName, double AccSaldo)
    :Name{AccName}, Saldo{AccSaldo}{}

bool Account::Deposit(double Amount){
    if (Amount < 0){
        return false;
    } else {
        Saldo += Amount;
        return true;
    }
}

bool Account::Withdraw(double Amount){
    if (Saldo - Amount < 0 || Amount < 0){
        return false;
    }
    else{
        Saldo -= Amount;
        return true;
    }
}

double Account::GetBalance() const{
    return Saldo;
}

void Account::Print(std::ostream &os) const{
    os << "[Account: " << Name << " Saldo: " << Saldo << "]";
}

// std::ostream &operator<<(std::ostream &os, const Account &Account){
//     os << "[Account: " << Account.Name << ": " << Account.Saldo << "]";
//     return os;
// }

// Account operator+=(Account &Acc, double amount){
//     Acc.Deposit(amount);
//     return Acc;
// }

// Account operator-=(Account &Acc, double amount){
//     Acc.Withdraw(amount);
//     return Acc;
// }
