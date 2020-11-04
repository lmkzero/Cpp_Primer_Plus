#ifndef BRASS_H_
#define BRASS_H_

#include<string>

class Brass{
private:
    std::string fullname;
    long accnum;
    double balance;
public:
    Brass(const std::string &s="Nullbody",long an=-1,double bal=0.0);
    void deposit(double amt);
    double bal() const;
    virtual void withdraw(double amt);
    virtual void viewacc() const;
    virtual ~Brass(){}
};

class BrassPlus:public Brass{
private:
    double maxloan;
    double rate;
    double owesbank;
public:
    BrassPlus(const std::string &s="Nullbody",long an=-1,double bal=0.0,double ml=500,double r=0.11125);
    BrassPlus(const Brass &ba,double ml=500,double r=0.11125);
    void resetmax(double m);
    void resetrate(double r);
    void resetowes();
    virtual void viewacc() const;
    virtual void withdraw(double amt);
}

#endif