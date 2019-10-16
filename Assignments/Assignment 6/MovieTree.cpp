#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

// MovieNode: node struct that will be stored in the MovieTree BST
void findSpot(MovieNode* temp, MovieNode* parent) {
  if (temp->title <= parent->title && parent->left == NULL) {
    parent->left = temp;
  } else if (temp->title <= parent->title && parent->left != NULL) {
    findSpot(temp, parent->left);
  }

  if (temp->title >= parent->title && parent->right == NULL) {
    parent->right = temp;
  } else if (temp->title >= parent->title && parent->right != NULL) {
    findSpot(temp, parent->right);
  }
}

void printBST(MovieNode* parent) {
  if (parent->left != NULL) {
    printBST(parent->left);
  }
  cout << "Movie: " << parent->title << " " << parent->rating << endl;
  if (parent->right != NULL) {
    printBST(parent->right);
  }
}

void queryBST(MovieNode* parent, float rating, int year) {
  if (parent->rating >= rating && parent->year >= year) {
    cout << parent->title << "(" << parent->year << ") " << parent->rating << endl;
  }
  if (parent->left != NULL) {
    queryBST(parent->left, rating, year);
  }
  if (parent->right != NULL) {
    queryBST(parent->right, rating, year);
  }
}

void aveRate(MovieNode* parent, MovieNode* ave) {
  ave->year++;
  ave->rating += parent->rating;
  if (parent->left != NULL) {
    aveRate(parent->left, ave);
  }
  if (parent->right != NULL) {
    aveRate(parent->right, ave);
  }
}

MovieNode* findNode(MovieNode* root, string title) {
  bool found = false;
  MovieNode* parent = root;
  while (!found) {
    if (title == parent->title) {
      found = true;
      return parent;
    }
    if (parent->left == NULL && parent->right == NULL) {
      found = true;
      return NULL;
    }
    if (parent->title >= title) {
      parent = parent->left;
    } else if (parent->title <= title) {
      parent = parent->right;
    }
  }
  return NULL;
}

MovieTree::MovieTree() {
  root = NULL;
}

MovieTree::~MovieTree() {
  //write your code
}

void MovieTree::printMovieInventory() {
  if (root != NULL) {
    printBST(root);
  } else {
    cout << "Tree is Empty. Cannot print" << endl;
  }
}

void MovieTree::addMovieNode(int ranking, string title, int year, float rating) {
  MovieNode* temp = new MovieNode(ranking, title, year, rating);
  if (root == NULL) {
    root = temp;
  } else {
    findSpot(temp, root);
  }
}

void MovieTree::findMovie(string title) {
  MovieNode* found = findNode(root, title);
  if (found != NULL) {
    cout << "Movie Info:" << endl;
    cout << "==================" << endl;
    cout << "Ranking:" << found->ranking << endl;
    cout << "Title  :" << found->title << endl;
    cout << "Year   :" << found->year << endl;
    cout << "rating :" << found->rating << endl;
  } else {
    cout << "Movie not found." << endl;
  }
}

void MovieTree::queryMovies(float rating, int year) {
  cout << "Movies that came out after " << year << " with rating at least " << rating << ":" << endl;
  queryBST(root, rating, year);
}

void MovieTree::averageRating() {
  if (root != NULL) {
    float average = 0.0;
    MovieNode* ave = new MovieNode(0,"",0,0);
    aveRate(root, ave);
    average = ave->rating / ave->year;
    cout << "Average rating:" << average << endl;
  } else {
    cout << "Average rating:0.0" << endl;
  }
}
