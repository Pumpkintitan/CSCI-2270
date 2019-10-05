#include<iostream>
#include<string>
using namespace std;

/*
// Split 'arr' into 'even_arr' & 'odd_arr'
//  - 'arr': pointer to original array
//  - 'even_arr': pointer to even array
//  - 'odd_arr': pointer to odd array
*/
void split(int* &arr, int* &even_arr, int* &odd_arr, int size, int &even_size, int &odd_size)
{
    //First I need to figure out how many even/odd nubers there are in the array
  for (int i = 0; i < size; i++) {
    if (arr[i]%2 == 0) {
      even_size++;
    } else {
      odd_size++;
    }
  }
  int *even_arr2 = new int[even_size];
  int *odd_arr2 = new int[odd_size];
  //And then loop back through and add the numbers in
  //But I need a counter for each to make sure I don't allocate to non-existent memory
  int even_counter = 0;
  int odd_counter = 0;
  for (int i = 0; i < size; i++) {
    if (arr[i]%2 == 0) {
      even_arr2[even_counter] = arr[i];
      even_counter++;
    } else {
      odd_arr2[odd_counter] = arr[i];
      odd_counter++;
    }
  }
  //Then I set the old arrays to the new values;
  even_arr = even_arr2;
  //This looks wierd, but the even_arr would give out garbage values for the first two elements
  //I have no idea why, but this fixes the problem and the code runs correctly
  even_arr[0] = even_arr2[0];
  even_arr[1] = even_arr2[1];

  odd_arr = odd_arr2;
  //And deallocate them
  delete [] even_arr2;
  delete [] odd_arr2;
}

void printArray(int* arr, int size) {
    for(int i = 0; i<size; i++)
    {
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;
}

int main(int argc, char* argv[])
{
    if(argc<2)
    {
      cout<<"usage: a.out <#>";
      return -1;
    }

	// Create input array:
    int size = stoi(argv[1]);
    int *arr = new int[size];

    cout<< "original array: ";
    for(int i = 0; i<size; i++)
    {
        arr[i] = rand()%100;
        cout<< arr[i];
        if(i < size-1)
          cout << ", ";
    }
    cout<<endl;

	// Call your function with new arrays:
  int even_size = 0;
  int odd_size = 0;
  //Now I create the new arrays
  int *even_arr = new int[0];
  int *odd_arr = new int[0];
  //And call split()
  split(arr, even_arr, odd_arr, size, even_size, odd_size);
	// Output
  //Showing even array
  if (even_size == 0) {
    cout << "no even items in the array" << endl;
  } else {
    cout<< "even array: ";
    for(int i = 0; i<even_size; i++)
    {
      cout<< even_arr[i];
      if(i < even_size-1)
      cout << ", ";
    }
    cout<<endl;
  }
  //Showing odd array
  if (odd_size == 0) {
    cout << "no odd items in the array" << endl;
  } else {
  cout<< "odd array: ";
  for(int i = 0; i<odd_size; i++)
  {
      cout<< odd_arr[i];
      if(i < odd_size-1)
        cout << ", ";
  }
  cout<<endl;
}
  //Deallocating memory
	delete [] even_arr;
  delete [] odd_arr;

    return 0;
}
