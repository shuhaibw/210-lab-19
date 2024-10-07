// COMSC-210 | Lab 19 | Shuhaib Walahi

#include <iostream>
#include <cstdlib> 
#include <ctime>
#include <vector>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// struct for movie review nodes
struct ReviewNode
{
    float rating;
    string comments;
    ReviewNode* next;
};

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
        
        // method to display all reviews
        void displayReviews() const
        {
            if (!reviewsHead) // check if the list is empty
            {
                cout << "    > No reviews for " << title << "." << endl;
                return;
            }

            // temp pointer to traverse the linked list
            ReviewNode* temp = reviewsHead; 
            int count = 1; 

            // loop to traverse through and output reviews
            while (temp)
            {
                cout << "    > Review #" << count << ": " << fixed 
                << setprecision(1) << temp->rating << ": " 
                << temp->comments << endl;
                temp = temp->next; // move to next review
                count++; // increment review count
            }
    }

        // getter for the title of the movie
        string getTitle() const { return title; }
};

// function prototypes
vector<Movie> loadMovies(const string& file);

int main()
{
    // start random number generator
    srand(static_cast<unsigned int>(time(0))); 

    // load movies from the input file
    vector<Movie> movies = loadMovies("../input.txt"); 

    // loop to go through each movie and display reviews
    for (const auto& movie : movies)
    {
        cout << "Movie: " << movie.getTitle() << endl; 
        movie.displayReviews(); 
        cout << endl; 
    }

    return 0;
}

/*
    loadMovies() reads movie titles and their corresponding reviews from a file
    arguments: 
    const string& filename: The name of the file containing movie titles and reviews
    returns:
    vector<Movie>: A vector of Movie objects populated with titles and reviews
*/
vector<Movie> loadMovies(const string& file)
{
    vector<Movie> movies; 
    ifstream fin(file); 

    // if file is no good
    if (!fin.good()) 
    {
        cout << "Error: unable to open file." << endl;
        return movies; 
    }

    string title; 

    // read title from file
    while (getline(fin, title)) 
    {
        // create a Movie object
        Movie movie(title); 
        string comment; 
        // read comments until empty line
        while (getline(fin, comment) && !comment.empty()) 
        {
            // add review to movie
            movie.addReview(comment); 
        }
        // add movie to vector
        movies.push_back(movie); 
    }
    fin.close(); 
    return movies; 
}