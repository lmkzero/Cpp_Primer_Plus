#include<iostream>
#include<vector>
#include<string>

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

int main(){
    using std::cout;
    using std::vector;

    vector<Review> books;
    Review tmp;
    while(FillReview(tmp)){
        books.push_back(tmp);
    }
    int num=books.size();
    if(num>0){
        cout<<"Thank you. You entered the following:"<<std::endl;
        for(int i=0;i<num;i++){
            ShowReview(books[i]);
        }
        cout<<"Reprising:"<<std::endl;
        vector<Review>::iterator pr;
        for(pr=books.begin();pr!=books.end();pr++){
            ShowReview(*pr);
        }
        vector<Review> oldlist(books);
        if(num>3){
            books.erase(books.begin()+1,books.begin()+3);
            cout<<"After erasure:"<<std::endl;
            for(pr=books.begin();pr!=books.end();pr++){
                ShowReview(*pr);
            }
            books.insert(books.begin(),oldlist.begin()+1,oldlist.begin()+2);
            cout<<"After insertion:"<<std::endl;
            for (pr=books.begin();pr!=books.end(); pr++){
                ShowReview(*pr);
            }
        }
    }else{
        cout<<"Nothing entered, nothing gained."<<std::endl;
    }

    return 0;
}