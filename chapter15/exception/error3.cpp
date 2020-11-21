// 异常捕捉

#include<iostream>

bool hmean(double a,double b){
    if(a==-b){
        throw "bad hmean arguments a==-b";
    }
    return 2.0*a*b/(a+b);
}

int main(){
    double x,y,z;
    std::cout<<"Enter two numbers:"<<std::endl;
    while(std::cin>>x>>y){
        try{
            z=hmean(x,y);
        }catch(const char* s){
            std::cout<<s<<std::endl;
            std::cout<<"new pair of numbers:"<<std::endl;
            continue;
        }
        std::cout<<"hmean of "<<x<<" and "<<y<<" is "<<z<<std::endl;
        std::cout<<"Enter next set of numbers <q to quit>:"<<std::endl;
    }

    return 0;
}