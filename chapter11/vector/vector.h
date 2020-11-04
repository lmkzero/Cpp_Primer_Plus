#ifndef VECTOR_H_
#define VECTOR_H_

#include<iostream>

namespace VECTOR{
    class Vector{
    public:
        enum Mode{RECT,POL};
    private:
        double x;
        double y;
        double mag;
        double ang;
        Mode mode;
        void set_mag();
        void set_ang();
        void set_x();
        void set_y();
    public:
        Vector();
        Vector(double n1,double n2,Mode mode=RECT);
        void reset(double n1,double n2,Mode mode=RECT);
        ~Vector(){};

        double get_x() const;
        double get_y() const;
        double get_mag() const;
        double get_ang() const;
        void setrect();
        void setpolar();

        Vector operator+ (const Vector &v) const;
        Vector operator- (const Vector &v) const;
        Vector operator- () const;
        Vector operator* (double n) const;

        friend Vector operator* (double n,const Vector &v);
        friend std::ostream & operator<< (std::ostream &os,const Vector &v);
    };
}

#endif