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

void func(shared_ptr<Test> p){
    cout << "Use count: " << p.use_count() << endl;
}

int main() {

    // shared_ptr<int> s1 {new int{100}};
    // cout << "Use count of: " << s1 << " = " << s1.use_count() << endl;

    // shared_ptr<int> s2 {s1};
    // cout << "Use count of: " << s1 << " = " << s1.use_count() << endl;

    // shared_ptr<int> s3;
    // s3 = s1;
    // cout << "Use count of: " << s1 << " = " << s1.use_count() << endl;

    // s1.reset();

    // cout << "Use count of: " << s1 << " = " << s1.use_count() << endl;
    // cout << "Use count of: " << s2 << " = " << s2.use_count() << endl;

    //===================================================

    // shared_ptr<Test> ptr {make_shared<Test>(100)};
    // func(ptr);
    // cout << "Use count: " << ptr.use_count() << endl;
    // {
    //     shared_ptr<Test> ptr1 {ptr};
    //     cout << "Use count: " << ptr.use_count() << endl;
    //     {
    //         shared_ptr<Test> ptr2 {ptr};
    //         cout << "Use count: " << ptr.use_count() << endl;
    //         ptr.reset();
    //     }
    //     cout << "Use count: " << ptr.use_count() << endl;
    // }
    // cout << "Use count: " << ptr.use_count() << endl;

    //===================================================

    shared_ptr<Account> acc1 {make_shared<CheckingAccount>("Miko",1000)};
    shared_ptr<Account> acc2 {make_shared<SavingAccount>("Karo",2000,10)};
    shared_ptr<Account> acc3 {make_shared<TrustAccount>("Kamil",3000,20)};

    vector<shared_ptr<Account>> Accounts;

    Accounts.push_back(acc1);
    Accounts.push_back(acc2);
    Accounts.push_back(acc3);

    for (auto acc: Accounts){
        cout << *acc << endl;
        cout << "use count: " << acc.use_count() << endl;
    }
}

