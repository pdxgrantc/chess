#ifndef HELPERS_CPP
#define HELPERS_CPP

#include <iostream>
#include <string>
#include <regex>

#include "helpers.h"

using namespace std;

#include <string>
#include <cctype>

string convertMoveToNumbers(string input)
{
    string output;

    for (char c : input)
    {
        c = tolower(c);

        if (c >= 'a' && c <= 'h')
        {
            output += char('1' + (c - 'a'));
        }
        else if (c >= '1' && c <= '8')
        {
            output += c;
        }
    }

    return output;
}

Move takeInput(int player_to_move)
{
    string userInput;
    regex pattern("^[A-Ha-h][1-8][A-Ha-h][1-8]$");

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

    userInput = convertMoveToNumbers(userInput);
    
    Move returnVal;
    returnVal.oi = userInput[0] - 1;
    returnVal.oj = userInput[1] - 1;
    returnVal.ni = userInput[2] - 1;
    returnVal.nj = userInput[3] - 1;

    return returnVal;
}

#endif
