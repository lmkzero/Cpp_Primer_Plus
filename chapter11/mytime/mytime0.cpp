#include<iostream>
#include "mytime0.h"

Time::Time(){
    hours=minutes=0;
}

Time::Time(int h,int m){
    hours=h;
    minutes=m;
}

void Time::addmin(int m){
    minutes+=m;
    hours+=minutes/60;
    minutes=minutes%60;
}

void Time::addhr(int h){
    hours+=h;
}

void Time::reset(int h,int m){
    hours=h;
    minutes=m;
}

Time Time::sumtime(const Time &t) const{
    Time sum;
    sum.minutes=minutes+t.minutes;
    sum.hours=hours+t.hours+sum.minutes/60;
    sum.minutes=sum.minutes%60;
    return sum;
}

void Time::show() const{
    std::cout<<hours<<" hours, "<<minutes<<" mins"<<std::endl;
}