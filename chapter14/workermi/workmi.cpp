#include<iostream>
#include<cstring>
#include"workermi.h"

const int SIZE=5;

int main(){
    using std::cin;
    using std::cout;
    using std::endl;
    using std::strchr;

    Worker *lolas[SIZE];

    int ct;
    for(ct=0;ct<SIZE;ct++){
        char choice;
        cout<<"Enter the employee category:"<<endl;
        cout<<"w: waiter\ts: singer\tt: singing waiter\tq: quit"<<endl;
        cin>>choice;
        while(strchr("wstq",choice)==NULL){
            cout<<"Please enter a w,s,t,q:"<<endl;
            cin>>choice;
        }
        if(choice=='q'){
            break;
        }
        switch (choice){
            case 'w':
                lolas[ct]=new Waiter;
                break;
            case 's':
                lolas[ct]=new Singer;
                break;
            case 't':
                lolas[ct]=new SingerWaiter;
                break;
            default:
                break;
        }
        cin.get();
        lolas[ct]->set();
    }
    cout<<endl<<"Here is your staff:"<<endl;
    int i;
    for(i=0;i<ct;i++){
        cout<<endl;
        lolas[i]->show();
    }
    for(i=0;i<ct;i++){
        delete lolas[i];
    }
    cout<<"Bye."<<endl;

    return 0;
}