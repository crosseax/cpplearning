// Abstract classes:
// are usually used as base class
// can be thought as a generic class that is the parent to all other classes
// are to generic to directly create objects from
// must contain at least ONE Pure Virutal Function

// the other ones, so far what we use, is called concrete class

// Pure virtual function: "=0" specifier
// exp: virtual void function() = 0;
// When derived from a abstract class, 
// all pure virtual function must be overriden in order to become concrete class
// otherwise it will also be an abstract class


#include <iostream>
#include <vector>

class Shape { // abstract class
private:
    // attributes common to all shapes
public:
    virtual void draw() = 0;    // pure virtual function
    virtual void rotate() = 0;  // pure virtual function
    virtual ~Shape() {std::cout << "Shape destructor" << std::endl; }
};


class Open_Shape: public Shape { // abstract class, cuz not all pure virtual function are overridden
public:
    virtual ~Open_Shape() {std::cout << "Open_shape destructor , "; }
};

class Closed_Shape: public Shape { // abstract class, cuz not all pure virtual function are overridden
public:
    virtual ~Closed_Shape() {std::cout << "Closed_shape destructor , "; }
};


class Line: public Open_Shape { // concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a line" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a line" << std::endl;
    }
    virtual ~Line() {std::cout << "Line destructor, "; }
};

class Circle: public Closed_Shape { // concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a circle" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a circle" << std::endl;
    }
    virtual ~Circle() {std::cout << "Circle destructor , "; }
};

class Square: public Closed_Shape { // concrete class
public:
    virtual void draw() override {
        std::cout << "Drawing a square" << std::endl;
    }
    virtual void rotate() override {
        std::cout << "Rotating a square" << std::endl;
    }
    virtual ~Square() {std::cout << "Square destructor , "; }
};


void screen_referesh_ref(const std::vector<Shape*>& shapes) {
    std::cout << "Refreshing " << std::endl;
    for (const auto shape : shapes) {
        shape->draw();
        shape->rotate();
    }
} 

void screen_referesh_ptr(const std::vector<Shape*>* shapes) {
    std::cout << "Refreshing " << std::endl;
    for (const auto shape : *shapes) {
        shape->draw();
        shape->rotate();
    }
} 


int main (void)
{
    // You CANNOT Instantiate a abstract class, on stack or heap
    // Shape s; // Error
    // Shape* sp = new Shape; // Error
    {
        Circle c;
        c.draw();
    }

    {
        Shape* c_ptr = new Circle;
        c_ptr->draw();
        c_ptr->rotate();
        delete c_ptr;
    }

    Shape* s1 = new Circle;
    Shape* s2 = new Line;
    Shape* s3 = new Square;

    std::cout << "\n===Loop through vector===" << std::endl;
    std::vector<Shape*> shapes_ptr {s1, s2, s3};
    for (const auto shape : shapes_ptr) {
        shape->draw();
    }

    std::cout << "\n===Loop through ref vector using function===" << std::endl;
    screen_referesh_ref(shapes_ptr);

    std::cout << "\n===Loop through ptr vector using function===" << std::endl;
    screen_referesh_ptr(&shapes_ptr);


    std::cout << "\n===Delete && Destructor===" << std::endl;
    delete s1;
    delete s2;
    delete s3;

    return 0;
}
