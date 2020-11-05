#include<iostream>
#include"workermi.h"

using std::cout;
using std::cin;
using std::endl;

Worker::~Worker(){}

void Worker::data() const{
    cout<<"Name:"<<fullname<<endl;
    cout<<"Employee ID:"<<id<<endl;
}

void Worker::get(){
    getline(cin,fullname);
    cout<<"Enter worker's ID:";
    cin>>id;
    while(cin.get()!='\n'){
        continue;
    }
}

void Waiter::data() const{
    cout<<"panache rating: "<<panache<<endl;
}

void Waiter::get(){
    cout<<"Enter waiter's panache rating"<<endl;
    cin>>panache;
    while(cin.get()!='\n'){
        continue;
    }
}

void Waiter::set(){
    cout<<"Enter waiter's name:";
    Worker::get();
    get();
}

void Waiter::show() const{
    cout<<"Category:waiter"<<endl;
    Worker::data();
    data();
}

char* Singer::pv[Singer::Vtype]={"other","alto","contralto","soprano","bass","baritone","tenor"};

void Singer::set(){
    cout<<"Enter singer's name:";
    Worker::get();
    get();
}

void Singer::show() const{
    cout<<"Category:singer"<<endl;
    Worker::data();
    data();
}

void Singer::data() const{
    cout<<"Vocal range:"<<pv[voice]<<endl;
}

void Singer::get(){
    cout<<"Enter number for singer's vocal range:"<<endl;
    int i;
    for(i=0;i<Vtype;i++){
        cout<<i<<": "<<pv[i]<<" ";
        if(i%4==3){
            cout<<endl;
        }
    }
    if(i%4!=0){
        cout<<endl;
    }
    cin>>voice;
    while(cin.get()!='\n'){
        continue;
    }
}

void SingerWaiter::data() const{
    Singer::data();
    Waiter::data();
}

void SingerWaiter::get(){
    Waiter::get();
    Singer::get();
}

void SingerWaiter::set(){
    cout<<"Enter singing waiter's name:";
    Worker::get();
    get();
}

void SingerWaiter::show() const{
    cout<<"Category singing waiter"<<endl;
    Worker::data();
    data();
}