#include "Actions.h"
#include <string>
#include <iostream>

using namespace std;

Actions::Actions()
{
    int rooms;
    int obj;
    int whatroom;

    Room *r = new Room;
    Room *tmp = Origin;
    rooms = 15;
    int g = 0;
    //cout << rooms << " SDFGDFS" << endl;
    for(int x = 0; x < rooms; x++){

        obj = rand() % 3;
        if(obj == 0){
            r->message = "Nothing here.";
        }else if(obj == 1){
            r->message = "Ooo fooood.";
            r->food = food_maker();
        }else{
            r->message = "Ooooo speeeeed";
            r->speed = rand() & 3;
        }

        //Six different possible room locations
        obj = rand() & 5;
        mape[g] = obj;
        g++;
        if(tmp->backwards == nullptr && obj == 0){
            r->forwards = tmp;
            tmp->backwards = r;
            //cout << "back";
        }

        if(tmp->forwards == nullptr && obj == 1){
            r->backwards = tmp;
            tmp->forwards = r;
            //cout << "forwards";
        }

        if(tmp->upwards == nullptr && obj == 2){
            r->backwards = tmp;
            tmp->upwards = r;
            //cout << "up";
        }

        if(tmp->downwards == nullptr && obj == 3){
            r->upwards = tmp;
            tmp->downwards = r;
            //cout << "down";
        }

        if(tmp->left == nullptr && obj == 4){
            r->right = tmp;
            tmp->left = r;
            //cout << "left";
        }

        if(tmp->right == nullptr && obj == 5){
            r->left = tmp;
            tmp->right = r;
            //cout << "right";
        }

        if(obj == 6){
            delete r;
            Room *re = new Room;
            r = re;
            continue;
        }

        tmp = r;
        Room *red = new Room;
        r = red;

    }
    r->downwards = tmp;
    tmp->upwards = r;
    r->escaped = true;

}


Actions::~Actions()
{
    //dtor
}

void Actions::namer(string user_name){
    Person->named = user_name;
    Person->food = 54;
}

int Actions::food_maker(){
    int yums;
    yums = rand() % 10;

    return yums;
}

bool Actions::Monster(){
    int OhNo = 0;
    int decider;
    decider = rand() % 20;
    if(OhNo == decider){
        cout << "I am sorry "<< Person->named << ", but you have lost.." << endl;
        cout << "The roof above you collapsed by the Monster.." << endl;
        cout << "Unlucky.." << endl;
        //cout << "Git Gud" << endl;
        death();
        return 1;
    }
    return 0;
}

void Actions::freedom(){
    cout << "Congratulations you are free." << endl;
    cout << "Goodbye" << endl;
}
void Actions::death(){
    cout << "Congratulations you are dead." << endl;
    cout << "Goodbye" << endl;
}


void Actions::playing(){
    string choice;
    Person->go = Origin;
    while(Person->go->escaped != true){
        bool d = Monster();
        if(d == 1){
            break;
        }
        if(Person->food == 0){
            death();
            return;
        }
        if(choice == "graph"){
            grapher();
        }
        cout << "Where do you want to move next?" << endl;
        cout << "Upwards? Downwards? Left? Right? Forwards? Backwards?" << endl;
        cout << "Also, please type upwards to go upwards, downwards to go downwards, etc., in all lowercase. " << endl;
        //cin.ignore();
        //getline(cin,choice);
        cin >> choice;
        string word[6] = {"upwards", "downwards", "left", "right" , "forwards" , "backwards"};
        int counte = 0;
        for(int y = 0; y<6; y++){
            if(choice == word[y]){
                break;
            }
            counte++;
        }
        if(counte == 6){
             cout << "Please try to type again," << endl;
             continue;
        }

        //if(choice != "upwards" || choice != "downwards" || choice != "left" || choice != "right" ||choice != "forwards" ||choice != "backwards"){
          //  cout << "Please try to type again," << endl;
           // continue;
        //}
        bool able = false;
        while(able == false){
            if(choice == "upwards"){
                if(Person->go->upwards != nullptr){
                    Person->go = Person->go->upwards;
                    Person->food = Person->food - 1;
                    able = true;
                    cout << "YOU ARE IN A NEW ROOM." << endl;
                    break;
                }else{
                    cout << "Whoops, there is no room there. Just a wall." << endl;
                    Person->food = Person->food - 1;
                    break;
                }
            }
            if(choice == "downwards"){
                if(Person->go->downwards != nullptr){
                    Person->go = Person->go->downwards;
                    Person->food = Person->food - 1;
                    able = true;
                    cout << "YOU ARE IN A NEW ROOM." << endl;
                    break;
                }else{
                    cout << "Whoops, there is no room there. Just a wall." << endl;
                    Person->food = Person->food - 1;
                    break;
                }
            }
            if(choice == "left"){
                if(Person->go->left != nullptr){
                    Person->go = Person->go->left;
                    Person->food = Person->food - 1;
                    able = true;
                    cout << "YOU ARE IN A NEW ROOM." << endl;
                    break;
                }else{
                    cout << "Whoops, there is no room there. Just a wall." << endl;
                    Person->food = Person->food - 1;
                    break;
                }
            }
            if(choice == "right"){
                if(Person->go->right != nullptr){
                    Person->go = Person->go->right;
                    Person->food = Person->food - 1;
                    able = true;
                    cout << "YOU ARE IN A NEW ROOM." << endl;
                    break;
                }else{
                    cout << "Whoops, there is no room there. Just a wall." << endl;
                    Person->food = Person->food - 1;
                    break;
                }
            }
            if(choice == "forwards"){
                if(Person->go->forwards != nullptr){
                    Person->go = Person->go->forwards;
                    Person->food = Person->food - 1;
                    able = true;
                    cout << "YOU ARE IN A NEW ROOM." << endl;
                    break;
                }else{
                    cout << "Whoops, there is no room there. Just a wall." << endl;
                    Person->food = Person->food - 1;
                    break;
                }
            }
            if(choice == "backwards"){
                if(Person->go->backwards != nullptr){
                    Person->go = Person->go->backwards;
                    Person->food = Person->food - 1;
                    able = true;
                    cout << "YOU ARE IN A NEW ROOM." << endl;
                    break;
                }else{
                    cout << "Whoops, there is no room there. Just a wall." << endl;
                    Person->food = Person->food - 1;
                    break;
                }
            }

        }
        if(able == false){
            cout << "Food left: " << Person->food << endl;
            continue;
        }


        Person->food = Person->food + Person->go->food;
        Person->speed = Person->speed + Person->go->speed;
        cout << Person->go->message << endl;


        cout << "Food left: " << Person->food << endl;
        cout << "Current speed: " << Person->speed << endl;
    }
    if(Person->go->escaped == true){
        freedom();
    }
    if(Person->go->escaped == false){
        return;
    }
}


void Actions::grapher(){

    cout << "Welp, you found out the cheat code.." << endl;
    cout << "=============" << endl;
    cout << "backwards = 0" << endl;
    cout << "forwards  = 1" << endl;
    cout << "upwards   = 2" << endl;
    cout << "downwards = 3" << endl;
    cout << "left      = 4" << endl;
    cout << "right     = 5" << endl;
    cout << "=============" << endl;
    for(int t = 0; t < 15; t++){
        cout << t + 1 << ". " << mape[t] << endl;
    }

}
