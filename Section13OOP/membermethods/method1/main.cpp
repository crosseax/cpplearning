// method 1
// do everything all in one file

#include <iostream>
#include <string>

using namespace std;

class Account {
private:
    // attributes
    string name;
    double balance;

public:
    // methods
    // declared inline
    void set_balance(double bal) {balance = bal;}
    double get_balance() {return balance;}

    // methods will be declared outside the class declaration
    void set_name(string n);
    string get_name();

    bool deposit(double ammount);
    bool withdraw(double ammount);
};


int main (void)
{
    Account frankAcc;
    frankAcc.set_name("Frank's account");
    frankAcc.set_balance(1000.00);

    if (frankAcc.deposit(200.00)){
        cout << "Deposit OK" << endl;
    } else {
        cout << "Deposit NOT allowed" << endl;
    }

    if (frankAcc.withdraw(500.00)){
        cout << "Withdrawal OK" << endl;
    } else {
        cout << "NOT sufficient funds" << endl;
    }

    if (frankAcc.withdraw(1500.00)){
        cout << "Withdrawal OK" << endl;
    } else {
        cout << "NOT sufficient funds" << endl;
    }

    return 0;
}


void Account::set_name(string n){ // :: is scope resolution operator
    name = n;
}

string Account::get_name(){
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
