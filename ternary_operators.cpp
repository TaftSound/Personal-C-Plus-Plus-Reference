#include <iostream>
#include <string>
//?: <--ternary operator is similar to an if statement

static int s_Level = 1;
static int s_Speed = 2;


int main()
{
//standard if statement:
    if (s_Level > 5) 
        s_Speed = 10;
    else
        s_Speed = 5;

//this is equivalent to:

    s_Speed = s_Level > 5 ? 10 : 5;
//format is: (condition) ? (result if true) : (result if false);

//another use case:
    std::string rank = s_Level > 10 ? "Master" : "Beginner";

//ternary operators can be nested:
    s_Level = 11;
    s_Speed = s_Level > 5 ? s_Level > 10 ? 15 : 10 : 5;
    std::cout << "Speed of player is: " << s_Speed << "\n";


}