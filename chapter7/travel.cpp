#include<iostream>
using namespace std;

struct travel_time{
    int hours;
    int mins;
};

const int Min_per_hour=60;

travel_time sum(travel_time t1,travel_time t2){
    travel_time total;
    total.mins=(t1.mins+t2.mins)%Min_per_hour;
    total.hours=(t1.hours+t2.hours)+(t1.mins+t2.mins)/Min_per_hour;
    return total;
}

void show_time(travel_time t){
    cout<<"H:"<<t.hours<<endl;
    cout<<"M:"<<t.mins<<endl;
}

int main(){
    travel_time day1={5,45};
    travel_time day2={4,55};
    travel_time trip=sum(day1,day2);
    show_time(trip);
    return 0;
}