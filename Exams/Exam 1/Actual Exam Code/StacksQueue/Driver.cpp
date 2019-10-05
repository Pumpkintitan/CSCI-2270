#include<iostream>
#include<string>
#include "STACKARR.hpp"
#include "QUEUEST.hpp"

using namespace std;

int main(int argc, char* argv[])
{
    if(argc <2)
    {
      cout<< "error. not enough input "<<endl;
      return -1;
    }

    int size = stoi(argv[1]);
    Queue Q;
    Q.initialiseQueue(size);

    /** test case 1**/
    /** in general enQ deQ**/
    int arr1[3] = {1,2,3};
    for(int i=0;i<3;i++)
    {
      Q.enqueue(arr1[i]);
      //Q.dequeue();
    }

    int result1 = Q.dequeue();//Q.peek();
    int result2 = Q.dequeue();
    cout<< "Test1: "<<endl;
    if(result1 == 1 && result2 ==2)
      cout<< "    Passed test 1"<< endl;
    else
      cout << "    Failed test 1"<< endl;

    // test case 2. Dequeue from an empty QUEUE
    cout<<"Test2:"<<endl;
    Q.dequeue();
    if(Q.isEmpty())
      cout<<"    Passed test 2"<<endl;
    else
      cout<<"   Failed test 2"<<endl;

    // test case3. Peek from an empty QUEUE
    cout<<"Test3:"<<endl;
    int result = Q.dequeue();//Q.peek();
    if (result!= -999)
      cout<< "    Failed"<<endl;
    else
      cout<< "    Passed"<<endl;
    return 0;
}
