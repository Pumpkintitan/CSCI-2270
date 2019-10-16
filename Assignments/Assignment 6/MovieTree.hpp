#include <string>

using namespace std;

struct MovieNode{
    int ranking;
    string title;
    int year;
    float rating;

    MovieNode* left = NULL;
    MovieNode* right = NULL;

    MovieNode(int rank, string t, int y, float r) {
        title = t;
        ranking = rank;
        year = y;
        rating = r;
    }

};


class MovieTree{
    private:
        MovieNode* root;


    public:
        
        MovieTree();

        ~MovieTree();

        void printMovieInventory();

        void addMovieNode(int ranking, std::string title, int year, float rating);

        void findMovie(std::string title);

        void queryMovies(float rating, int year);

        void averageRating();
};
