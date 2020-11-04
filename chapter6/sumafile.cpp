#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

const int size=60;

int main(){
    char filename[size];
    ifstream inFile;
    cout<<"Enter name of data file"<<endl;
    cin.getline(filename,size);
    inFile.open(filename);
    if(!inFile.is_open()){
        cout<<"could not open the file"<<endl;
        exit(EXIT_FAILURE);
    }

    // scores.text末尾需要添加换行符
    double value;
    double sum=0.0;
    int count=0;
    inFile>>value;
    while(inFile.good()){
        ++count;
        sum+=value;
        inFile>>value;
    }
    if(inFile.eof()){
        cout<<"End of file reached"<<endl;
    }else if(inFile.fail()){
        cout<<"Input terminated by data mismatch"<<endl;
    }else{
        cout<<"Input terminated for unknown reason"<<endl;
    }
    if(count==0){
        cout<<"No data processed"<<endl;
    }else{
        cout<<"Item read:"<<count<<endl;
        cout<<"Sum:"<<sum<<endl;
        cout<<"Average:"<<sum/count<<endl;
    }
    inFile.close(); 
    return 0;
}