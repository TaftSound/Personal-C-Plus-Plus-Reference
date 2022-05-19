#include <iostream>
#include <string>

//templates are not limited to use for types in functions.  you can create templates 
//for all kinds of things.  here are some examples:

//e.g. [1] here is a template for an array class
#if 1
template<int N>
class Array
{
private:
    int m_Array[N];  //<--this will set the array size to whatever int is 
                     // passed in to the template argument when it is called
public:
    int getSize() { return N; }
};
#endif

int main(){

// e.g. [1] calling an array class from the template above:
    Array<5> array;
//this ^^^ is identical to coding the follwing:
#if 0  //<--toggle between 1 and 0 to toggle code
class Array
{
private:
    int m_Array[5];
public:
    int getSize() { return 5; }
};

Array array;  //<--instantiates an object of Array called array
#endif
    std::cout << array.getSize() << "\n";

}