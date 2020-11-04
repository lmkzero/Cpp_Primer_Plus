#include<iostream>
using namespace std;

const int Max=5;

int fill_array(double arr[],int limit){
    double temp;
    int i;
    for(i=0;i<limit;i++){
        cout<<"Enter value #"<<(i+1)<<":";
        cin>>temp;
        if(!cin){
            cin.clear();
            while(cin.get()!='\n'){
                continue;
            }
            cout<<"bad input"<<endl;
            break;
        }else if(temp<0){
            break;
        }else{
            arr[i]=temp;
        }
    }
    return i;
}

void show_array(const double arr[],int n){
    for(int i=0;i<n;i++){
        cout<<"Property #"<<(i+1)<<":"<<arr[i]<<endl;
    }
}

void revalue(double fa,double arr[],int size){
    for(int i=0;i<size;i++){
        arr[i]*=fa;
    }
}

int main(){
    double properties[Max];
    int size=fill_array(properties,Max);
    show_array(properties,size);
    if(size>0){
        cout<<"Enter revaluation factor:";
        double factor;
        while(!(cin>>factor)){
            cin.clear();
            while(cin.get()!='\n'){
                continue;
            }
            cout<<"bad input"<<endl;
        }
        revalue(factor,properties,size);
        show_array(properties,size);
    }
    cout<<"Done"<<endl;
    return 0;
}