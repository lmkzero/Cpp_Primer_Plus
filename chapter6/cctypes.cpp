#include<iostream>
#include<cctype>
using namespace std;

int main(){
    cout<<"Enter text:"<<endl;
    char ch;
    int whitespace=0,digits=0,chars=0,punct=0,others=0;
    cin.get(ch);
    while(ch!='@'){
        if(isalpha(ch)){    // 参数是字母，返回true
            chars++;
        }else if(isspace(ch)){  // 参数是标准空白字符（空格、换行符、回车、制表符），返回true
            whitespace++;
        }else if(isdigit(ch)){  // 参数是数字（0~9），返回true
            digits++;
        }else if(ispunct(ch)){  // 参数是标点符号，返回true
            punct++;
        }else{
            others++;
        }
        cin.get(ch);
    }
    // isalnum()    // 参数是字母数字，返回true
    // isgraph()   // 参数是除空格之外的打印字符，返回true
    // isprint()   // 参数是打印字符（包括空格），返回true
    // islower()   // 参数是小写字母，返回true
    // isupper()   // 参数是大写字母，返回true
    // tolower()   // 参数是大写字母，则返回其小写
    // toupper()   // 参数是小写字母，则返回其大写
    return 0;
}