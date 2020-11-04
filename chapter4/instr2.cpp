#include<iostream>
using namespace std;

// getline()
// 通过回车键输入的换行符确定输入结尾
// 取一行输入，丢弃换行符
// 第一个参数：数组名称，第二个参数：字符数（实际能存储字符数=size-1）
void instr1(){
    const int size=20;
    char name[size];
    char dessert[size];
    cout<<"Enter your name:"<<endl;
    cin.getline(name,size);
    cout<<"Enter your favorite dessert:"<<endl;
    cin.getline(dessert,size);
    cout<<"I have some "<<dessert<<endl;
}

// get()
// 通过回车键输入的换行符确定输入结尾
// 取一行输入，不丢弃换行符
// 函数参数相同
// 连续调用get()函数时，第二个函数看到的第一个字符就是换行符，认为已达到行尾
// 使用不带参数的cin.get()处理换行符
// 拼接方式：cin.get(name,size)返回的是cin对象，可用来再次调用
void instr2(){
    const int size=20;
    char name[size];
    char dessert[size];
    cout<<"Enter your name:"<<endl;
    cin.get(name,size).get();
    cout<<"Enter your favorite dessert:"<<endl;
    cin.get(dessert,size);
    cout<<"I have some "<<dessert<<endl;
}

// 空行问题
// 输入字符串比分配的空间长

int main(){
    instr1();
    instr2();
    return 0;
}