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
