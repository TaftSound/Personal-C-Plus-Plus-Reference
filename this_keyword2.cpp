//playground for understanding this keyword
#include <iostream>

//    void multiply(const Test& e);

class Test 
{
    int x = 0;
    int y = 0;   

public:
//this keyword is a pointer to the current instantiated object of a class
//the following will not return 100 or 250 for the variables because the
//this keyword causes the functions to return specifically the x value stored
//in the class object.
    int getInput() { int x = 250; return this->x; }
    int getMult() { int y = 100; return this->y; }
 //following is a class constructor, taking two int values as parameters and
 //using the this keyword to store the identically names x and y variables
 //properly into those that represent actual data members x and y of the
 //Test class object when it is instantiated.
    Test (int x, int y) {
        this->x = x;
        this->y = y;
    #if 0  //<-- if this is included in the constructor, it will automatically 
           //call the function multiply with this object as the argument
        void multiply(const Test& e); //<--declaration must be here to call 
                                      //multiply function in the scope of the
                                      //constructor
        multiply(*this); //<--calls the multiply function.
    #endif
    }
    #if 1
    void multiply() {
        void multiply(const Test& e);  //<--must be declared WITHIN the scope of the function
        multiply(*this);  
    }
    #endif
    #if 0
    void multiply() {
        void multiply(Test& e);  //<--must be declared WITHIN the scope of the function
        multiply(*this);  
    }
    #endif

    #if 0
    void multiply(const Test& e);
    multiply(*this); //<--note that here it DOES NOT work, because you can not use the 
                     // this keyword outside of a member function. 
    #endif
};
#if 1   
    void multiply(const Test& e) 
    {
        auto test = e;
        int input = test.getInput();
        int mult = test.getMult();
        int output = (input * mult);
        std::cout << input << " times " << mult << " equals " << output << "\n";
    }
#endif
#if 0
    void multiply(Test& e) //can also be down without const in this way
    {
        int input = e.getInput();
        int mult = e.getMult();
        int output = (input * mult);
        std::cout << input << " times " << mult << " equals " << output << "\n";

    }
#endif
//main function here=============================================
int main() {

Test testB(5, 10);
std::cout << "The input is " << testB.getInput() << "\n";
std::cout << "The multiplier is " << testB.getMult() << "\n";

//both of these function calls below now achieve the same thing:
multiply(testB);
//testB.multiply(*this); //<--this cannot work because this keyword 
                        // can ONLY be used inside a member function
testB.multiply();


}