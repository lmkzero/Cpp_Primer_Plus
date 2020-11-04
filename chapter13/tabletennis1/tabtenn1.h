#ifndef TABTENN1_H_
#define TABTENN1_H_

#include<string>
using std::string;

class TableTennisPlayer{
private:
    string firstname;
    string lastname;
    bool hastable;
public:
    TableTennisPlayer(const string &fn="none",const string &ln="none",bool ht=false);
    void name() const;
    bool hasTable() const;
    void resetTable(bool v);
};

class RatedPlayer:public TableTennisPlayer{
private:
    unsigned int rating;
public:
    RatedPlayer(unsigned int r=0,const string &fn="none",
        const string &ln="none",bool ht=false);
    RatedPlayer(unsigned int r,const TableTennisPlayer &tp);
    unsigned int rat() const;
    void resetRating(unsigned int r);
};

#endif