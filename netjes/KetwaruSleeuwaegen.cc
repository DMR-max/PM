#include <iostream>
#include <fstream>
using namespace std;

/*
Auteurs: Sjouk Ketwaru en Ryan Sleeuwaegen
naam bestand: KetwaruSleeuwaegen.cc
*Beschrijving van t bestand*
text editor: Atom, compiler: MinGW.
Laatst aan gewerkt op: .
 */

void infoblokje ( ) {

}

ifstream invoer ("invoer.txt", ios::in | ios::binary); // denk aan <fstream>
ofstream uitvoer ("uitvoer.txt", ios::out | ios::binary);
int main (){
  int karakters;
  karakters = 0;
  char kar = invoer.get ( );
  while ( ! invoer.eof ( ) ) {

    kar = invoer.get ( );
    karakters++;

  }//while
  invoer.close ( );
  uitvoer.close ( );

}
