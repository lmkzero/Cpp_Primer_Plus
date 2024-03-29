#include<iostream>
#include<cctype>
#include "stack.h"

using namespace std;

int main(){
    Stack st;
    char ch;
    unsigned long po;
    cout<<"Please enter A to add a purchase order,\n";
    cout<<"P to process a PO, or Q to quit."<<endl;
    while (cin>>ch&&toupper(ch)!='Q'){
        while (cin.get()!='\n'){
            continue;
        }
        if(!isalpha(ch)){
            cout<<'\a';
            continue;
        }
        switch (ch){
            case 'A':
            case 'a':
                cout<<"Enter a PO number to add:";
                cin>>po;
                if(st.isfull()){
                    cout<<"Stack is full"<<endl;
                }else{
                    st.push(po);
                }
                break;
            case 'p':
            case 'P':
                if(st.isempty()){
                    cout<<"Stack already empty"<<endl;
                }else{
                    st.pop(po);
                    cout<<"PO #"<<po<<" popped"<<endl;
                }
            default:
                break;
        }
        cout<<"Please enter A to add a purchase order,\n";
        cout<<"P to process a PO, or Q to quit."<<endl;
    }
    return 0;
}