#ifndef WORKERMI_H_
#define WORKERMI_H_

#include<string>

class Worker{
private:
    std::string fullname;
    long id;
protected:
    virtual void data() const;
    virtual void get();
public:
    Worker():fullname("no one"),id(0L){}
    Worker(const std::string &s,long n):fullname(s),id(n){}
    virtual ~Worker() =0;
    virtual void set() =0;
    virtual void show() const =0;
};


class Waiter:virtual public Worker{
private:
    int panache;
protected:
    void data() const;
    void get();
public:
    Waiter():Worker(),panache(0){}
    Waiter(const std::string &s,long n,int p=0):Worker(s,n),panache(p){}
    Waiter(const Worker &wk,int p=0):Worker(wk),panache(p){}
    void set();
    void show() const;
};

class Singer:virtual public Worker{
protected:
    enum{other,alto,contralto,soprano,bass,baritone,tenor};
    enum{Vtype=7};
    void data() const;
    void get();
private:
    static char* pv[Vtype];
    int voice;
public:
    Singer():Worker(),voice(other){}
    Singer(const std::string &s,long n,int v=other):Worker(s,n),voice(v){}
    Singer(const Worker &wk,int v=other):Worker(wk),voice(v){}
    void set();
    void show() const;
};


class SingerWaiter:public Singer,public Waiter{
protected:
    void data() const;
    void get();
public:
    SingerWaiter(){}
    SingerWaiter(const std::string &s,long n,int p=0,int v=other):Worker(s,n),Waiter(s,n,p),Singer(s,n,v){}
    SingerWaiter(const Worker &wk,int p=0,int v=other):Worker(wk),Waiter(wk,p),Singer(wk,v){}
    SingerWaiter(const Waiter &wt,int v=other):Worker(wt),Waiter(wt),Singer(wt,v){}
    SingerWaiter(const Singer &wt,int p=0):Worker(wt),Waiter(wt,p),Singer(wt){}
    void set();
    void show() const;
};

#endif