#include <iostream>
#include <fstream>
using namespace std;


ifstream invoer ("invoer.txt", ios::in | ios::binary); // denk aan <fstream>
ofstream uitvoer ("uitvoer.txt", ios::out | ios::binary);
int main (){
  int karakters, a;
  karakters = 0;
  char kar = invoer.get ( );
  while ( ! invoer.eof ( ) ) {
    kar = invoer.get ( );
    karakters++;
    if (isdigit(kar) == true){
      cout << kar << endl;
      a = kar * kar;
      cout << a << endl;
    }else{
      uitvoer.put (kar); // of uitvoer << kar;
    }
  }//while
  cout << karakters << endl;
  invoer.close ( );
  uitvoer.close ( );

}
