#include<iostream>
using namespace std;

template <typename T>
void Swap(T &a,T &b){
    T temp=a;
    a=b;
    b=temp;
}

template<typename T>
void Swap(T a[],T [],int n){
    T temp;
    for(int i=0;i<n;i++){ 
        temp=a[i];
        a[i]=b[i];
        b[i]=temp;
    }
}

int main(){
    int i=10,j=20;
    cout<<i<<'\t'<<j<<endl;
    Swap(i,j);
    cout<<i<<'\t'<<j<<endl;

    const int len=8;
    int d1[len]={0,7,0,4,1,7,7,6};
    int d2[len]={0,7,2,0,1,9,6,9};
    Swap(d1,d2,len);
    return 0;
}