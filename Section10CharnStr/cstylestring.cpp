#include <iostream>
#include <cstring>
#include <cctype>

using namespace std;

int main(void) 
{
    char firstName[255] {};
    char lastName [255] {};
    char fullName [511] {};

    // cout << "Please enter your first name(max length 20 characters): ";
    // cin >> firstName;
    // cout << "Please enter your last name(max length 20 characters): ";
    // cin >> lastName;

    // cout << "Your first name has " << strlen(firstName) << " characters" << endl;
    // cout << "Your last name has " << strlen(lastName) << " characters" << endl;
    
    // strcpy(fullName, firstName);
    // strcat(fullName, " ");
    // strcat(fullName, lastName);

    // cout << "Your full name is " << fullName << endl;




    cout << "Enter Your name: "; // have space in there
    cin.getline(fullName, 50); // how many memories(characters) you need
    cout << "Your full name is: " << fullName;

    char temp[511] {};
    strcpy(temp, fullName);

    for (size_t i = 0; i < strlen(fullName); i++){
        if (isalpha(fullName[i])){
            fullName[i] = toupper(fullName[i]);
        }
    }

    cout << "Your full name in upper case is: " << fullName << endl;

    cout << "Comparing " << temp << " and " << fullName << endl;
    cout << "Result: " << strcmp(temp, fullName) << endl;
    
    cout << "Comparing " << fullName << " and " << temp << endl;
    cout << "Result: " << strcmp(fullName, temp) << endl;
    

    return 0;
}