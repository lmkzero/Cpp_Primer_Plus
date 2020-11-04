#include<iostream>
#include "stock20.h"

Stock::Stock(){
    company="no name";
    shares=0;
    share_val=0.0;
    total_val=0.0;
}

Stock::Stock(const std::string &co,long n,double pr){
    company=co;
    if(n<0){
        std::cout<<"Numbers of shares can't be negative;"<<std::endl;
        shares=0;
    }else{
        shares=n;
    }
    share_val=pr;
    set_total();
}

Stock::~Stock(){
    // nothing
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

void Stock::update(double price){
    share_val=price;
    set_total();
}

void Stock::show() const{
    using std::cout;
    using std::endl;
    using std::ios_base;
    ios_base::fmtflags orig=cout.setf(ios_base::fixed,ios_base::floatfield);
    std::streamsize prec=cout.precision(3);
    cout<<"Company: "<<company<<" Shares: "<<shares<<endl;
    cout<<"Share price: "<<share_val<<endl;
    cout.precision(2);
    cout<<"Total worth: "<<total_val<<endl;

    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);
}

const Stock& Stock::topval(const Stock &s) const{
    if(s.total_val>total_val){
        return s;
    }else{
        return *this;
    }
}