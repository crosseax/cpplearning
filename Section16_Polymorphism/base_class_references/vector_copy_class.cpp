#include <iostream>
#include <vector>

class Base {
public:
    virtual void print(){ 
        std::cout << "print Base" << std::endl;
    }

    virtual ~Base() {
        std::cout << "Base destructor" << std::endl;
    }
};

class Derived: public Base {
public:
    virtual void print(){
        std::cout << "print Derived" << std::endl;
    }
    virtual ~Derived() {
        std::cout << "Derived destructor, ";
    }
};

void do_print(Base& obj) {
    obj.print();
}


int main (void)
{
    Base b;
    Derived d;

    b.print();

    std::cout << "\n===normal destructor when derived out of block===" << std::endl;
    {
        Derived tmpD;
    }

    std::cout << "\n===vector 1 destructor when out of box===" << std::endl;
    {
        // such behavior is because when pass obj into vector
        // without using *ptr or &ref
        // its doing copy by default
        // so the compiler only alloc enough memory for Base each time
        // then the Derived get "Sliced"
        // hence the behavior below

        std::vector<Base> BaseVec;
        std::cout << "1\n" << std::endl;
        BaseVec.push_back(b);
        std::cout << "2\n" << std::endl;
        BaseVec.push_back(d);
        std::cout << "3\n" << std::endl;

        for (auto stuff : BaseVec) {
            std::cout << "\ntry" << std::endl;
            do_print(stuff);
            std::cout << "tryend" << std::endl;
        }
        std::cout << "4" << std::endl;
    }

    std::cout << "\n===vector 2 Ptr, so no destructor===" << std::endl;
    {
        std::vector<Base*> BaseVecPtr;
        BaseVecPtr.push_back(&b);
        BaseVecPtr.push_back(&d);

        for (auto stuff : BaseVecPtr) {
            do_print(*stuff);
        }
    }

    std::cout << "\n===destructor===" << std::endl;



    return 0;
}
