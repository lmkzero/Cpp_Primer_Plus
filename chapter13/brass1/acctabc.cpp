#include<iostream>
#include"acctabc.h"

using std::cout;
using std::endl;
using std::ios_base;
using std::string;

AcctABC::Formatting AcctABC::setFormat() const{
    Formatting f;
    f.flags=cout.setf(ios_base::fixed,ios_base::floatfield);
    f.pr=cout.precision(2);
    return f;
}

void AcctABC::restore(Formatting &f) const{
    cout.setf(f.flags,ios_base::floatfield);
    cout.precision(f.pr);
}

AcctABC::AcctABC(const string &s,long an,double bal){
    fullname = s;
    accnum=an;
    balance=bal;
}

void AcctABC::deposit(double amt){
    if(amt<0){
        cout<<"Negative deposit not allowed"<<endl;
    }else{
        balance+=amt;
    }
}

void AcctABC::withdraw(double amt){
    balance-=amt;
}

void Brass::withdraw(double amt){
    if(amt<0){
        cout<<"Withdraw amount must be positive"<<endl;
    }else if(amt<=Balance()){
        AcctABC::withdraw(amt);
    }else{
        cout<<"Withdraw amount exceeds your balance"<<endl;
    }
}

void Brass::viewacc() const{
    Formatting f=setFormat();
    cout<<"Brass Client:"<<FullName()<<endl;
    cout<<"Account number:"<<Accnum()<<endl;
    cout<<"Balance:"<<Balance()<<endl;
    restore(f);
}

BrassPlus::BrassPlus(const std::string &s,long an,double bal,double ml,double r):AcctABC(s,an,bal){
    maxloan=ml;
    owesbank=0.0;
    rate=r;
}

BrassPlus::BrassPlus(const Brass &ba,double ml,double r):AcctABC(ba){
    maxloan=ml;
    owesbank=0.0;
    rate=r;
}

void BrassPlus::viewacc() const{
    Formatting f=setFormat();
    cout<<"BrassPlus Client:"<<FullName()<<endl;
    cout<<"Account Number:"<<Accnum()<<endl;
    cout<<"Balance:"<<Balance()<<endl;
    cout<<"Maxloan:"<<maxloan<<endl;
    cout<<"Owed to bank:"<<owesbank<<endl;
    cout.precision(3);
    cout<<"Load Rate:"<<rate*100<<endl;
    restore(f);
}

void BrassPlus::withdraw(double amt){
    Formatting f=setFormat();
    double bal=Balance();
    if(amt<bal){
        AcctABC::withdraw(amt);
    }else if(amt<=bal+maxloan-owesbank){
        double advance=amt-bal;
        owesbank+=advance*(1.0+rate);
        cout<<"Bank advance:"<<advance<<endl;
        cout<<"Finance charge:"<<advance*rate<<endl;
        deposit(advance);
        AcctABC::withdraw(amt);
    }else{
        cout<<"Credit limit exceeded"<<endl;
    }
    restore(f);
}