#include "lexicalanalizer.h"
#include <string.h>

using namespace std;

enum struct Status{
    start,
    itIsInteger,
    havePoint,
    itIsReal,
    exponent,
    sign,
    realWithExponent,
    fail
};

bool isDigit(char ch);
bool isExponent(char ch);
bool isSign(char ch);
bool isPoint(char ch);

bool stateMachine(char* str)
{
    Status state = Status::start;
    int i = 0;
    while (i < strlen(str))
    {
        switch (state) {
        case Status::start:
            if (isDigit(str[i]) && str[i] != '0') {
                state = Status::itIsInteger;
            } else {
                state = Status::fail;
            }
            break;
        case Status::itIsInteger:
            if (isDigit(str[i])) {
                state = Status::itIsInteger;
            } else if (isPoint(str[i])) {
                state = Status::havePoint;
            } else if (isExponent(str[i])) {
                state = Status::exponent;
            } else {
                state = Status::fail;
            }
            break;
        case Status::havePoint:
            if (isDigit(str[i])) {
                state = Status::itIsReal;
            } else {
                state = Status::fail;
            }
            break;
        case Status::itIsReal:
            if (isDigit(str[i])) {
                state = Status::itIsInteger;
            } else if (isExponent(str[i])) {
                state = Status::exponent;
            } else {
                state = Status::fail;
            }
            break;
        case Status::exponent:
            if (isDigit(str[i])) {
                state = Status::realWithExponent;
            } else if (isSign(str[i])) {
                state = Status::sign;
            } else {
                state = Status::fail;
            }
            break;
        case Status::sign:
            if (isDigit(str[i])) {
                state = Status::realWithExponent;
            } else {
                state = Status::fail;
            }
            break;
        case Status::realWithExponent:
            if (isDigit(str[i])) {
                continue;
            } else {
                state = Status::fail;
            }
            break;
        default:
            break;
        }
        if (state == Status::fail) {
            break;
        }
        i++;
    }
    switch (state) {
    case Status::itIsInteger:
    case Status::itIsReal:
    case Status::realWithExponent:
        return true;
    default:
        return false;
    }
}


bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

bool isExponent(char ch)
{
    return (ch == 'E' || ch == 'e');
}

bool isSign(char ch)
{
    return (ch == '+' || ch == '-');
}

bool isPoint(char ch)
{
    return (ch == '.');
}
