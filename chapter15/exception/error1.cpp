// 调用abort()函数
// vscode + wsl环境下会报错，信息类似如下
// 无法打开“raise.c”...

#include<iostream>
#include<cstdlib>

double hmean(double a,double b){
    if(a==-b){
        std::cout<<"untenable arguments to hmean"<<std::endl;
        std::abort();
    }
    return 2.0*a*b/(a+b);
}

int main(){
    double x,y,z;
    std::cout<<"Enter two numbers:"<<std::endl;
    while(std::cin>>x>>y){
        z=hmean(x,y);
        std::cout<<"hmean of "<<x<<" and "<<y<<" is "<<z<<std::endl;
        std::cout<<"Enter next set of numbers <q to quit>:"<<std::endl;
    }
    return 0;
}