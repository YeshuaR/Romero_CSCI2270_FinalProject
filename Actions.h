#ifndef ACTIONS_H
#define ACTIONS_H
#include <string>

using namespace std;

struct Room{
        string message;
        int food;
        int speed;
        bool escaped = false;
        Room *left = nullptr;
        Room *right = nullptr;
        Room *backwards = nullptr;
        Room *forwards = nullptr;
        Room *upwards = nullptr;
        Room *downwards = nullptr;
        //add adj
};

struct user{
    string named;
    int food;
    int speed;
    Room *go;
};



class Actions
{
    public:
        Actions();  //Randomly creates the rooms and their locations and what is inside of them
        virtual ~Actions();
        void namer(string name); //Names the user
        int food_maker(); //Randomly makes foods in randomly rooms
        bool Monster(); //There is a monster above the user
        void freedom(); //When freedom has been reached
        void death();  //When death has been reached
        void playing(); //The function where the user actually plays in
        void grapher(); //Shows the graph and direction of movement to win the game
        //Since this a weird doubly linked list, creating a graph like in class would be a bit odd,
        //so I just made it so that the graph can be interpreted when drawn out since truly,
        //there is one direction.
    protected:

    private:
        user *Person = new user; //The user is a person!
        Room *Origin = new Room; //The first room
        int mape[15]; //Holds the cheats
};

#endif // ACTIONS_H
