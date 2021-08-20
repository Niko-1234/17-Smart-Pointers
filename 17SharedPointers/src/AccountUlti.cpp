#include "AccountUlti.h"


void Display(const std::vector <Account *> &Accounts){
    std::cout << "=====Accounts===========================" << std::endl;
    for (const auto a: Accounts){
        std::cout << *a << std::endl;
    }
}

void Deposit(std::vector <Account *> &Accounts, double Amount){
    std::cout << "=====Depositing===========================" << std::endl;
    for (auto a: Accounts){
        if(a->Deposit(Amount)){
            std::cout << "Deposited " << Amount << " to " << *a << std::endl;
        } else
        {
            std::cout << "Filed Deposit " << Amount << " to " << *a << std::endl;
        }
    }
}

void Withdraw(std::vector <Account *> &Accounts, double Amount){
    std::cout << "=====Withdrawing===========================" << std::endl;
    for (auto a: Accounts){
        if(a->Withdraw(Amount)){
            std::cout << "Withdrew " << Amount << " from " << *a << std::endl;
        } else
        {
            std::cout << "Filed Withdraw " << Amount << " from " << *a << std::endl;
        }
    }
}