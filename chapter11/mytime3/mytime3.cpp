#include<iostream>
#include "mytime3.h"

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
    minutes%=60;
}

void Time::addhr(int h){
    hours+=h;
}

void Time::reset(int h,int m){
    hours=h;
    minutes=m;
}

Time Time::operator + (const Time &t) const{
    Time sum;
    sum.minutes=minutes+t.minutes;
    sum.hours=hours+t.hours+sum.minutes/60;
    sum.minutes%=60;
    return sum;
}

Time Time::operator - (const Time &t) const{
    Time diff;
    int total1,total2;
    total1=t.minutes+t.hours*60;
    total2=minutes+hours*60;
    diff.minutes=(total2-total1)%60;
    diff.minutes=(total2-total1)/60;
    return diff;
}

Time Time::operator * (double n) const{
    Time result;
    long total=hours*n*60+minutes*n;
    result.hours=total/60;
    result.minutes=total%60;
    return result;
}

std::ostream & operator<< (std::ostream &os,const Time &t){
    os<<t.hours<<" hours "<<t.minutes<<" minutes"<<std::endl;
    return os;
}