#include<iostream>
#include"dma.h"

int main(){
    using std::cout;
    using std::endl;

    baseDMA shirt("Portabelly",8);
    lacksDMA ballon("red","Blipmo",4);
    hasDMA map("Mercator","Buffalo keys",5);
    cout<<"Displaying baseDMA object:"<<endl;
    cout<<shirt<<endl;
    cout<<"Displaying lacksDMA object:"<<endl;
    cout<<ballon<<endl;
    cout<<"Displaying hasDMA object:"<<endl;
    cout<<map<<endl;

    lacksDMA ballon2(ballon);
    cout<<"Result of lacksDMA copy:"<<endl;
    cout<<ballon2<<endl;

    hasDMA map2(map);
    map2=map;
    cout<<"Result of hasDMA assignment:"<<endl;
    cout<<map2<<endl;
    
    return 0;
}