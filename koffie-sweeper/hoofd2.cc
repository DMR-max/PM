#include <iostream>
#include "stapel.h"
using namespace std;

int main ( ) {
  srand(time(0));
  koffiebord K;

  //bordvakje B;
  K.infoblokje ( );
  K.grootte_bord ( );
  K.maak_bord ( );

  K.menu( );

  return 0;
}
