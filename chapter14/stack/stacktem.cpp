#include<iostream>
#include<string>
#include<cctype>
#include"stacktp.h"

using std::cin;
using std::cout;

int main(){
    Stack<std::string> st;
    char ch;
    std::string po;
    cout<<"Please enter A to add a purchase order,\n"<<"P to process a PO, or Q to quit..\n";
    while(cin>>ch&&std::toupper(ch)!='Q'){
        while(cin.get()!='\n'){
            continue;
        }
        if(!std::isalpha(ch)){
            cout<<'\a';
            continue;
        }
        switch(ch){
            case 'A':
            case 'a':
                cout<<"Enter a PO number to add:";
                cin>>po;
                if(st.isfull()){
                    cout<<"Stack is already full"<<std::endl;
                }else{
                    st.push(po);
                }
                break;
            case 'P':
            case 'p':
                if(st.isempty()){
                    cout<<"Stack is empty"<<std::endl;
                }else{
                    st.pop(po);
                    cout<<"PO #"<<po<<" popped"<<std::endl;
                }
                break;
        }
        cout<<"Please enter A to add a purchase order,\n"<<"P to process a PO, or Q to quit..\n";
    }

    return 0;
}