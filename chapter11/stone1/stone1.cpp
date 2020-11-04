#include<iostream>
#include "stonewt1.h"

using std::cout;
using std::endl;

int main(){
    Stonewt poppins(9,2.8);
    double p_wt=poppins;
    cout<<"Convert to double => ";
    cout<<"Poppins: "<<p_wt<<" pounds"<<endl;
    cout<<"Convert to int => ";
    cout<<"Poppins: "<<int(poppins)<<" pounds"<<endl;
    return 0;
}