#include <iostream>
#include "koffiebord.h"
using namespace std;

int LeesGetal (int bovengrens) {
  char kar;
  int getal = 0;

  kar = cin.get ( );

    while ( kar == '\n' ) {
      kar = cin.get ( );
    }

    while (kar !='\n') {
      if ( '0' <= kar && kar <= '9' && getal < bovengrens ) {
        getal = 10 * getal + (kar - '0');
      }
      kar = cin.get ( );
    }
    return getal;
}

int main ( ) {
<<<<<<< HEAD
  srand(time(0));
  koffiebord Koffiebord;
  Koffiebord.menu( );
  return 0;
=======
  int b, h;
  //bordvakje b;
  //koffiebord K;

  cout << "Breedte: ";
  b = LeesGetal (1000);

  cout << "hoogte: ";
  h = LeesGetal (1000);

  cout << b << ", " << h << endl;
>>>>>>> f4ee07ba19a45b2f60ae370ed9aaba425d1ae723
}
