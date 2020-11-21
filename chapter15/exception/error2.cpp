// 返回错误码

#include<iostream>
#include<cfloat>

bool hmean(double a,double b,double *ans){
    if(a==-b){
        *ans=DBL_MAX;
        return false;
    }else{
        *ans=2.0*a*b/(a+b);
        return true;
    }
}

int main(){
    double x,y,z;
    std::cout<<"Enter two numbers:"<<std::endl;
    while(std::cin>>x>>y){
        if(hmean(x,y,&z)){
            std::cout<<"hmean of "<<x<<" and "<<y<<" is "<<z<<std::endl;
        }else{
            std::cout<<"One value should not be negative of the other - try again"<<std::endl;
        }
        std::cout<<"Enter next set of numbers <q to quit>:"<<std::endl;
    }

    return 0;
}