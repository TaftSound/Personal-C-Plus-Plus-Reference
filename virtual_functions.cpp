#include <iostream>
#include <string>
//in this file a class Entity and subclass Player are defined in
//order to use them to demonstrate a reason to use virtual functions 
//something important to remember is that they negatively impact 
//performance in some small ways

//class definition
class Entity {
    public:
//declares a method to get name:
//        std::string getName() { return "Entity"; }

//this declares the same method as a VIRTUAL function instead:
//toggle between which is active and notice the diffent result
        virtual std::string getName() { return "Entity"; }
};
//subclass definition
class Player : public Entity {
    private: 
        std::string name;
    public:
        Player(const std::string& newName)
            : name(newName) {}
//notice that this again declares a method to get name,
//but with a different return value:
//    std::string getName() { return name; }

//these two are equivalent in this case, but this is what override means,
//that this is overriding the virtual function in the base class
    std::string getName() override { return name; }
};

int main() {
//this will function as expected, printing the name of the Entity
//and the name of the Player:
    Entity* e = new Entity();
    std::cout << e->getName() << "\n";

    Player* p = new Player("Matt");
    std::cout << p->getName() << "\n";
//when you run the code, the following sill STILL print "Entity", 
//even though you have initialized it as p, which is a player, 
//and player p has a name of Matt.  But if you look back up to the two 
//getName() functions above, this result makes sense.
    Entity* entity = p;
    std::cout << entity->getName() << "\n";

//this becomes an issue when you use polymorphism, which can be solved
//by using virtual functions, look back up top and switch the virtual function 
//on and off, see what happens.



return 0;
}
