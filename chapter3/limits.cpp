#include<iostream>
#include<limits>
// #include<climits>

using namespace std;

int main(){
    cout<<sizeof(short)<<endl;  // 2
    cout<<sizeof(int)<<endl;    // 4
    cout<<sizeof(long)<<endl;   // 8
    cout<<sizeof(long long)<<endl;  //8

    long long llong=INT64_MAX;
    // cout<<sizeof llong<<endl;
    cout<<sizeof(llong)<<endl;

    return 0;
}