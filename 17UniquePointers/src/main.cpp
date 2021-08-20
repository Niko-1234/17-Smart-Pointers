#include <iostream>
#include <memory>
#include <vector>
#include "SavingAccount.h"
#include "CheckingAccount.h"
#include "TrustAccount.h"
#include "I_Account.h"
#include "AccountUlti.h"

using namespace std;

class Test{
private:
    int data;
public:
    Test():data{0} {cout << "Test constructor [" << data << "]" << endl;};
    Test(int number):data{number}{cout << "Test constructor [" << data << "]" << endl;}
    int GetData(){return data;};
    ~Test(){cout << "Test destructor [" << data << "]" << endl;};
};

int main() {
    // Test *t1 = new Test {1000}; //get memory
    // delete t1; //clear memory
    // unique_ptr<Test> t1 {new Test {5000}}; //autmaticly clear memory
    // unique_ptr<Test> t2 = make_unique<Test>(1000);
    // unique_ptr<Test> t3 {make_unique<Test>(3000)};

    // unique_ptr<Test> t4;
    //t4 = t3; //imposible uniqe ointer cant be copied
    // t4 = move(t3);
    // if (!t3)
    //     cout << "t3 is nullptr" << endl;

    unique_ptr<Account> acc1 {make_unique<CheckingAccount>("Moe",5000)};
    cout << *acc1 << endl;

    vector<unique_ptr<Account>> Accounts;

    Accounts.push_back(make_unique<CheckingAccount>("Miko",1000));
    Accounts.push_back(make_unique<TrustAccount>("Kamil",3000,10));
    Accounts.push_back(make_unique<SavingAccount>("Karo",2000,10));

    for (const auto &acc:Accounts)
        cout << *acc << endl;
}

