#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

struct Review{
    std::string title;
    int rating;
};

bool FillReview(Review &rr){
    std::cout<<"Enter book title (quit to quit):";
    std::getline(std::cin,rr.title);
    if(rr.title=="quit"){
        return false;
    }
    std::cout<<"Enter book rating:";
    std::cin>>rr.rating;
    if(!std::cin){
        return false;
    }
    while (std::cin.get()!='\n'){
        continue;
    }
    return true;
}

void ShowReview(const Review &rr){
    std::cout<<rr.rating<<'\t'<<rr.title<<std::endl;
}

bool worseThan(const Review &r1,const Review &r2){
    if(r1.rating<r2.rating){
        return true;
    }else{
        return false;
    }
}

bool operator<(const Review &r1,const Review &r2){
    if(r1.title<r2.title){
        return true;
    }else if(r1.title==r2.title&&r1.rating<r2.rating){
        return true;
    }else{
        return false;
    }
}

int main(){
    using namespace std;

    vector<Review> books;
    Review tmp;
    while(FillReview(tmp)){
        books.push_back(tmp);
    }
    int num=books.size();
    if(num>0){
        cout<<"Thank you. You entered the following:"<<std::endl;
        for_each(books.begin(),books.end(),ShowReview;

        sort(books.begin(),books.end());
        cout<<"Sorted by the title:"<<end;
        for_each(books.begin(),books.end(),ShowReview);

        sort(books.begin(),books.end(),worseThan);
        cout<<"Sorted by title"<<endl;
        for_each(books.begin(),books.end(),ShowReview);

        random_shuffle(books.begin(),books.end());
        cout<<"After shuffling:"<<endl;
        for_each(books.begin(),books.end(),ShowReview);
    }else{
        cout<<"Nothing entered, nothing gained."<<std::endl;
    }

    return 0;
}