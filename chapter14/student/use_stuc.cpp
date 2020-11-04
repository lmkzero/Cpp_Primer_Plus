#include<iostream>
#include "studentc.h"

using std::cin;
using std::cout;
using std::endl;

const int pupils=3;
const int quizzes=5;

void set(Student &sa,int n){
    cout<<"Please enter the student's name:"<<endl;
    getline(cin,sa);
    cout<<"Please enter "<<n<<" quiz scores:"<<endl;
    for(int i=0;i<n;i++){
        cin>>sa[i];
    }
    while(cin.get()!='\n'){
        continue;
    }
}

int main(){
    Student ada[pupils]={Student(quizzes),Student(quizzes),Student(quizzes)};
    int i;
    for(i=0;i<pupils;i++){
        set(ada[i],quizzes);
    }
    cout<<"\nStudent List:"<<endl;
    for(i=0;i<pupils;i++){
        cout<<ada[i].get_name()<<endl;
    }
    cout<<endl<<"Results:"<<endl;
    for(i=0;i<pupils;i++){
        cout<<endl<<ada[i];
        cout<<"average: "<<ada[i].avgerage()<<endl;
    }
    return 0;
}