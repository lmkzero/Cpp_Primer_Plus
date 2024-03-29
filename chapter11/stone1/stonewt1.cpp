#include<iostream>
#include "stonewt1.h"

using std::cout;
using std::endl;

Stonewt::Stonewt(){
    stone=pds_left=pounds=0;
}

Stonewt::Stonewt(double lbs){
    stone=int(lbs);
    pds_left=int(lbs)%Lbs_per_stn+lbs-int(lbs);
    pounds=lbs;
}

Stonewt::Stonewt(int stn,double lbs){
    stone=stn;
    pds_left=lbs;
    pounds=stn*Lbs_per_stn+lbs;
}

Stonewt::~Stonewt(){}

void Stonewt::show_lbs() const{
    cout<<pounds<<" pounds"<<endl;
}

void Stonewt::show_stn() const{
    cout<<stone<<" stone,"<<pds_left<<" pounds"<<endl;
}

Stonewt::operator int() const{
    return int(pounds+0.5);
}

Stonewt::operator double() const{
    return pounds;
}