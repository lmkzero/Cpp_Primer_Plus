#include<iostream>
#include<array>
#include<string>
using namespace std;

const int seasons=4;
const array<string,seasons> snames={"spring","summer","fall","winter"};

void fill(array<double,seasons> *pa){
    for(int i=0;i<seasons;i++){
        cout<<"Enter "<<snames[i]<<" expenses:"<<endl;
        cin>>(*pa)[i];
    }
}

void show(array<double,seasons> da){
    double total=0.0;
    for(int i=0;i<seasons;i++){
        cout<<snames[i]<<":"<<da[i]<<endl;
        total+=da[i];
    }
    cout<<"Total:"<<total<<endl;
}

int main(){
    array<double,seasons> expenses;
    fill(&expenses);
    show(expenses);
    return 0;
}