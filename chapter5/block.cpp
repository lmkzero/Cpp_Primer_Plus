#include<iostream>
using namespace std;

int main(){
    int x=20;
    // 在语句块内，新变量隐藏旧变量
    // 语句块结束，旧变量再次可见
    {
        cout<<x<<endl;  // 原来的x
        int x=100;
        cout<<x<<endl;  // 新的x
    }
    cout<<x<<endl;  // 原来的x
    return 0;
}