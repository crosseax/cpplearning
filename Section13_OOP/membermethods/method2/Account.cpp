#include "Account.h"
// since Account.h #include <string>, no need to do it here agains

void Account::set_name(std::string n){ // the first :: is scope resolution operator
    name = n;
}

std::string Account::get_name(){
    return name;
}

bool Account::deposit(double ammount){
    if (ammount >= 0){
        balance += ammount;
        return true;
    } else {
        return false;
    }
}

bool Account::withdraw(double ammount){
    if (balance - ammount >= 0){
        balance -= ammount;
        return true;
    } else {
        return false;
    }
}
