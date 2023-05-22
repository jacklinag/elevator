#include <vector>
using namespace std;
class Elevator;
class Building;
class Person;

class Elevator{
public:
    Elevator(){}
    Elevator(int x){
        current_floor = x;
    }

    int getfloor();
    void setfloor(int);
    void display_floor();
    void move(int);

private:
//the elevator at now:
    int current_floor;

};

class Person{
public:
    Person() = delete; 
    Person(int x,int y){
        _floor_start = x;
        _floor_end = y;
    }

    int getstart();
    int getend();

private:
    int _floor_start;
    int _floor_end;
};

class Building{
public:
    Building() = delete;
    Building(int x){
        maxfloor = x;
    }
    // member function
    Elevator* SeletElevatortoPerson(Person*);
    void NewElevator(Elevator*);
    void Elevateperson(Person*);
    void printstatus();

    // data member
    //Elevator* e1;
    //Elevator* e2;
    vector<Elevator*> _elist;
    int maxfloor;

};
