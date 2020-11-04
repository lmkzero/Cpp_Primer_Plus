#include<iostream>
#include"tabtenn1.h"

TableTennisPlayer::TableTennisPlayer(const string &fn,const string &ln,bool ht){
    firstname=fn;
    lastname=ln;
    hastable=ht;
}

void TableTennisPlayer::name() const{
    std::cout<<firstname<<" "<<lastname<<std::endl;
}

bool TableTennisPlayer::hasTable() const{
    return hastable;
}

void TableTennisPlayer::resetTable(bool v){
    hastable=v;
}

RatedPlayer::RatedPlayer(unsigned int r,const string &fn,const string &ln,bool ht):TableTennisPlayer(fn,ln,ht){
    rating=r;
}

RatedPlayer::RatedPlayer(unsigned int r,const TableTennisPlayer &tp):TableTennisPlayer(tp){
    rating=r;
}

unsigned int RatedPlayer::rat() const{
    return rating;
}

void RatedPlayer::resetRating(unsigned int r){
    rating=r;
}