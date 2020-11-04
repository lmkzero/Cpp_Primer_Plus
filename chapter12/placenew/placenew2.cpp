#include<iostream>
#include<string>

using namespace std;

const int BUF=512;
class JustTesting{
private:
    string words;
    int number;
public:
    JustTesting(const string &s="Just Testing",int n=0){
        words=s;
        number=n;
        cout<<words<<" constructed"<<endl;
    }
    ~JustTesting(){
        cout<<words<<" destroyed"<<endl;
    }
    void show() const{
        cout<<words<<", "<<number<<endl;
    }
};

int main(){
    char *buffer=new char[BUF];
    JustTesting *pc1,*pc2;
    pc1=new (buffer)JustTesting;
    pc2=new JustTesting("Heap1",20);
    cout<<"Memory block addresses:"<<endl;
    cout<<"buffer:"<<(void*)buffer<<" heap:"<<pc2<<endl;
    cout<<"Memory contents:"<<endl;
    pc1->show();
    pc2->show();

    JustTesting *pc3,*pc4;
    // 偏移量
    pc3=new (buffer+sizeof(JustTesting))JustTesting("Better Idea",6);
    pc4=new JustTesting("Heap2",10);
    cout<<"Memory contents:"<<endl;
    pc3->show();
    pc4->show();

    delete pc2;
    delete pc4;
    
    // 显式析构
    pc3->~JustTesting();
    pc4->~JustTesting();
    delete[] buffer;
    
    return 0;
}