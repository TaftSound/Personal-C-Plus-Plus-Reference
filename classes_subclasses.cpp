#include <iostream>
#include <string>
//note that related header file is included here:
#include "classes_subclasses.h"

//class definition
class Entity {

    public: 
        std::string getName() { return "Entity"; }

};
//this defines a sub class of the base class Entity:
class Player : public Entity {
//defines a name and number as a class attributes
    private: 
        std::string name;
        int playerNumber;
//defines a class constructor to take name as input, use a const string 
//reference to pass the values to name and playerNumber.  uses a member 
//initializer list
    public:
        Player(const std::string& newName, const int& newNumber)
            : name(newName),    // <-- member initializer list
              playerNumber(newNumber) {}
//declares a method to get name:
    std::string getName() { return name; }
};

int main() {
//creaters a pointer to the class Entity and the sub class Player 
//and allocates them to the heap. calls their getName member function
    Entity* e = new Entity();
    std::cout << e->getName() << "\n";

    Player* p = new Player("Matt", 27);
    std::cout << p->getName() << "\n";


    delete e;
    delete p;


return 0;
}
