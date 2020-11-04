#include<iostream>
#include "mytime3.h"

int main(){
    using std::cout;
    using std::endl;
    Time aida(3,35);
    Time tosca(2,48);
    Time temp;

    cout<<"Aida and tosca:"<<endl;
    cout<<aida;
    cout<<tosca;
    temp=aida+tosca;
    cout<<temp;

    temp=aida*1.17;
    cout<<temp;

    cout<<10.0*tosca<<endl;
    return 0;
}