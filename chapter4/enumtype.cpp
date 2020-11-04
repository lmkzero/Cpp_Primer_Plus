#include<iostream>
using namespace std;

int main(){
    // 对应0~7
    // 枚举量是整型,可被提升为int类型,但是int类型不能自动转换为枚举类型
    enum spectrum {red,orange,yellow,green,blue,violet,indigo,ultraviolet};
    int color=blue;
    // 非法
    // spectrum band=3;

    // 显式设置枚举量的值
    enum bits{one=1,two=2,four=4,eight=8};
    // first=0,third=101
    enum bigstep{first,second=100,third};

    // 取值范围
    // 比最大值大的2的幂
    // 0或者比最小值小的2的幂(负号)
    bits myflags=bits(6);    // 合法
    return 0;
}