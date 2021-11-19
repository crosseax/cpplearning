#ifndef _INSUFFICIENT_FUNDS_EXCEPTION_H_
#define _INSUFFICIENT_FUNDS_EXCEPTION_H_

class InsufficientFundsException: public std::exception {
public:
    InsufficientFundsException() {};
    ~InsufficientFundsException() {};
    virtual const char* what() const noexcept { 
        return "Insufficient Funds Exception";
    }
};



#endif 