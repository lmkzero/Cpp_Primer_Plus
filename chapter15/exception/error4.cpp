#include<iostream>
#include<cmath>
#include"exc_mean.h"

double hmean(double a,double b){
    if(a==-b){
        throw bad_hmean(a,b);
    }
    return 2.0*a*b/(a+b);
}

double gmean(double a,double b){
    if(a<0||b<0){
        throw bad_gmean(a,b);
    }
    return std::sqrt(a*b);
}

int main(){
    using std::cout;
    using std::cin;
    using std::endl;

    double x,y;
    cout<<"Enter two numbers:"<<endl;
    while(cin>>x>>y){
        try{
            cout<<"Hmean of "<<x<<" and "<<y<<" is "<<hmean(x,y)<<endl;
            cout<<"Gmean of "<<x<<" and "<<y<<" is "<<gmean(x,y)<<endl;
            cout<<"Enter next set of numbers <q to quit>"<<endl;
        }catch(bad_hmean &bh){
            bh.mesg();
            continue;
        }catch(bad_gmean &bg){
            bg.mesg();
            break;
        }
    }

    return 0;
}