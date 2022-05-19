#include <iostream>
#include <string>
//this expands on pure virtual functions 1 and demonstrates
//implementation of an "interface"

//this base class Printable is a class set up in a way that is 
//referred to as an interface, because it only contains a 
//pure virtual function

class Printable {
    public:
        virtual std::string getClassName() = 0; //<--pure virtual function
};

//class definition
class Entity : public Printable {
    public:
        virtual std::string getName() { return "Entity"; } //<--virtual function
        std::string getClassName() override { return "Entity"; }

};

//subclass definition
class Player : public Entity {
    private: 
        std::string name;
    public:
        Player(const std::string& newName)
            : name(newName) {}
    
    std::string getName() override { return name; }
    std::string getClassName() override { return "Player"; }
};

void print(Printable* obj) {    //<--we are using a type that we created above
    std::cout << obj->getClassName() << "\n";
}

int main() {

    Player* p = new Player("Matt");
    Entity* e = new Entity();  //<--THIS WILL NOW NOT GIVE YOU AN ERROR
                               // because the pure virtual function has 
                               // been implemented by the subclasses of 
                               // the child functions.
    print(e);
    print(p);

return 0;
}
