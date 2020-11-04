#include<iostream>
#include "stonewt.h"

using std::cout;
using std::endl;

void display(const Stonewt &st,int n){
    for(int i=0;i<n;i++){
        st.show_stn();
    }
}

int main(){
    Stonewt incognito=275;
    Stonewt wolfe(285.7);
    Stonewt taft(21,8);
    cout<<"The celebrity weighted ";
    incognito.show_stn();
    cout<<"The detective weighted ";
    wolfe.show_stn();
    cout<<"The president weighted ";
    taft.show_lbs();

    incognito=276.8;
    taft=325;
    cout<<"After dinner, the celebrity weighted ";
    incognito.show_stn();
    cout<<"After dinner, the presdient weighted ";
    taft.show_lbs();
    display(taft,2);
    cout<<"The wrestler weighted even more ";
    display(422,2);
    
    return 0;
}