#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    string brackets = "";
    cout << "Please, enter the sequence of brackets: " << endl;
    getline(cin, brackets);

    int k = 0;
    bool is_balanced = true;

    for (unsigned i = 0; i < brackets.length(); ++i) {
        if (brackets[i] == '(') {
            k++;
        }
        else if (brackets[i] == ')') {
            k--;
        }
        else {
            continue;
        }
        if (k < 0) {
            is_balanced = false;
            break;
        }
    }

    if (k != 0 || !is_balanced) {
        cout << "NOT: The sequence of brackets is unbalanced :( \n";
    }
    else {
        cout << "OK: The sequence of brackets is balanced! \n";
    }
    cout << endl;

    return 0;
}

