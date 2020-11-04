#include<iostream>
#include "mytime1.h"

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

void Time::show() const{
    std::cout<<hours<<" hours, "<<minutes<<" mins"<<std::endl;
}

Time Time::operator + (const Time &t) const{
    Time sum;
    sum.minutes=t.minutes+minutes;
    sum.hours=t.hours+hours+sum.minutes/60;
    sum.minutes=sum.minutes%60;
    return sum;
}