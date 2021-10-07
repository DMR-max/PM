#include <iostream>
#include <fstream>
using namespace std;


  ifstream invoer ("invoer.txt", ios::in); // denk aan <fstream>
  ofstream uitvoer ("uitvoer.txt", ios::out);
  char kar = invoer.get ( );
  while ( ! invoer.eof ( ) ) {
    uitvoer.put (kar); // of uitvoer << kar;
    kar = invoer.get ( );
  }//while
  invoer.close ( );
  uitvoer.close ( );
