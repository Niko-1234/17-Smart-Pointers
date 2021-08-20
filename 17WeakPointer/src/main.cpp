#include <iostream>
#include <memory>

class B;

class A{
    std::shared_ptr<B> Bptr;
public:
    void setB(std::shared_ptr<B> &b){
        Bptr = b;
    };
    A(){std::cout << "A Constructor" << std::endl;}
    ~A(){std::cout << "A Destructor" << std::endl;}
};

class B{
    std::weak_ptr<A> Aptr;
public:
    void setA(std::shared_ptr<A> &a){
        Aptr = a;
    };
    B(){std::cout << "B Constructor" << std::endl;}
    ~B(){std::cout << "B Destructor" << std::endl;}
};

int main() {
    std::shared_ptr<A> a = std::make_shared<A>();
    std::shared_ptr<B> b = std::make_shared<B>();
    a->setB(b);
    b->setA(a);
}