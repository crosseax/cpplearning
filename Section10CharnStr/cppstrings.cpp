#include <iostream> 
#include <vector>
#include <string>

using namespace std;

int main()
{
    string s1;
    string s2 {"CrosSea"};
    string s3 {s2};
    string s4 {"CrosSea", 3}; // Cro
    string s5 {s3,2,4}; // starting from char[2], count 4 chars
    string s6 (3, 'x'); // constructor style initialization

    cout << "s2: " << s2 << endl; 
    cout << "s3: " << s3 << endl; 
    cout << "s4: " << s4 << endl; 
    cout << "s5: " << s5 << endl; 
    cout << "s6: " << s6 << endl; 

    cout << s4.length() << endl; // this is oop already
    cout << "s2+s4: " << s2 + s4 << endl;
    s4[0] = 'B';
    cout << s4 << endl;
    s4.at(0) = 'T';
    cout << s4 << endl;

    // a proper way to loop through the string
    for (size_t i = 0; i < s2.length(); i++){
        cout << s2.at(i) << " ";
    }
    cout << endl;

    // range base for loop
    for (char c : s2){
        cout << c << " ";
    }
    cout << endl;

    for (int c : s2){
        cout << c << " ";
    }
    cout << endl;

    

    string testStr {"Just for a test"};
    cout << testStr.find("for") << endl; // return index of the begining of the searching result in the original str
    cout << testStr.find("bd") << endl; // a huge number, which is the same as string::npos
    cout << (testStr.find("bd") == string::npos) << endl; // 1, which means true
    cout << testStr.rfind("for") << endl; // reverse find, return the same 
    
    cout << testStr << endl;
    testStr.erase(0,5);
    cout << testStr << endl;



    // two examples below
    // exp. 1
    string unformatted_full_name {"StephenHawking"};

    string first_name {unformatted_full_name, 0, 7};
    string last_name = unformatted_full_name.substr(7, 7);

    string formatted_full_name = first_name + last_name;

    formatted_full_name.insert(7, " ");

    cout << formatted_full_name << endl;


    // exp. 2
    string journal_entry_1 {"Isaac Newton"};
    string journal_entry_2 {"Leibniz"};

    journal_entry_1.erase(0, 6);
    
    cout << journal_entry_1 << " and " << journal_entry_2 << endl;

    if (journal_entry_2 < journal_entry_1) 
        journal_entry_2.swap(journal_entry_1);

    cout << journal_entry_1 << " and " << journal_entry_2 << endl;

    string reversed {journal_entry_1.rbegin(), journal_entry_1.rend()};

    cout << reversed << endl;

    // string t1;
    // cout << "Input a string: "; 
    // getline(cin, t1); // to get string with spaces
    // cout << "You have entered: " << t1 << endl;


    return 0;
}