#include<iostream>
#include "namesp.h"

void other(){
    using std::cout;
    using std::endl;
    using namespace debts;
    Person dg={"Doodles","Glister"};
    showPerson(dg);
    cout<<endl;

    Debt zippy[3];
    int i;
    for (i = 0; i < 3; i++){
        getDebt(zippy[i]);
    }
    for(i=0;i<3;i++){
        showDebt(zippy[i]);
    }
    cout<<"Total:"<<sumDebts(zippy,3)<<endl;
}

void another(){
    using pers::Person;
    Person collector={"Milo","Rightshift"};
    pers::getPerson(collector);
    std::cout<<std::endl;
}

int main(){
    using debts::Debt;
    using debts::showDebt;
    Debt golf={{"Benny","Goatsniff"},120.0};
    showDebt(golf);

    return 0;
}