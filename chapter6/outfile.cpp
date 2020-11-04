#include<iostream>
#include<fstream>
using namespace std;

int main(){
    char automobile[50];
    int year;
    double a_price,b_price;
    ofstream outFile;
    outFile.open("./chapter6/carinfo.text");
    cout<<"Enter the make and model of automobile"<<endl;
    cin.getline(automobile,50);
    cout<<"Enter the model year"<<endl;
    cin>>year;
    cout<<"Enter the original asking price"<<endl;
    cin>>a_price;
    b_price=0.913*a_price;

    cout<<fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout<<"Make and model:"<<automobile<<endl;
    cout<<"Year:"<<year<<endl;
    cout<<"Was asking $"<<a_price<<endl;
    cout<<"Now asking $"<<b_price<<endl;

    outFile<<fixed;
    outFile.precision(2);
    outFile.setf(ios_base::showpoint);
    outFile<<"Make and model:"<<automobile<<endl;
    outFile<<"Year:"<<year<<endl;
    outFile<<"Was asking $"<<a_price<<endl;
    outFile<<"Now asking $"<<b_price<<endl;

    outFile.close();
    return 0;
}