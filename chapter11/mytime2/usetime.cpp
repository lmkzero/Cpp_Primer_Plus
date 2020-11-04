#include<iostream>
#include "mytime2.h"

int main(){
    using std::cout;
    using std::endl;
    Time weeding(4,35);
    Time waxing(2,47);
    Time total;
    Time diff;
    Time adjusted;

    cout<<"weeding time:";
    weeding.show();

    cout<<"waxing time:";
    waxing.show();

    cout<<"total work time:";
    total=weeding+waxing;
    total.show();

    cout<<"weeding time - waxing time:";
    diff=weeding-waxing;
    diff.show();

    cout<<"adjusted time:";
    adjusted=total*1.5;
    adjusted.show();

    return 0;
}