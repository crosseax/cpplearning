#include <iostream>
#include <string>
#include <vector>

using namespace std;

void display_menu();
char get_selection();

void handle_display(const vector<int> &v);
void handle_add (vector<int> &v);
void handle_total (vector<int> &v);
void handle_mean (const vector<int> &v);
void handle_smallest (const vector<int> &v);
void handle_largest (const vector<int> &v);
void handle_find (const vector<int> &v);
void handle_quit();
void handle_unknown();

void display_list(const vector<int> &v);
int calculate_total(const vector<int> &v);
double calculate_mean(const vector<int> &v);
int get_smallest(const vector<int> &v);
int get_largest(const vector<int> &v);
bool find(const vector<int> &v, int target);



int main (void)
{
    vector<int> numbers;
    char selection{};

    do {
        cout << endl;
        display_menu();
        selection = get_selection();
        switch (selection){ 
            case 'P':
                handle_display(numbers);
                break;
            case 'A':
                handle_add(numbers);
                break;
            case 'T':
                handle_total(numbers);
                break;
            case 'M':
                handle_mean(numbers);
                break;
            case 'S':
                handle_smallest(numbers);
                break;
            case 'L':
                handle_largest(numbers);
                break;
            case 'F':
                handle_find(numbers);
                break;
            case 'Q':
                handle_quit();
                break;
            default:
                handle_unknown();
                break;
        } 
    } while (selection != 'Q');
    
    cout << endl;

    return 0;
}



void display_menu(){
    cout << "\nP - Print numbers" << endl;
    cout << "A - Add a number" << endl;
    cout << "T - Display total of the numbers" << endl;
    cout << "M - Display mean of the numbers" << endl;
    cout << "S - Display the smallest number" << endl;
    cout << "L - Display the largest number" << endl;
    cout << "F - Find a number" << endl;
    cout << "Q - Quit" << endl;
    cout << "\nEnter your choice: ";
}

char get_selection(){
    char selection{};
    cin >> selection;
    return toupper(selection);
}

void handle_display(const vector<int> &v){
    if (v.size() == 0){
        cout << "[] - the list is empty" << endl;
    } else {
        display_list(v);
    }
}

void handle_add (vector<int> &v){
    int num_to_add {};
    cout << "Enter an integer to add to the list: ";
    cin >> num_to_add;
    v.push_back(num_to_add);
    cout << num_to_add << " added" << endl; 
}

void handle_total (vector<int> &v){
    if (v.size() == 0){
        cout << "Unable to calculate total - list is empty" << endl;
    } else {
        cout << "The total is " << calculate_total(v) << endl;
    } 
}

void handle_mean (const vector<int> &v){
    if (v.size() == 0){
        cout << "Unable to calculate mean - list is empty" << endl;
    } else {
        cout << "The mean is " << calculate_mean(v) << endl;
    }
}

void handle_smallest (const vector<int> &v){
    if (v.size() == 0){
        cout << "There's no number, hence no smallest" << endl;
    } else {
        cout << "The smallest number is " << get_smallest(v) << endl;
    }

}

void handle_largest (const vector<int> &v){
    if (v.size() == 0){
        cout << "There's no number, hence no largest" << endl;
    } else {
        cout << "The largest number is " << get_largest(v) << endl;
    }
}

void handle_find (const vector<int> &v){
    int target{};
    cout << "Enter the number to find: ";
    cin >> target;
    if (find(v, target)){
        cout << target << " was found" << endl;
    } else {
        cout << target << " was NOT found" << endl;
    }
}

void handle_quit(){
    cout << "Goodbye" << endl;
}

void handle_unknown(){
    cout << "Unknown selection - try again" << endl;
}



void display_list(const vector<int> &v){
    cout << "[ ";
    for (auto num : v){
        cout << num << " ";
    }
    cout << "]" << endl;
}

int calculate_total(const vector<int> &v){
    int total{};
    for (auto num : v){
        total += num;
    }
    return total;
}

double calculate_mean(const vector<int> &v){
    int total{};
    for (auto num : v){
        total += num;
    }
    return static_cast<double>(total)/v.size();
}

int get_smallest(const vector<int> &v){
    int min {v[0]};
    for (size_t i=0; i < v.size(); i++){
        if (min > v[i]){
            min = v[i]; 
        }
    }
    return min;
}

int get_largest(const vector<int> &v){
    int max {v[0]};
    for (size_t i=0; i < v.size(); i++){
        if (max < v[i]){
            max = v[i]; 
        }
    }
    return max;
}

bool find(const vector<int> &v, int target){
    for (auto num : v){
        if (num == target){
            return true;
        }
    }
    return false;
}

