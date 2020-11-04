#include "worker0.h"
#include<iostream>

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker(){}

void Worker::set(){
    cout<<"Enter worker's name:"<<endl;
    getline(cin,fullname);
    cout<<"Enter worker's ID:"<<endl;
    cin>>id;
    while (cin.get()!='\n'){
        continue;
    }
}

void Worker::show() const{
    cout<<"Name:"<<fullname<<endl;
    cout<<"Employee ID:"<<id<<endl;
}

void Waiter::set(){
    Worker::set();
    cout<<"Enter waiter's panache rating:";
    cin>>panache;
    while(cin.get()!='\n'){
        continue;
    }
}

void Waiter::show() const{
    cout<<"Category:waiter"<<endl;
    Worker::show();
    cout<<"Panacher rating:"<<panache<<endl;
}

char* Singer::pv[]={"other", "alto","contralto","soprano","bass","baritone","tenor"};

void Singer::set(){
    Worker::set();
    cout<<"Enter number for singer's vocal range:"<<endl;
    int i;
    for(i=0;i<Vtype;i++){
        cout<<i<<":"<<pv[i]<<" ";
        if(i%4==3){
            cout<<endl;
        }
    }
    if(i%4!=0){
        cout<<endl;
    }
    while(cin>>voice&&(voice<0||voice>=Vtype)){
        cout<<"Please enter a value >=0 and < "<<Vtype<<endl;
    }
    while(cin.get()!='\n'){
        continue;
    }
}

void Singer::show() const{
    cout<<"Category:singer"<<endl;
    Worker::show();
    cout<<"Vocal range:"<<pv[voice]<<endl;
}