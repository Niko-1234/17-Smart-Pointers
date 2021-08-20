#ifndef _SAVINGACCOUNT_H_
#define _SAVINGACCOUNT_H_
#include "Account.h"

class SavingAccount: public Account{
private:
    static constexpr const char *DefSavAccName = "SavNone";
    static constexpr double DefSavAccSaldo = 0.0;
    static constexpr double DefIntRate = 0.0;
protected:
    double IntRate;
public:
    SavingAccount (std::string SavAccName = DefSavAccName, double SavAccSaldo = DefSavAccSaldo, double IntRate = DefIntRate);
    virtual bool Deposit (double Amount) override;
    virtual bool Withdraw (double Amount) override;
    virtual void Print(std::ostream &os) const override;
    virtual ~SavingAccount() = default;
};

#endif // _SAVINGACCOUNT_H_