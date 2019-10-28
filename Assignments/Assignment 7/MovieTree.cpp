#include "MovieTree.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

void insertTreeNode(TreeNode* temp, TreeNode* parent) {
  if (temp->titleChar < parent->titleChar && parent->leftChild == NULL) {
    parent->leftChild = temp;
  } else if (temp->titleChar < parent->titleChar && parent->leftChild != NULL) {
    insertTreeNode(temp, parent->leftChild);
  }

  if (temp->titleChar > parent->titleChar && parent->rightChild == NULL) {
    parent->rightChild = temp;
  } else if (temp->titleChar > parent->titleChar && parent->rightChild != NULL) {
    insertTreeNode(temp, parent->rightChild);
  }
}

TreeNode* searchHelper(char titleChar, TreeNode* temp) {
  if (temp->titleChar == titleChar) {
    return temp;
  } else {
    if (temp->titleChar < titleChar) {
      return searchHelper(titleChar, temp->rightChild);
    }
    if (temp->titleChar > titleChar) {
      return searchHelper(titleChar, temp->leftChild);
    }
  }
}

TreeNode* searchNode(char titleChar, TreeNode* root) {
  TreeNode* temp = searchHelper(titleChar, root);
  if (temp->titleChar == titleChar) {
    return temp;
  } else {
    return NULL;
  }
}

void printBST(TreeNode* parent) {
  if (parent->leftChild != NULL) {
    cout << "Left" << endl;
    printBST(parent->leftChild);
    cout << "Back" << endl;
  }
  cout << "Movies starting with letter: " << parent->titleChar << endl;
  LLMovieNode* temp = parent->head;
  while(temp != NULL) {
    cout << " >> " << temp->title << " " << temp->rating << endl;
    temp = temp->next;
  }
  if (parent->rightChild != NULL) {
    cout << "Right" << endl;
    printBST(parent->rightChild);
    cout << "Back" << endl;
  }
}

void insertIntoLL(TreeNode* temp, LLMovieNode* movie) {
  if (temp->head == NULL) {
    temp->head = movie;
  } else {
    LLMovieNode* crawler = temp->head;
    LLMovieNode* prev = crawler;
    bool added = false;
    while(crawler != NULL && !added) {
      added = false;
      if (movie->title < temp->head->title) {
        movie->next = temp->head;
        temp->head = movie;
        added = true;
      }
      if (movie->title > prev->title && movie->title < crawler->title) {
        movie->next = crawler;
        prev->next = movie;
        added = true;
      }
      prev = crawler;
      crawler = crawler->next;
      if (crawler == NULL && !added) {
        movie->next = crawler;
        prev->next = movie;
        added = true;
      }
    }
  }
}

TreeNode* getMaxValueNode(TreeNode* currNode){
    if(currNode->rightChild == NULL){
        return currNode;
    }
    return getMaxValueNode(currNode->rightChild);
}

TreeNode* getMinValueNode(TreeNode* currNode){

    if(currNode->leftChild == NULL){
      return currNode;
    }
    return getMinValueNode(currNode->leftChild);
}

TreeNode* findHelper(TreeNode* tempP, TreeNode* temp) {
  if (tempP->titleChar == temp->titleChar) {
    return tempP;
  } else {
    if (tempP->titleChar < temp->titleChar) {
      return findHelper(tempP->rightChild, temp);
    }
    if (tempP->titleChar > temp->titleChar) {
      return findHelper(tempP->leftChild, temp);
    }
  }
}

TreeNode* findParent(TreeNode* temp, TreeNode* root) {
  TreeNode* tempP = findHelper(root, temp);
  if (tempP->rightChild == temp || tempP->leftChild == temp) {
    return temp;
  } else {
    return NULL;
  }
}

void removeNode(TreeNode* temp, TreeNode* root) {
  cout << "Removing Node..." << endl;
  if (temp->rightChild == NULL && temp->leftChild == NULL) {
    cout << "None" << endl;
    TreeNode* tempP = findParent(temp, root);
    cout << tempP->titleChar << endl;
    temp = NULL;
  } else if (temp->rightChild == NULL && temp->leftChild != NULL) {
    cout << "Left" << endl;
    TreeNode* min = getMinValueNode(temp->rightChild);
    temp = min;
    min = NULL;
  } else if (temp->rightChild != NULL && temp->leftChild == NULL) {
    cout << "Right" << endl;
    TreeNode* max = getMaxValueNode(temp->leftChild);
    temp = max;
    max = NULL;
  } else {
    cout << "Both" << endl;
    TreeNode* max = getMaxValueNode(temp->leftChild);
    temp = max;
    max = NULL;
  }
}

void deleteNode(TreeNode* temp) {
  if (temp->leftChild != NULL) {
    deleteNode(temp->leftChild);
  }
  if (temp->rightChild != NULL) {
    deleteNode(temp->rightChild);
  }
  if (temp->head != NULL) {
    LLMovieNode* del = temp->head;
    while (del != NULL) {
      delete del;
      del = del->next;
    }
    temp->head = NULL;
  }
  delete temp;
}

//---------------------------------------------------------------

MovieTree::MovieTree() {
  root = NULL;
}

MovieTree::~MovieTree(){
  deleteNode(root);
  delete root;
}

void MovieTree::printMovieInventory() {
  printBST(root);
}

void MovieTree::addMovie(int ranking, std::string title, int year, float rating) {
  TreeNode* searched = new TreeNode;
  TreeNode* temp = new TreeNode;
  temp->titleChar = title[0];
  if (root == NULL) {
    root = temp;
  }
  if (root != NULL) {
    insertTreeNode(temp, root);
    searched = searchNode(title[0], root);
  }
  if (root != NULL && searched->titleChar == title[0]){
    LLMovieNode* tempL = new LLMovieNode(ranking, title, year, rating);
    insertIntoLL(searched, tempL);
  } else {
    LLMovieNode* tempL = new LLMovieNode(ranking, title, year, rating);
    insertIntoLL(temp, tempL);
  }

}

void MovieTree::deleteMovie(std::string title) {
  TreeNode* searched = new TreeNode;
  searched = searchNode(title[0], root);
  if (searched != NULL) {
  LLMovieNode* crawler = searched->head;
  LLMovieNode* prev = crawler;
  while (crawler != NULL) {
    if (crawler->title == title && crawler == searched->head) {
      if (crawler->next == NULL) {
        delete crawler;
        searched->head = NULL;

        removeNode(searched, root);
      }else {
        searched->head = crawler->next;
        delete crawler;
      }
    } else if (crawler->title == title) {
      prev->next = crawler->next;
      delete crawler;
    } else {
      prev = crawler;
      crawler = crawler->next;
    }
  }
}
}
