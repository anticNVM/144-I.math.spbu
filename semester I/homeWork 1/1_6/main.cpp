#include <iostream>
#include <string>

using namespace std;

int amountOfSubs(string subStr, string str);

int main()
{
    string str = "";
    cout << "Please, enter a string: \n";
    getline(cin, str);
    string subStr = "";
    cout << "Please, enter a substring: \n";
    getline(cin, subStr);

    if (subStr.length() > str.length()) {
        cout << "There are 0 substrings in string cause substring is longer than string :(\n";
    } else {
        cout << "Amount of subs(S1, S) = " << amountOfSubs(subStr, str) << endl;
    }

    return 0;
}

int amountOfSubs(string subStr, string str)
{
    int amountOfSubs = 0;
    for (unsigned i = 0; i <= (str.length() - subStr.length()); ++i) {
        if (str[i] == subStr[0]) {
            bool isItSub = true;
            for (unsigned j = 1; j < subStr.length(); ++j) {
                if (str[j + i] != subStr[j]) {
                    isItSub = false;
                    break;
                }
            }
            if (isItSub) {
                amountOfSubs++;
            }
        }
    }
    return amountOfSubs;
}
