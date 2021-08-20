#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_
#include <string>
#include "I_Account.h"


class Account: public I_Account
{
private:
    static constexpr const char *DefName = "None";
    static constexpr double DefSaldo = 0.0;
protected:
    std::string Name;
    double Saldo;
public:
    Account(std::string AccName = DefName, double AccSaldo = DefSaldo);
    virtual bool Deposit(double Amount) = 0;
    virtual bool Withdraw(double Amount) = 0;
    virtual void Print(std::ostream &os) const override;
    double GetBalance() const;
    virtual ~Account() = default;
};

#endif // _ACCOUNT_H_