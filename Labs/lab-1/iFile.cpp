#include <fstream>
#include <iostream>
using namespace std ;
int main ()
{
// File Reading
char str[ 10 ];
//Opens the file for reading
// Ensure that filename.txt is present in the same directory
// as that of the source file
ifstream iFile ( "filename.txt" );
//Reads one string from the file
iFile>> str;
//Outputs the file contents
cout << str << "\n" ;
// waits for a keypress
cin.get();
// iFile is closed
iFile.close();
}
