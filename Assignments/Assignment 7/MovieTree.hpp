/****************************************************************/
/*                  MovieTree Definition                   */
/****************************************************************/
/* LEAVE THIS FILE AS IS! DO NOT MODIFY ANYTHING! =]            */
/****************************************************************/

#ifndef MOVIETREE_HPP
#define MOVIETREE_HPP

#include <string>

/* Linked List node structure that will be stored at each node in the BST*/
struct LLMovieNode
{
  int ranking;                // Rank of the movie
  std::string title;          // Title of the movie
  int year;                   // Release year
  float rating;               // Movies rating
  struct LLMovieNode* next;   // Pointer to the next node

  LLMovieNode(){} // default constructor

  // Parametrized constructor
  LLMovieNode(int r, std::string t, int y, float q) : ranking(r), title(t),
    year(y), rating(q), next(NULL) {}
};

/* Node struct that will be stored in the MovieTree BST */

struct TreeNode
{
  LLMovieNode* head = NULL;    // Pointer to the head node of a LL
  char titleChar;              // Starting character of the titles stored in the linked list
  TreeNode *parent = NULL;     // Pointer to its parent node in BST
  TreeNode *leftChild = NULL;  // Pointer to its leftChild in BST
  TreeNode *rightChild = NULL; // Pointer to its rightChild in BST
};

/* Class for storing and manipulating the TreeNode's of BST*/

class MovieTree
{
    public:
      // Check writeup for detailed function descriptions
      MovieTree();
      ~MovieTree();
      void printMovieInventory();
      void addMovie(int ranking, std::string title, int year, float rating);
      void deleteMovie(std::string title);

    private:
      TreeNode *root;
};

#endif
