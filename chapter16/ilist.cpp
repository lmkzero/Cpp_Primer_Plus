#include<iostream>
#include<initializer_list>

double sum(std::initializer_list<double> il){
    double tot=0;
    for(auto p=il.begin();p!=il.end();p++){
        tot+=*p;
    }
    return tot;
}

double average(const std::initializer_list<double> &rill){
    double tot=0;
    int n=rill.size();
    double ave=0.0;
    if(n>0){
        for(auto p=rill.begin();p!=rill.end();p++){
            tot+=*p;
        }
        ave=tot/n;
    }
    return ave;
}

int main(){
    using std::cout;
    using std::endl;
    cout<<"List 1:sum="<<sum({2,3,4})<<", ave= "<<average({2,3,4})<<endl;

    std::initializer_list<double> dl={1.1,2.2,3.3,4.4,5.5};
    cout<<"List 2:sum="<<sum(dl)<<", ave= "<<average(dl)<<endl;

    dl={16.0,25.0,36.0,40.0,64.0};
    cout<<"List 3:sum="<<sum(dl)<<", ave= "<<average(dl)<<endl;

    return 0;
}