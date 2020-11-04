#ifndef ACCTABC_H_
#define ACCTABC_H_

#include<iostream>
#include<string>

class AcctABC{
private:
    std::string fullname;
    long accnum;
    double balance;
protected:
    struct Formatting{
        std::ios_base::fmtflags flags;
        std::streamsize pr;
    };
    const std::string & FullName() const { return fullname; }
    long Accnum() const { return accnum;}
    Formatting setFormat() const;
    void restore(Formatting &f) const;
public:
    AcctABC(const std::string &s="Nullbody",long an=-1,double bal=0.0);
    void deposit(double amt);
    double Balance() const { return balance;}
    virtual void withdraw(double amt) =0;
    virtual void viewacc() const =0;
    virtual ~AcctABC(){}
};


class Brass:public AcctABC{
public:
    Brass(const std::string &s="Nullbody",long an=-1,double bal=0.0):AcctABC(s,an,bal){}
    virtual void withdraw(double amt);
    virtual void viewacc() const;
    virtual ~Brass(){}
};


class BrassPlus:public AcctABC{
private:
    double maxloan;
    double rate;
    double owesbank;
public:
    BrassPlus(const std::string &s="Nullbody",long an=-1,double bal=0.0,double ml=500,double r=0.10);
    BrassPlus(const Brass & ba,double ml=500,double r=0.10);
    void resetMax(double m){
        maxloan=m;
    }
    void resetRate(double r){
        rate=r;
    }
    void resetOwes(){
        owesbank=0;
    }
    virtual void viewacc() const;
    virtual void withdraw(double amt);
};

#endif