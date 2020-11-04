#include<iostream>
#include "stock10.h"

stock10::stock10(){
    std::cout<<"Default constructor called"<<std::endl;
    company="no name";
    shares=0;
    share_val=0.0;
    total_val=0.0;
}

stock10::stock10(const std::string &co,long n,double pr){
    std::cout<<"Constructor using "<<co<<" called"<<std::endl;
    company=co;
    if(n<0){
        std::cout<<"Numbers of shares can't be nagative;"<<std::endl;
        shares=0;
    }else{
        shares=n;
    }
    share_val=pr;
    set_total();
}

stock10::~stock10(){
    std::cout<<"released object"<<std::endl;
}

void stock10::buy(long num,double price){
    if(num<0){
        std::cout<<"Numbers of shares purchased can't be negative;"<<std::endl;
    }else{
        shares+=num;
        share_val=price;
        set_total();
    }
}

void stock10::sell(long num,double price){
    if(num<0){
        std::cout<<"Numbers of shares sold can't be negative;"<<std::endl;
    }else if(num>shares){
        std::cout<<"You can't sell more than you have"<<std::endl;
    }else{
        shares-=num;
        share_val=price;
        set_total();
    }
}

void stock10::update(double price){
    share_val=price;
    set_total();
}

void stock10::show(){
    using std::cout;
    using std::endl;
    using std::ios_base;
    ios_base::fmtflags orig=cout.setf(ios_base::fixed,ios_base::floatfield);
    std::streamsize prec=cout.precision(3);
    cout<<"Company: "<<company<<" Shares: "<<shares<<endl;
    cout<<"Shares price: "<<share_val<<endl;
    cout.precision(2);
    cout<<"Total: "<<total_val<<endl;
    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);
}