#include<iostream>
#include "mytime0.h"

int main(){
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2,40);
    Time fixing(5,55);
    Time total;
    cout<<"planning time = ";
    planning.show();

    cout<<"coding time = ";
    coding.show();

    cout<<"fixing time = ";
    fixing.show();

    total=coding.sumtime(fixing);
    cout<<"total time = ";
    total.show();
    return 0;
}
