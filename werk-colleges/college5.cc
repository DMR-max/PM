#include <iostream>
#include <fstream>
using namespace std;


  ifstream invoer ("invoer.txt"); // denk aan <fstream>
  ofstream uitvoer ("uitvoer.txt");
int main (){
  char kar = invoer.get ( );
  while ( ! invoer.eof ( ) ) {
    uitvoer.put (kar); // of uitvoer << kar;
    kar = invoer.get ( );
  }//while
  invoer.close ( );
  uitvoer.close ( );
}
