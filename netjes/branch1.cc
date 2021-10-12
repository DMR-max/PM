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
  bool commentaar, inspringen;
  int d, diepte = 0;
  cin >> d;
  while ( ! invoer.eof ( ) ) {
    kar_vorige = kar;
    kar = invoer.get();
    if (kar == '/' && kar_vorige == '/'){
      commentaar = true;
    }
    if (kar =='{' ){
      diepte++;
      inspringen = true;
    }
    if (kar == '}'){
      diepte--;
    }
    if (commentaar == true){
      while(kar != '\n'){
       uitvoer.put(' ');
       kar = invoer.get ( );
      }
      commentaar = false;
    }
     if (inspringen == true){
      uitvoer.put('\n');
        for(int i; i < diepte; i++){
          uitvoer.put(' ');
        }
      inspringen = false;
    }
    for (int i; i < d; i++){
      uitvoer.put(' ');
    }
    uitvoer.put(kar_vorige);
    }
}




int main ( ){
  infoblokje ( );
  copy ( );
}
