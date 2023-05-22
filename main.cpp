#include "elevator.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
    Elevator* elevator1 = new Elevator(0);
    Elevator* elevator2 = new Elevator(0);
    Building* b = new Building(10);
    b->NewElevator(elevator1);
    b->NewElevator(elevator2);
    
    while(true){
        cout<< "input e for elevate , s for check elevators' status"<<endl;
        string str;
        cin >> str;
        if(str.size()!=1){
            cerr<< "error command!! plz reinput again"<<endl;
        }
        else if(str[0]=='e'){
            int _floor_start, _floor_end; 
            cout << "which floor are you at?" <<endl;
            cin >> _floor_start;
            if(_floor_start>10 || _floor_start<0){
                cerr << "Out of this building!!"<<endl;
            }
            cout << "which floor are you leaving for?" <<endl;
            cin >> _floor_end;
            if(_floor_end>10 || _floor_end<0){
                cerr << "Out of this building!!"<<endl;
                continue;
            }
            else if(_floor_end == _floor_start){
                cerr << "you are already at floor " << _floor_start<<endl;
                continue;
            }
            Person* a = new Person(_floor_start,_floor_end);
            b->Elevateperson(a);
            delete a;
        }
        else if(str[0]=='s'){
            b->printstatus();
        }
        else{
            cerr<<"error command!! plz reinput again"<<endl;
        }
            
    }
    delete elevator1;
    delete elevator2;
    delete b;
    return 0;
}