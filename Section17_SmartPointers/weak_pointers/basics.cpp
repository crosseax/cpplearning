// Smart pointers, weak pointers
// smart pointers #include <memory>

// weak pointers
// weak_ptr<T>, points to type T object on the heap
// does NOT participate in owning relationship
// so does NOT affect the lifetime of what it points to
// always created from a shared_ptr
// does NOT increment or decrement reference use count
// used to prevent strong reference cycles (A contains shared_ptr<B> and B contains shared_ptr<A>)
// which could prevent objects from being deleted
// which could lead to memory leak
// because the shared_ptr on the heap in the obj wont have 0 use_count and prevents itself from being deleted

#include <iostream>
#include <memory>

class B; // forward declaration

class A {
    std::shared_ptr<B> bPtr;
public:
    void set_B(std::shared_ptr<B>& b) {
        bPtr = b;
    }
    A() {std::cout << "A Constructor" << std::endl;}
    ~A() {std::cout << "A Destructor" << std::endl;}
};

class B {
    std::weak_ptr<A> aPtr; // if std::shared_ptr<A>, then strong circular reference
    // make weak to break the strong circular reference
    // now, A has stronger ownership to B than B to A
public:
    void set_A(std::shared_ptr<A>& a) {
        aPtr = a;
    }
    B() {std::cout << "B Constructor" << std::endl;}
    ~B() {std::cout << "B Destructor" << std::endl;}
};

int main (void)
{
    std::shared_ptr<A> a = std::make_shared<A> ();
    std::shared_ptr<B> b = std::make_shared<B> ();
    
    a->set_B(b);
    b->set_A(a);

    return 0;
}