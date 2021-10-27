#include <iostream>
#include <vector>
#include <string>

using namespace std;

double calc_cost (double baseCost, double taxRate = 0.06, double shipCost = 3.50);

void greeting(string name, string prefix = "Mr.", string suffix ="");

int main (void)
{
    double cost1, cost2, cost3 {0};
    cost1 = calc_cost (100, 0.08, 4.25);
    cout << cost1 << endl;

    cost2 = calc_cost (100, 0.08);
    cout << cost2 << endl;

    cost3 = calc_cost (100);
    cout << cost3 << endl;

    greeting ("Jones", "Dr.", "M.D.");
    greeting ("Smith");
    greeting ("Howard", "Mrs.");

    return 0;
};

double calc_cost (double baseCost, double taxRate, double shipCost){
    return baseCost += (baseCost * taxRate) + shipCost;
};

void greeting (string name, string prefix, string suffix){
    cout << "Hello " << prefix + " " + name + " " + suffix << endl;
}
