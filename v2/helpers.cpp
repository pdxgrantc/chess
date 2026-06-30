#ifndef HELPERS_CPP
#define HELPERS_CPP

#include <iostream>
#include <string>
#include <regex>

#include "helpers.h"

using namespace std;

string toLowercase(string input)
{
    string output;

    for (unsigned char c : input)
    {
        if (isalnum(c))
        {
            output += tolower(c);
        }
    }

    return output;
}

Move takeInput(int player_to_move)
{
    std::string userInput;
    std::regex pattern("^[A-Ha-h][1-8][A-Ha-h][1-8]$");

    while (true)
    {
        cout << endl;
        cout << "Player " << player_to_move + 1 << "'s turn." << endl;
        cout << "Enter your move (eg c2c3 to move c2 to c3): ";
        cin >> userInput;

        if (!std::regex_match(userInput, pattern))
        {
            cout << "Invalid Move" << endl;
            continue;
        }

        break;
    }

    userInput = toLowercase(userInput);

    Move returnVal;
    returnVal.oi = 0;
    returnVal.oj = 0;
    returnVal.ni = 0;
    returnVal.nj = 0;

    return returnVal;
}

#endif
