// COMSC-210 | Lab 19 | Shuhaib Walahi

#include <iostream>

using namespace std;

// struct for movie review nodes
struct ReviewNode
{
    float rating;
    string comments;
    ReviewNode* next;
};

// class for movie
class Movie
{
    private:
        string title;
        // pointer to head of reviews linked list
        ReviewNode* reviewsHead; 
    public:
        // constructor to initialize a movie object with a title
        Movie(const string& t) : title(t), reviewsHead(nullptr) {}
        // destructor
        
};

int main
{
    return 0;
}