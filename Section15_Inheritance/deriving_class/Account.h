#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

class Account {
public:
    Account ();
    ~Account ();

    void deposit (double amount);
    void withdraw (double amount);
};

#endif // _ACCOUNT_H_