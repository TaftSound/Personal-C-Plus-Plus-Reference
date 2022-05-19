#include <iostream>

//info about new keyword and use of new keyword
//the new keyword is used specifically to allocate memory on to the heap
//the point of allocating memory on the heap instead of the stack is that it 
//does not get deleted when it goes out of scope. However, it is much
//slower than allocating memory on the stack, and should only be used 
//when there is a reason you need to. It is also extremely important
//to remember that you NEED to use the delete function within your program
//for EVERY time that you use the new keyword.

//here is just the basic declaration of a variable without new keyword:
    int a = 0;
//here instead is the demonstration of the declaration using the new keyword:
    int* b = new int;
//new returns a pointer!! so now this means that b is a pointer whose data has 
//been stored specifically on the heap!!

//you can also use new to create a pointer to a function and allocate it to the heap
//simple function defined here and given an initialized name constructor.
class Entity {
    
    std::string name;
    
    public:
        Entity() : name("Entity") {}

        std::string getName() {return name;}
};

int main() {
//this is how you would dereference the pointer named b in order to change 
       // b; //<--this on its own now stores the memory address on the heap
//the value it is a pointer for
        *b = 27; //<-- this is how you de-reference the pointer to retrieve the 
                 //value stored at the memory address in b
//this just prints the value
        std::cout << *b << "\n";
//here the delete keyword is used to clean up by removing b from memory:
        delete b;
//here the new keyword is used to create a pointer to Entity e that is 
//allocated to the heap.  This also shows the different syntax for calling
//the Entity class's member function getName when Entity object is created 
//in this way.
    Entity* e = new Entity();
    std::cout << e->getName();
    std::cout << "\n";

    delete e;

return 0;
}