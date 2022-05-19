//playground for understanding this keyword
#include <iostream>

class Test 
{
    std::string text = "This is a test.";
    int x = 5;

public:
//this keyword is a pointer to the current instantiated object of a class
    void timesFive(int x) 
    {
        std::cout << x << " times five equals " << (x * this->x) << "\n"; 
    }

};

int main() {

Test testA;
testA.timesFive(10);



}