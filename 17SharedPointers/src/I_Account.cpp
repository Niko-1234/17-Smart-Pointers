#include "I_Account.h"

std::ostream &operator<<(std::ostream &os, const I_Account &AccType){
    AccType.Print(os);
    return os;
};