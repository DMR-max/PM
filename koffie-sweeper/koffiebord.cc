#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "koffiebord.h"
using namespace std;


int leesgetal (int bovengrens) {
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
}//leesgetal

/* bordvakje::bordvakje ( ) {
  // TODO
}//bordvakje::bordvakje

koffiebord::koffiebord ( ) {
  // TODO
}//koffiebord::koffiebord

koffiebord::~koffiebord ( ) {
  // TODO
}//koffiebord::~koffiebord

void koffiebord::drukaf ( ) {
  cout << "Een koffiebord ziet er mooi uit." << endl;
  // TODO
}//koffiebord::drukaf */
