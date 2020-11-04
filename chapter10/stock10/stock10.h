#ifndef STOCK10_H_
#define STOCK10_H_

#include<string>

class stock10{
private:
    std::string company;
    long shares;
    double share_val;
    double total_val;
    void set_total(){
        total_val=shares*share_val;
    }
public:
    stock10();
    stock10(const std::string &co,long n=0,double pr=0.0);
    ~stock10();
    void buy(long num,double price);
    void sell(long num,double price);
    void update(double price);
    void show();
};

#endif