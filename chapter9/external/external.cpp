#include<iostream>
using namespace std;

double warming=0.3;

void update(double dt);
void local();

int main(){
    cout<<"global warming = "<<warming<<endl;
    update(0.1);
    cout<<"global warming = "<<warming<<endl;
    local();
    cout<<"global warming = "<<warming<<endl;
    return 0;
}