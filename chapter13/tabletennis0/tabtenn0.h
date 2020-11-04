#ifndef TABTENN0_H_
#define TABTENN0_H_

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

#endif