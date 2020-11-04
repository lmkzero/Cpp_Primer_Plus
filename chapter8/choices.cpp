#include<iostream>
using namespace std;

template <typename T>
T lesser(T a,T b){
    return a<b?a:b;
}

int lesser(int a,int b){
    a=a<0?-a:a;
    b=b<0?-b:b;
    return a<b?a:b;
}

int main(){
    int m=20;
    int n=-30;
    double x=15.5;
    double y=25.5;
    // 使用非模板函数
    cout<<lesser(m,n)<<endl;
    // 使用模板函数，double
    cout<<lesser(x,y)<<endl;
    // <>表示应该使用模板函数，int
    cout<<lesser<>(m,n)<<endl;
    // 模板显示实例化，强制类型转换int
    cout<<lesser<int>(x,y)<<endl;
    return 0;
}