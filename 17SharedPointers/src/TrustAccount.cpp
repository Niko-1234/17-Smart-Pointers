#include <iostream>
#include "TrustAccount.h"

TrustAccount::TrustAccount(std::string TrstAccName, double TrstAccSaldo, double TrstIntRate)
    :SavingAccount{TrstAccName, TrstAccSaldo, TrstIntRate}, WithdrawCounter{0}{}

bool TrustAccount::Deposit(double Amount){
    if (Amount >= Threshold)
        Amount += DepositBonus;
    return SavingAccount::Deposit(Amount);
}

bool TrustAccount::Withdraw(double Amount){
    if (WithdrawCounter < MaxWithdrawsNumber && Amount <= MaxWithdrawPercent*Saldo){
        WithdrawCounter++;
        return SavingAccount::Withdraw(Amount);
    } else {
        // std::cout << "Withdraw impossible" << std::endl;
        return false;
    }
}

void TrustAccount::Print(std::ostream &os) const{
    os << "[Trust Account: " << Name << " Saldo: " << Saldo << " Int.Rate: " << IntRate << " Withdraws: " << WithdrawCounter << "]";
}