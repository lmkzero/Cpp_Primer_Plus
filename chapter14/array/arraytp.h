#ifndef ARRAY_H_
#define ARRAY_H_

#include<iostream>
#include<cstdlib>

// 表达式参数可以是整型、枚举、引用、指针
// 实例化模板时，表达式的值必须是常量表达式
template<typename T,int n>
class ArrayTP{
private:
    T arr[n];
public:
    ArrayTP(){}
    explicit ArrayTP(const T &v);
    virtual T& operator[](int i);
    virtual T operator[](int i) const;
};

template<typename T,int n>
ArrayTP<T,n>::ArrayTP(const T &v){
    for(int i=0;i<n;i++){
        arr[i]=v;
    }
}

template<typename T,int n>
T& ArrayTP<T,n>::operator[](int i){
    if(i<0||i>=n){
        std::cerr<<"Error in array limits: out of range"<<std::endl;
        std::exit(EXIT_FAILURE);
    }
    return arr[i];
}

template<typename T,int n>
T ArrayTP<T,n>::operator[](int i) const{
    if(i<0||i>=n){
        std::cerr<<"Error in array limits: out of range"<<std::endl;
        std::exit(EXIT_FAILURE);
    }
    return arr[i];
}

#endif