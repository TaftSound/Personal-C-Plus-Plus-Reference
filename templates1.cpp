#include <iostream>
#include <string>

//this is an example of a template.  it is not actually compiled until it
//is called in the main function, and can recieve any type
template <typename T>
//template<class T>  <-- this is another way you could write this that functions identically
void print(T value) {
    std::cout << value << "\n";
}
//if the template is not used later in the main function, for all intents
//and purposes it doesn't actually exist in the code when compiled.


int main(){

//example here you can see the print function accepting variables of any type:
    print("Turds");
    print(47);
    print('A');
    print(4.75683);
    print(true);
//you can also specify the types explicitly when you call the function like so:
    print<int>(5);
    print<char>('A');
    print<std::string>("This is a string yo");

}