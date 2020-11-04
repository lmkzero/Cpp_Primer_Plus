#include<iostream>
#include"tabtenn0.h"

TableTennisPlayer::TableTennisPlayer(const string &fn,const string &ln,bool ht){
    firstname=fn;
    lastname=ln;
    hastable=ht;
}

void TableTennisPlayer::name() const{
    std::cout<<lastname<<" "<<firstname<<std::endl;
}

bool TableTennisPlayer::hasTable() const{
    return hasTable;
}

void TableTennisPlayer::resetTable(bool v){
    hastable=v;
}