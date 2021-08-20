#ifndef _TRUSTACCOUNT_H_
#define _TRUSTACCOUNT_H_
#include "SavingAccount.h"

class  TrustAccount: public SavingAccount{
private:
    static constexpr const char *DefName = "TrustNone";
    static constexpr double DefSaldo = 0.0;
    static constexpr double DefIntRate = 0.0;
    static constexpr double Threshold = 5000.0;
    static constexpr int MaxWithdrawsNumber = 3;
    static constexpr double MaxWithdrawPercent = 0.2;
    static constexpr double DepositBonus = 50.0;
protected:
    int WithdrawCounter;
public:
    TrustAccount(std::string TrstAccName = DefName, double TrstAccSaldo = DefSaldo, double TrstIntRate = DefIntRate);
    virtual bool Deposit(double Amount) override;
    virtual bool Withdraw(double Amount) override;
    virtual void Print(std::ostream &os) const override;
    virtual ~TrustAccount() = default;
};

#endif // _TRUSTACCOUNT_H_