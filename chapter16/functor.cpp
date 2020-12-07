#include<iostream>
#include<list>
#include<iterator>
#include<algorithm>

template<typename T>
class TooBig{
private:
    T cutoff;
public:
    TooBig(const T &t):cutoff(t){}
    bool operator()(const T &v){
        return v>cutoff;
    }
};

void outint(int n){
    std::cout<<n<<"\t";
}

int main(){
    using std::list;
    using std::cout;
    using std::endl;

    TooBig<int> f100(100);
    int vals[10]={50,100,90,180,60,210,415,88,188,201};
    list<int> yadayada(vals,vals+10);
    list<int> etcetera(vals,vals+10);

    cout<<"Original list:"<<endl;
    for_each(yadayada.begin(),yadayada.end(),outint);
    cout<<endl;

    for_each(etcetera.begin(),etcetera.end(),outint);
    cout<<endl;

    // named function object
    yadayada.remove_if(f100);
    // construct a function object
    etcetera.remove_if(TooBig<int>(200));

    cout<<"Trimmed list:"<<endl;
    for_each(yadayada.begin(),yadayada.end(),outint);
    cout<<endl;
    for_each(etcetera.begin(),etcetera.end(),outint);
    cout<<endl;

    return 0;
}