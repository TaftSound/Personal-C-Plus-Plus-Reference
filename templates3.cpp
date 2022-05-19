#include <iostream>
#include <string>

//to take previous example even further, you can use templete to allow for variable
//size AND variable type for this class template Array:

//e.g. [1] here is the previous template for an array class
#if 0
template<int N>
class Array
{
private:
    int m_Array[N];  //<--this will set the array size to whatever int is 
                     // passed in to the template argument when it is called
public:
    int getSize() const { return N; }
};
#endif
//e.g. [2] here is a similar template set up that additionally allows
//for variable types in the class Array:
template<typename T, int N>
class Array
{
private:
    T m_Array[N];
public:
    int getSize() const { return N; }
};

int main(){
#if 0
// e.g. [1] calling an array class from the first template above:
    Array<5> array;
#endif
// e.g. [2] calling an array class from the second template above:
    Array<std::string, 25> array; 
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