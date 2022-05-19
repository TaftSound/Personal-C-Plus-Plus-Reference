#include <iostream>
#include <vector>
//this file NEEDS to be compiled using -std=c++20 ahead of the file name

//expanded function_pointers3.cpp to explain use of lambdas.
//a lamda is used where you might otherwise use a function pointer

//[1] here functions are defined and a function pointer is used to 
// pass a function into the ForEach function as an argument.
#if 0
void PrintValue(int value)
{
    std::cout << "Value: " << value << "\n";
}
#endif
void ForEach(const std::vector<int>& values, void(*func)(int))
{
    for (int value : values) 
        func(value);
}

int main() {
// [2] here you see a vector declared, followed by a call
//to the ForEach function which takes the vector and the 
//PrintValue function above as arguments. PrintValue is passed in
//by using a function pointer, which means that the function body 
//does not need to be duplicated in order to copy it in to the 
//ForEach function unnecesarily.
    std::vector<int> values = { 10, 3, 27, 18 };
//    ForEach(values, PrintValue);
// [3] here is an example that achieves the same end by utlizing a 
//lambda instead of a function pointer, which means that the function 
//PrintValue above is not necessary
    ForEach(values, [](int valueA) { std::cout << "Value: " << valueA << "\n"; });
#if 0
[1]
    [] = captures, e.g. what is this lambda able to accees outsie of it's own scope,
    if left blank, it captures nothing.  if [&] it captures everything used in the lambda
    function body by reference.  if [=] is used it captures every variable used in the lambda
    function body by copying. this can be specified for individual element as well.
    e.g. [&, &value] or [&value, =value13] or [=a, &b] or [=, &b]
[2]  
    the () following the capture [] is where you store parameters that will be passed to 
    the lambdas function body.
[3] the {} following the (parameters) and [captures] is where you store the lambda's
    function body
[4] the general structure of a lambda is: [captures](params) any specifiers {function body}
    will get deeper in to specifiers in its own file but this is one very useful example:
#endif
        int a = 27;
        auto lambda = [=](int value) mutable { a = 5; std::cout << "Value: " << a << "+" << value << "\n"; };
        lambda(4);
//if you do not inclue muteable in ^^^^^^^^^ this example, the lambda function will not be able to change 
//the value of a when it is passed by copy [=] into the lambda.
//could also be achieved as follows:
        auto lambda2 = [&](int value) { a = 5; std::cout << "Value: " << a << "+" << value << "\n"; };
        lambda2(4);
//this also allows you to change variable a in this case because it is passed by reference [&]
}