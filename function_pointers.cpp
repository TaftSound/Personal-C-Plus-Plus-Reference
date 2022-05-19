#include <iostream>

//a function pointer is basically a way to assign a function to a variable
//here is a simple function:
void hello_world() {
    std::cout << "Hello World" << std::endl;
}

int main() {
#if 0
// [1] this is just calling the function in the normal way:
    hello_world();

// [2] this however creates a function pointer named function
//that is now a pointer to the function hello_world:
    auto function = &hello_world;
// can also be written as auto function = hello_world;  without the ampersand,
//as the compiler sees this as already implied when written in this way
// [3] so now, calling:
    hello_world();
//and calling:
    function();
//are essentially identical.
//you will notice that running the code up to this point prints
//hello world three times.
#endif
// [4] there are actually a variety of ways to create a function pointer.
//all of the following will create the same result:
#if 0
// way two:
    void(*function)() = hello_world; //<--this is identical to auto function = &hello_world;
//  void(*name_of_pointer)(any_parameters_here) = name_of_original; 
    function()
#endif
#if 1
//way three:
    typedef void(*hello_world_function)();
    hello_world_function function = hello_world;

    function();
#endif
}