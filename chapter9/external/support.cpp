#include<iostream>
using namespace std;

extern double warming;

void update(double dt){
    // extern double warming;
    warming+=dt;
    cout<<"updating global warming to "<<warming<<endl;
}

void local(){
    double warming=0.8;
    cout<<"Local warming = "<<warming<<endl;
    cout<<"global warming = "<<::warming<<endl;
}  