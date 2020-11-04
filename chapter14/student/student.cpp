#include "studentc.h"

using std::ostream;
using std::istream;
using std::string;
using std::endl;

double Student::avgerage() const{
    if(scores.size()>0){
        return scores.sum()/scores.size();
    }else{
        return 0;
    }
}

const string& Student::get_name() const{
    return name;
}

double & Student::operator[](int n){
    return scores[n];
}

double Student::operator[](int n) const{
    return scores[n];
}

ostream& Student::arr_out(ostream &os) const{
    int i;
    int lim=scores.size();
    if(lim>0){
        for(i=0;i<lim;i++){
            os<<scores[i]<<" ";
            if(i%5==4){
                os<<endl;
            }
        }
        if(i%5!=0){
            os<<endl;
        }
    }else{
        os<<"empty array"<<endl;
    }
    return os;
}

istream& operator>>(istream &is,Student &stu){
    is>>stu.name;
    return is;
}

istream& getline(istream &is,Student &stu){
    getline(is,stu.name);
    return is;
}

ostream& operator<<(ostream &os,const Student &stu){
    os<<"Scores for "<<stu.name<<":"<<endl;
    stu.arr_out(os);
    return os;
}