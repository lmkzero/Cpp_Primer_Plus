#include<iostream>
#include"brass.h"

using std::cout;
using std::endl;
using std::string;

typedef std::ios_base::fmtflags format;
typedef std::streamsize precis;

format setFormat(){
    return cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
}

void restore(format f,precis p){
    cout.setf(f,std::ios_base::floatfield);
    cout.precision(p);
}

Brass::Brass(const std::string &s,long an,double bal){
    fullname=s;
    accnum=an;
    balance=bal;
}

void Brass::deposit(double amt){
    if(amt<0){
        cout<<"Negative deposit not allowed"<<endl;
    }else{
        balance+=amt;
    }
}

double Brass::bal() const{
    return balance;
}

void Brass::withdraw(double amt){
    format initState=setFormat();
    precis p=cout.precision(2);
    if(amt<0){
        cout<<"Withdraw account must be positive"<<endl;
    }else if(amt<balance){
        balance -=amt;
    }else{
        cout<<"Withdraw account exceeds your balance"<<endl;
    }
    restore(initState,p);
}

void Brass::viewacc() const{
    format initState=setFormat();
    precis p=cout.precision(2);
    cout<<"Client:"<<fullname<<endl;
    cout<<"Account number:"<<accnum<<endl;
    cout<<"Balance:"<<balance<<endl;
    restore(initState,p);
}

BrassPlus::BrassPlus(const string &s,long an,double bal,double ml,double r):Brass(s,an,bal){
    maxloan=ml;
    owesbank=0.0;
    rate=r;
}

BrassPlus::BrassPlus(const Brass &ba,double ml,double r):Brass(ba){
    maxloan=ml;
    owesbank=0.0;
    rate=r;
}

void BrassPlus::resetmax(double m){
    maxloan=m;
}

void BrassPlus::resetrate(double r){
    rate=r;
}

void BrassPlus::resetowes(){
    owesbank=0.0;
}

void BrassPlus::viewacc() const{
    format initState=setFormat();
    precis p=cout.precision(2);
    Brass::viewacc();
    cout<<"Max loan:"<<maxloan<<endl;
    cout<<"Owed to bank:"<<owesbank<<endl;
    cout.precision(3);
    cout<<"Loan rate:"<<100*rate<<endl;
    restore(initState,p);
}

void BrassPlus::withdraw(double amt){
    format initState=setFormat();
    precis p=cout.precision(2);
    double bal=Brass::bal();
    if(amt<0){
        Brass::withdraw(amt);
    }else if(amt<=bal+maxloan-owesbank){
        double advance=amt-bal;
        owesbank+=advance*(1.0+rate);
        cout<<"Bank advance:"<<advance<<endl;
        cout<<"Finance charge:"<<advance*rate<<endl;
        deposit(advance);
        Brass::withdraw(amt);
    }else{
        cout<<"Credit limit exceeded"<<endl;
    }
    restore(initState,p);
}
