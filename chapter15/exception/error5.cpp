#include<iostream>
#include<cmath>
#include<string>
#include"exc_mean.h"

class demo{
private:
    std::string word;
public:
    demo(const std::string &str){
        word=str;
        std::cout<<"demo "<<word<<" created"<<std::endl;
    }
    ~demo(){
        std::cout<<"demo "<<word<<" destoryed"<<std::endl;
    }
    void show() const{
        std::cout<<"demo "<<word<<" lives"<<std::endl;
    }
};

double hmean(double a,double b){
    if(a<0||b<0){
        throw bad_hmean(a,b);
    }
    return 2.0*a*b/(a+b);
}

double gmean(double a,double b){
    if(a<0||b<0){
        throw bad_gmean(a,b);
    }
    return std::sqrt(a*b);
}

double means(double a,double b){
    double am,hm,gm;
    demo d2("found in means()");
    am=(a+b)/2.0;
    try{
        hm=hmean(a,b);
        gm=gmean(a,b);
    }catch(bad_hmean &bh){
        bh.mesg();
        std::cout<<"Caught in means"<<std::endl;
        throw;
    }
    d2.show();
    return (am+hm+gm)/3.0;
}

int main(){
    using std::cout;
    using std::cin;
    using std::endl;

    double x,y,z;
    {
        demo d1("found in block in main()");
        cout<<"Enter two numbers:"<<endl;
        while(cin>>x>>y){
            try{
                z=means(x,y);
                cout<<"The mean mean of "<<x<<" and "<<y<<" is "<<z<<endl;
                cout<<"the next pair:"<<endl;
            }catch(bad_hmean &bh){
                bh.mesg();
                cout<<"Try again"<<endl;
                continue;
            }catch(bad_gmean &bg){
                cout<<bg.mesg();
                break;
            }
        }
        d1.show();
    }
    cout<<"done"<<endl;
    cin.get();
    cin.get();
    
    return 0;
}