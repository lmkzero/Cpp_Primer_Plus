#include<iostream>
using namespace std;

double betsy(int len){
    return 0.05*len;
}

double pam(int len){
    return 0.03*len+0.04*len*len;
}

void estimate(int line,double (*fp)(int)){
    cout<<line<<" lines will take ";
    cout<<(*fp)(line)<<" hours"<<endl;
}

int main(){
    int code;
    cin>>code;
    estimate(code,betsy);
    estimate(code,pam);
    return 0;
}