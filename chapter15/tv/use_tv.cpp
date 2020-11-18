#include<iostream>
#include"tv.h"

int main()
{   
    using std::cout;
    Tv s42;
    cout<<"Initial settings for 42"<<std::endl;
    s42.settings();
    s42.onoff();
    s42.chanup();
    cout<<std::endl<<"Adjusted settings for 42"<<std::endl;
    s42.chanup();
    cout<<std::endl<<"Adjusted settings for 42"<<std::endl;
    s42.settings();

    Remote grey;
    grey.set_chan(s42,10);
    grey.volup(s42);
    grey.volup(s42);
    cout<<std::endl<<"Settings after remote for 42"<<std::endl;
    s42.settings();

    Tv s58(Tv::On);
    s58.set_mode();
    grey.set_chan(s58,28);
    cout<<std::endl<<"s58 settings"<<std::endl;
    s58.settings();

    return 0;
}
