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
  cout << "Makers: Sjouk Ketwaru (s3287297), "
  << "Ryan Sleeuwaegen (s3122166)" << endl
  << "Jaar van aankomst: 2021" << endl
  << "Studierichting: Kunstmatige Intelligentie" << endl
  << "opgave 2, gemaakt op 18-10-2021" << endl
  << "Dit is een programma dat een foutloos te compileren C++-programma "
  << "een klein beetje probeert te begrijpen." << endl << endl;
}



void copy ( ) {
  ifstream invoer ("invoer.txt", ios::in | ios::binary);
  ofstream uitvoer ("uitvoer.txt", ios::out | ios::binary);
  char kar = invoer.get ( );
  char kar_vorige;
  while ( ! invoer.eof ( ) ) {
    if (kar == '/' && kar == kar_vorige){
        while (kar != '\n'){
          kar = invoer.get ( );
      }
    }else if(kar_vorige == '/' || kar_vorige != '/'){
      uitvoer.put(kar_vorige);
    }
    kar_vorige = kar;
    kar = invoer.get( );
  }
  invoer.close ( );
  uitvoer.close ( );
}



int main ( ){
  infoblokje ( );
  copy ( );
}
