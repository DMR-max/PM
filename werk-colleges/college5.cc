#include <iostream>
#include <fstream>
using namespace std;


ifstream invoer ("invoer.txt", ios::in | ios::binary); // denk aan <fstream>
ofstream uitvoer ("uitvoer.txt", ios::out | ios::binary);
int main (){
  int karakters;
  karakters = 0;
  char kar = invoer.get ( );
  while ( ! invoer.eof ( ) ) {
    if ( '0' <= kar && kar <= '9' ){
      cout << kar << endl;
      int b = kar;
      int a = b;
      cout << a << endl;
    }else{
      uitvoer.put (kar); // of uitvoer << kar;
    }
    kar = invoer.get ( );
    karakters++;

  }//while
  cout << karakters << endl;
  invoer.close ( );
  uitvoer.close ( );

}
