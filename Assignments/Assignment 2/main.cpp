#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
using namespace std;

struct wordItem {
  string word;
  int count;
};

void getStopWords(const char *ignoreWordFileName, string ignoreWords[]) {
  ifstream iwords(ignoreWordFileName);
  if (iwords.fail()) {
    cout << "Failed to open " << ignoreWordFileName << endl;
  }
  string temp;
  for (int i = 0; i < 50; i++) {
    getline(iwords, temp);
    ignoreWords[i] = temp;
  }
}

bool isStopWord(string word, string ignoreWords[]) {
  for (int i = 0; i < 50; i++) {
    if (word == ignoreWords[i]) {
      return true;
    }
  }
  return false;
}

int getTotalNumberNonStopWords(wordItem uniqueWords[], int length) {
  int total = 0;
  for (int i = 0; i < length; i++) {
    total = total + uniqueWords[i].count;
  }
  return total;
}

void arraySort(wordItem uniqueWords[], int length) {
  wordItem temp;
  for (int i = 0; i < length; i++) {
    for (int j = 0; j < length; j++) {
      if (uniqueWords[i].count > uniqueWords[j].count) {
        temp = uniqueWords[j];
        uniqueWords[j] = uniqueWords[i];
        uniqueWords[i] = temp;
      }
    }
  }
}

void printNext10(wordItem uniqueWords[], int N, int totalNumWords) {
  for (int i = N; i < N+10; i++) {
    cout << fixed << setprecision(4) << round(10000*((float) uniqueWords[i].count/totalNumWords))/10000 << " - " << uniqueWords[i].word << endl;
  }
}

void doubleArr(wordItem*& inArr, int& N){
  wordItem* temp = new wordItem[2*N];
  for (int i = 0; i < N; i++) {
    temp[i] = inArr[i];
  }
  delete [] inArr;
  inArr = temp;
  N = 2*N;
}

int main(int argc, char const *argv[]) {
  if (argc != 4) {
    cout << "Usage: Assignment2Solution <number of words> <inputfilename.txt> <ignoreWordsfilename.txt>" << endl;
    return -1;
  }
  int length = 100;
  int uwordcount = 1;
  int doubled = 0;
  string ignoreWords[50];
  getStopWords(argv[3],ignoreWords);
  wordItem *uniqueWords;
  uniqueWords = new wordItem[length];
  int index = stoi(argv[1]);
  ifstream tsawyer(argv[2]);
  string temp;
  while(tsawyer.good()) {
    bool added = false;
    tsawyer >> temp;
    if (!isStopWord(temp, ignoreWords)) {
      for (int i = 0; i < uwordcount; i++) {
        if (temp == uniqueWords[i].word && !added) {
          uniqueWords[i].count++;
          added = true;
        } else if (i == uwordcount -1 && !added) {
          uniqueWords[i].word = temp;
          uniqueWords[i].count = 1;
          added = true;
          uwordcount++;
          //cout << uniqueWords[i].word << "-" << uniqueWords[i].count << endl;
          i++;
        }
      }
      if (uwordcount == length) {
        doubleArr(uniqueWords, length);
        doubled++;
      }
    }
  }
  int ctotal = getTotalNumberNonStopWords(uniqueWords, uwordcount);
  cout << "Array doubled: " << doubled << endl << "#"<< endl << "Unique non-common words: " << uwordcount-1 << endl << "#"<< endl << "Total non-common words: " << ctotal << endl;
  arraySort(uniqueWords, length);
  cout << "#" << endl;
  cout << "Probability of next 10 words from rank " << stoi(argv[1]) << endl;
  cout << "---------------------------------------" << endl;
  printNext10(uniqueWords, stoi(argv[1]), ctotal);

  return 0;
}
