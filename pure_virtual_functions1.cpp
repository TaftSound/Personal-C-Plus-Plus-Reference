#include <iostream>
#include <string>
//this is the same as the virtual functions note but made specific
//to pure virtual functions

//class definition
class Entity {
    public:

//this declares getName() as a pure virtual function, which now
//MUST be implemented by the subclass when the subclass is instantiated

        virtual std::string getName() = 0;  //<--THIS IS A PURE VIRTUAL FUNCTION

//when a bass class is defined with only pure virtual functions that must
//be implemented when a sub class is instantiated, this set up is sometimes
//referred to as an interface.
};

//subclass definition
class Player : public Entity {
    private: 
        std::string name;
    public:
        Player(const std::string& newName)
            : name(newName) {}

//this is the funtion which MUST be implemented when instantiating 
//this sub class due to the use of a pure virtual function in 
//the base class:
    std::string getName() override { return name; }
};

int main() {

    Entity* e = new Entity();  //<--THIS WILL GIVE YOU AN ERROR
                               // because the pure virtual function above
                               // has not been implemented when this instance
                               // is instantiated


return 0;
}
