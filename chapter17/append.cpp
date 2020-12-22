#include<iostream>
#include<fstream>
#include<string>
#include<cstdlib>

const char *file="./chapter17/guests.txt";

int main(){
    using namespace std;
    char ch;
    ifstream fin;
    fin.open(file);
    if(fin.is_open()){
        cout<<"Here are the current contents of the "<<file<<" file:"<<endl;
        while(fin.get(ch)){
            cout<<ch;
        }
        fin.close();
    }

    ofstream fout(file,ios::out|ios::app);
    if(!fout.is_open()){
        cerr<<"Can't open "<<file<<" file for output."<<endl;
        exit(EXIT_FAILURE);
    }

    cout<<"Enter guest name (enter a blank line to quit):"<<endl;
    string name;
    while(getline(cin,name)&&name.size()>0){
        fout<<name<<endl;
    }
    fin.close();

    fin.clear();
    fin.open(file);
    if(fin.is_open()){
        cout<<"Here are the new contents of the "<<file<<" file:"<<endl;
        while(fin.get(ch)){
            cout<<ch;
        }
        fin.close();
    }
    cout<<"Done."<<endl;

    return 0;
}