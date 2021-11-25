#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "header.h"
using namespace std;

void koffiebord::LeesGetal ( ) {
  char kar;
  int getal;

  cout << "Voer een getal in: ";

  kar = cin.get ( );

    while ( kar == '\n' ) {
      kar = cin.get ( );
    }

    while (kar !='\n') {
      if ( '0' <= kar && kar <= '9' && getal < 1000 ) {
        getal= 10 * getal + (kar - '0');
      }
      kar = cin.get ( );
    }
}
