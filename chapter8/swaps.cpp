#include<iostream>
using namespace std;

void swapr(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
}

void swapp(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

void swap(int a,int b){
    int temp=a;
    a=b;
    b=temp;
}

void show(int a,int b){
    cout<<a<<'\t'<<b<<endl;
}

int main(){
    int wallet1=300;
    int wallet2=350;
    show(wallet1,wallet2);
    swapr(wallet1,wallet2);
    show(wallet1,wallet2);
    swapp(&wallet1,&wallet2);
    show(wallet1,wallet2);
    swap(wallet1,wallet2);
    show(wallet1,wallet2);
    return 0;
}