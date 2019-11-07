// Driver program
#include<iostream>
#include "hash.hpp"
using namespace std;

// GOLD TODO Complete this function
void printPairs(int* arr, int size, int sum, HashTable ht){

  bool pairFound = false;
  for (int i = 0; i < size; i++) {
    int tempKey = ht.searchItem(sum-arr[i])->key;
    if (tempKey + arr[i] == 19) {
      cout << tempKey << " + " << arr[i] << " = " << sum << endl;
      pairFound = true;
    } else {
      cout << tempKey << " + " << arr[i] << " != " << sum << endl;
    }

  }
  //TODO :
  // iterate over each element in the array,
  // search for sum-arr[i] in the hashtable, if you find it, print out the pairs giving this sum
  // and you are done!

  if(pairFound==false){
    cout<<"pair not found";
  }



}



int main()
{
    int a[] = {15, 11, 27, 8, 12, 7, 18};
    int n = 7;

    // 7 is count of buckets in hash table
    HashTable ht(7);

    // insert the keys into the hash table.
    // SILVER TODO : Complete insertItem() function
    for (int i = 0; i < n; i++) {
        ht.insertItem(a[i]);
    }

    cout<< "Contents of the hash table are"<<endl;
    // SILVER TODO : Complete printTable() function
    ht.printTable();

    cout<<endl;

    int searchFor = 8;
    // SILVER TODO : Complete searchItem() function
    if(ht.searchItem(searchFor))
     {
       cout<<searchFor<<" found in the hash table"<<endl;
     }
    else{
      cout<<searchFor<<" not found in the hash table"<<endl;
    }
    cout<<"------------------------------------"<<endl;

    int sum = 19;

    // GOLD TODO Complete printPairs() function
    printPairs(a,n,sum,ht);

    return 0;
}
