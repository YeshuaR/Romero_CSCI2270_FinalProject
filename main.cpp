/*
Yeshua Romero
CSCI 2270
Lecturer Austin
*/


#include <iostream>
#include "Actions.h"
#include <string>

using namespace std;

int main()
{
    Actions act;

    string name;

    cout << "Hello user, you are entering a world unknown." << endl;
    cout << "Prepare yourself for a challenge, but first," << endl;
    cout << "Enter your name: ";

    //cin.ignore();
    getline(cin,name);

    act.namer(name);

    cout << "You need to escape this maze (not really, one path truly, but which way? the walls are too far to see..)." << endl;
    cout << "But you are running out of food, you need to eat per move to survive." << endl;
    cout << "Don't worry - I hope. By the way, you may find speed, it does nothing" << endl;
    cout << "==========" << endl;
    cout << "If you want to cheat or test the so called maze.. type graph" << endl;

    cout << "=== By the way, there is a monster roaming above your maze.." << endl;

    act.playing();

    return 0;
}
