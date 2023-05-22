#include "elevator.h"
#include <iostream>
#include <windows.h>
using namespace std;

int 
Elevator::getfloor()
{
    return current_floor;
}

void 
Elevator::display_floor()
{
    cout << "the elevator is at " << current_floor << endl;
}

void 
Elevator::move(int a)
{
    setfloor(a);
    display_floor();
}

void 
Elevator::setfloor(int a)
{   
    Sleep(abs(current_floor-a)*1000);
    current_floor = a;
}


Elevator* 
Building::SeletElevatortoPerson(Person* a)
{   
    int mindiff =  maxfloor;
    Elevator* ret;
    for(int i=0; i<_elist.size(); i++){
        if(abs(_elist[i]->getfloor()-a->getstart()) <= mindiff){
            mindiff = abs(_elist[i]->getfloor()-a->getstart());
            ret = _elist[i];
        }
    }
    //move to person start floor 
    ret->setfloor(a->getstart());   
    cout << "elevator arrives start floor !!"<<endl;
    return ret;
}

void 
Building::NewElevator(Elevator* ne)
{   
    if(!ne){
        return;
    }
    _elist.push_back(ne);
}

void 
Building::Elevateperson(Person* a)
{   
    //chose a elevator to person start floor
    Elevator* tmp = SeletElevatortoPerson(a);
    //moving to end floor
    tmp->setfloor(a->getend());
    cout << "elevator arrives destination !!"<<endl;
    tmp->display_floor();
}

void 
Building::printstatus()
{   
    for(int i=0; i<_elist.size(); i++){
        cout << "elevator "<<i<< " is at:" <<_elist[i]->getfloor() << endl;
    }
}

int 
Person::getstart()
{
    return _floor_start;
}

int 
Person::getend()
{
    return _floor_end;
}
