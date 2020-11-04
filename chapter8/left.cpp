#include<iostream>
using namespace std;

const int arrSize=80;

// 在函数声明中指定默认值
// 要为某个参数设定默认值，则必须为它右边的每个参数设定默认值
char* left(const char* str,int n=1);

char* left(const char* str,int n){
    if(n<0){
        n=0;
    }
    char* p=new char[n+1];
    int i;
    for(i=0;i<n;i++){
        p[i]=str[i];
    }
    while(i<=n){
        p[i++]='\0';
    }
    return p;
}

int main(){
    char sample[arrSize];
    cout<<"Enter a string:"<<endl;
    cin.get(sample,arrSize);
    char* ps=left(sample,4);
    cout<<ps<<endl;
    delete[] ps;

    ps=left(sample);
    cout<<ps<<endl;
    delete[] ps;
    return 0;
}