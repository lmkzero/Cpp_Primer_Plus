#include<iostream>
#include "stock00.h"

void Stock::acquire(const std::string &co,long n,double pr){
    company=co;
    if(n<0){
        std::cout<<"Numbers of shares can't be negative;"<<std::endl;
        std::cout<<"shares are set to 0"<<endl;
        shares=0;
    }else{
        shares=n;
    }
    share_val=pr;
    set_total();
}

void Stock::buy(long num,double price){
    if(num<0){
        std::cout<<"Numbers of shares purchased can't be negative;"<<std::endl;
    }else{
        shares+=num;
        share_val=price;
        set_total();
    }
}

void Stock::sell(long num,double price){
    if(n<0){
        std::cout<<"Numbers of shares sold can't be negative;"<<std::endl;
    }else if(num>shares){
        std::cout<<"You can't sell more than you have;"<<std::endl;
    }else{
        shares-=num;
        share_val=price;
        set_total();
    }
}

void Stock::update(double price){
    share_val=price;
    set_total();
}

void Stock::show(){
    std::cout<<"Company: "<<company<<", Shares: "<<shares<<endl;
    std::cout<<"Share price: "<<share_val<<", Total: "<<total_val<<endl;
}