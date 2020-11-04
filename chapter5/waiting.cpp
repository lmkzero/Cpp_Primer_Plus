#include<iostream>
#include<ctime>
using namespace std;

int main(){
    cout<<"delay time:"<<endl;
    float secs;
    cin>>secs;
    clock_t delay=secs*CLOCKS_PER_SEC;
    cout<<"starting\a\n";
    clock_t start=clock();
    cout<<start<<endl;
    while (clock()-start<delay){
        /* code */
    }
    cout<<clock()<<endl;
    cout<<"done"<<endl;
    return 0;
}