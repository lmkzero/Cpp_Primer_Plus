#include<iostream>
#include<sstream>
#include<string>

int main(){
    using namespace std;

    ostringstream outstr;
    string hdisk;
    cout<<"What's the name of your hard disk?"<<endl;
    getline(cin,hdisk);

    int cap;
    cout<<"What's its capacity in GB?"<<endl;
    cin>>cap;
    outstr<<"The hard disk "<<hdisk<<" has a capacity of "<<cap<<" gigabytes."<<endl;
    string result=outstr.str();
    cout<<result;

    return 0;
}