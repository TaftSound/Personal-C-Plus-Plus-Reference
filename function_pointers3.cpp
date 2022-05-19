#include <iostream>
#include <vector>

//expanding on function pointers, example use case:
//[1]
void PrintValue(int value)
{
    std::cout << "Value: " << value << "\n";
}
//in the following, the function parameters pass in by reference a vector of type
//int with name values, and use a function pointer to pass in a function with
//a parameter of type int as an argument and name this function pointer func.
//the result of running this code is that the function above, "PrintValue",
//is run for each iteration in the range of the for loop, and the value at 
//each index number of the vector is prianted via the PrintValue function
void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for (int value : values)  //<--come back to this syntax for for loops
                              // int value is the declaration of a variable
                              // values is the range of the for loop, which in this 
                              //case will equate to the size of the vector passed
                              //in to the function as an argument.
        func(value);
}

int main() {

    std::vector<int> values = { 10, 3, 27, 18 };
    ForEach(values, PrintValue);


}