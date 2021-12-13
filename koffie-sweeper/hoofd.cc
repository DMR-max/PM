/*
Auteurs: Sjouk Ketwaru en Ryan Sleeuwaegen
Student nummers: s3287297 en s3122166
naam bestanden: koffiebord.cc, koffiebord.h, hoofd.cc

Het programma is in staat om koffiesweeper te spelen via een menu-systeem.
Aan de hand van het menu is het spel speelbaar en anders kan de computer spelen.
Ook is het mogelijk om random zetten te doen.

Text editor: Atom (ubuntu), Compiler: G++ versie: 9.3.0.
Laatst aan gewerkt op: 13-12-2021.
*/

#include <iostream>
#include "koffiebord.h"
using namespace std;

int main ( ) {
  srand(time(0));
  koffiebord K;
  //bordvakje B;
  K.infoblokje ( );
  K.grootte_bord ( );
  K.percentage ( );
  K.maak_bord ( );
  K.keuze ( );
  K.menu ( );
  return 0;
}
