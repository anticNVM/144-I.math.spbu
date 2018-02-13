#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    cout << "Please, enter something: " << endl;
    string array = "";
    getline(cin, array);

    int k = 0;
    for (unsigned i = 0; i < array.length(); ++i) {
        if (array[i] == '0')
            k++;
    }
    cout << "Amount of '0' in this char_array = " << k << endl;

    return 0;
}
