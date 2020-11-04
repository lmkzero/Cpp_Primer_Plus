#include<iostream>
using namespace std;

int main(){
    const int size=20;
    char name[size];
    char dessert[size];
    cout<<"Enter your name:"<<endl;
    // 在name的输入是多个单词的情况下,第二个单词会保存在输入队列中，也就是dessert会直接输出
    cin>>name;
    cout<<"Enter your favorite dessert:"<<endl;
    cin>>dessert;
    cout<<"I have some "<<dessert<<endl;
    return 0;
}