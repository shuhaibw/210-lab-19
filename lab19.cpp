// COMSC-210 | Lab 19 | Shuhaib Walahi

#include <iostream>
#include <cstdlib> 

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

        // destructor to clean up the linked list of reviews
        ~Movie() 
        {
            // pointer to the current review node
            ReviewNode* current = reviewsHead; 
            // loop to delete all reviews
            while (current) 
            {
                ReviewNode* toDelete = current; 
                current = current->next;         
                delete toDelete;                 
            }
        }   

        // method to add a review with a random rating
        void addReview(const string& comment)
        {
            // create a new review node
            ReviewNode* newNode = new ReviewNode();
            // random rating from 1.0 to 5.0
            newNode->rating = static_cast<float>(rand() % 41 + 10) / 10.0; 
            newNode->comments = comment; 
            // make new node point to current head
            newNode->next = reviewsHead;
            // assign head to point to new node  
            reviewsHead = newNode;        
        }
        
};

int main
{
    // start random number generator
    srand(static_cast<unsigned int>(time(0))); 

    // load movies from the input file
    vector<Movie> movies = loadMovies("../input.txt"); 

    return 0;
}