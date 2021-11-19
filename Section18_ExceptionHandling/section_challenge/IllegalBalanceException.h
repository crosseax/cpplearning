#ifndef _ILLEGAL_BALANCE_EXCEPTION_H_
#define _ILLEGAL_BALANCE_EXCEPTION_H_

class IllegalBalanceException: public std::exception {
public:
    IllegalBalanceException() {};
    ~IllegalBalanceException() {};
    virtual const char* what() const noexcept { 
        return "Illegel balance exception";
    }
};

#endif 