#include <iostream>
#include <string>

//class declaration
class Entity {

    public: 
        std::string getName();

};
//this declares a sub class of the base class Entity:
class Player : public Entity {
//declares a name as a class attribute
    private: 
        std::string name;
        int playerNumber;
//class constructor declaration:
    public:
        Player(const std::string& newName, const int& newNumber)

//declares a method to get name:
        std::string getName();
};

