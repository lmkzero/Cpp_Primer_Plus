#include<cmath>
#include "vector.h"

namespace VECTOR{
    const double Rad_to_deg=45.0/std::atan(1.0);

    void Vector::set_mag(){
        mag=std::sqrt(x*x+y*y);
    }

    void Vector::set_ang(){
        if(x==0.0&&y==0.0){
            ang=0.0;
        }else{
            ang=std::atan2(y,x);
        }
    }

    void Vector::set_x(){
        x=mag*std::cos(ang);
    }

    void Vector::set_y(){
        y=mag*std::sin(ang);
    }

    Vector::Vector(){
        x=y=mag=ang=0.0;
        mode=RECT;
    }

    Vector::Vector(double n1,double n2,Mode mode){
        (*this).mode=mode;
        if(mode==RECT){
            x=n1;
            y=n2;
            set_mag();
            set_ang();
        }else if(mode==POL){
            mag=n1;
            ang=n2;
            set_x();
            set_y();
        }else{
            std::cout<<"Incorrect Mode"<<std::endl;
            x=y=mag=ang=0.0;
            (*this).mode=RECT;
        }
    }

    void Vector::reset(double n1,double n2,Mode mode){
        (*this).mode=mode;
        if(mode==RECT){
            x=n1;
            y=n2;
            set_mag();
            set_ang();
        }else if(mode==POL){
            mag=n1;
            ang=n2;
            set_x();
            set_y();
        }else{
            std::cout<<"Incorrect Mode"<<std::endl;
            x=y=mag=ang=0.0;
            (*this).mode=RECT;
        }
    }

    void Vector::setpolar(){
        mode=POL;
    }

    void Vector::setrect(){
        mode=RECT;
    }

    Vector Vector::operator+ (const Vector &v) const{
        return Vector(x+v.x,y+v.y);
    }

    Vector Vector::operator- (const Vector &v) const{
        return Vector(x-v.x,y-v.y);
    }

    Vector Vector::operator- () const{
        return Vector(-x,-y);
    }

    Vector Vector::operator* (double n) const{
        return Vector(n*x,n*y);
    }

    Vector operator* (double n,const Vector &v){
        return v*n;
    }

    std::ostream & operator<<(std::ostream &os,const Vector &v){
        if(v.mode==Vector::RECT){
            os<<"(x,y)=("<<v.x<<","<<v.y<<")"<<std::endl;
        }else if(v.mode==Vector::POL){
            os<<"(m,a)=("<<v.mag<<","<<v.ang<<")"<<std::endl;
        }else{
            os<<"Mode of vector is invalid"<<std::endl;
        }
    }
}
