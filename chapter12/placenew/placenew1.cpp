#include<iostream>
#include<string>
// #include<new>

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
    pc3=new (buffer)JustTesting("Bad Idea",6);  // 覆盖了pc1的内存单元
    pc4=new JustTesting("Heap2",10);
    cout<<"Memory contents:"<<endl;
    pc3->show();
    pc4->show();

    delete pc2;
    delete pc4;
    delete[] buffer;    // 不能自动调用pc1，pc3的析构函数，虽然空间已经释放，但是对象未被显式析构

    return 0;
}