#include<iostream>
#include<fstream>
#include<string>

int main(){
    using namespace std;

    string filename;
    cout<<"Enter name for new file: ";
    cin>>filename;

    ofstream fout(filename.c_str());
    fout<<"For your eye only!\n";
    cout<<"Enter your secrect number: ";

    float secrect;
    cin>>secrect;
    fout<<"Your secrect number is "<<secrect<<endl;
    fout.close();

    ifstream fin(filename.c_str());
    cout<<"Here are the contents of "<<filename<<":\n";
    char ch;
    while(fin.get(ch)){
        cout<<ch;
    }
    cout<<"Done\n";
    fin.close();

    return 0;
}