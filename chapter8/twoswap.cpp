#include<iostream>
using namespace std;

struct job
{
    char name[40];
    double salary;
    int floor;
};

template<typename T>
void Swap(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}

// or
// template<> void Swap(job &a,job &b)
template<> void Swap<job>(job &a,job &b){
    double temp1=a.salary;
    a.salary=b.salary;
    b.salary=temp1;

    int temp2=a.floor;
    a.floor=b.floor;
    b.floor=temp2;
}

void show(job &a){
    cout<<a.name<<":"<<a.salary<<","<<a.floor<<endl;
}

int main(){
    cout.precision(2);
    cout.setf(ios::fixed,ios::floatfield);
    int i=10,j=20;
    cout<<"i,j="<<i<<","<<j<<endl;
    Swap(i,j);
    cout<<"i,j="<<i<<","<<j<<endl;

    job sue={"susan",7300.60,7};
    job sidney={"sidney",78060.72,9};
    show(sue);
    show(sidney);
    Swap(sue,sidney);
    show(sue);
    show(sidney);
    return 0;
}