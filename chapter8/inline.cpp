#include<iostream>
using namespace std;

// 函数调用
// 执行到函数调用指令时，程序将在函数调用后立即存储该指令的内存地址
// 并将函数参数复制到堆栈，跳转到标记函数起点的内存单元，指向函数代码
// 然后跳回到地址被保存的指令处

inline double square(double x){
    return x*x;
}

int main(){
    double a,b;
    double c=13.0;
    a=square(5.0);
    b=square(4.5+7.5);

    cout<<square(c++)<<endl;
    return 0;
}