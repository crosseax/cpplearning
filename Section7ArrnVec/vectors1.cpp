#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // vector <int> scores {100, 95, 81, 92, 77};
    // cout << "The third score is " << scores.at(2) << endl;
    // scores.push_back(79); // like append(79) in python

    // vector <int> nums {1,2,3};
    // cout << nums.at(5) << endl; // now this will give error during compilation

    vector <char> vowels {'a','e','i','o','u'};

    cout << vowels[0] << endl;
    cout << vowels[4] << endl;

    vector <int> scores {100, 98, 88};

    cout << "second score: " << scores.at(1) << endl;
    cout << "now change the second score to: ";
    cin >> scores.at(1);
    cout << "second score now: " << scores.at(1) << endl;

    cout << "There are " << scores.size() << " scores in the vector" << endl;
    scores.push_back(75);
    cout << "There are now " << scores.size() << " scores in the vector" << endl;

    cout << "Now add another score to the vector: ";
    int addedScore {0};
    cin >> addedScore;
    scores.push_back(addedScore);
    cout << "You added " << addedScore << endl;
    cout << "There are now " << scores.size() << " scores in the vector" << endl;


    // multi dimensional vector

    vector <vector<int>> ratings
    {
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12}
    };

    // ratings.at(row).at(col)
    cout << ratings.at(0).at(0) << endl;
    cout << ratings.at(1).at(0) << endl;
    cout << ratings.at(0).at(2) << endl;


    return 0;
}