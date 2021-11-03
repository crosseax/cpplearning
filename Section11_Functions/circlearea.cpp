#include <iostream>

using namespace std;

const double PI {3.14159};

void area_circle (void);
double calc_area_circle (double radius);


int main (void) 
{
    area_circle();


    return 0;
}


double calc_area_circle (double radius)
{
    return PI * radius * radius; 
}

void area_circle (void)
{
    double radius {};
    cout << "Please enter the radius of the circle: ";
    cin >> radius;

    cout << "The area of the circle with radius of " << radius << " is " << calc_area_circle(radius) << endl;
}