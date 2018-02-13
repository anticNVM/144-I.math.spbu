#include "stateMachine.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
    vector<string> tests = {
        "st@student.spbu.r",
        "ST@STUDENT.SPBU.R",
        "ASD..",
        "QWERTY@",
        "QWERTY@TEST.3.ST.E"
    };

    cout << "Checking for email: \n\n";
    for (auto str : tests) {
        cout << stateMachine(str.c_str()) << "  " << str << endl;
    }

    return 0;
}

