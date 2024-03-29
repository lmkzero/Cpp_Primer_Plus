#include<iostream>
#include "namesp.h"

namespace pers{
    using std::cout;
    using std::cin;
    using std::endl;
    void getPerson(Person &rp){
        cout<<"Enter first name:";
        cin>>rp.fname;
        cout<<"Enter last name:";
        cin>>rp.lname;
    }
    void showPerson(const Person &rp){
        cout<<rp.lname<<" "<<rp.fname<<endl;
    }
}

namespace debts{
    void getDebt(Debt &rd){
        getPerson(rd.name);
        cout<<"Enter debt:";
        cin>>rd.amount;
    }
    void showDebt(const Debt &rd){
        showPerson(rd.name);
        cout<<"debt:"<<rd.amount<<endl;
    }
    double sumDebts(const Debt arr[],int n){
        double total=0.0;
        for(int i=0;i<n;i++){
            total+=arr[i].amount;
        }
        return total;
    }
}