#include <iostream>
#include "koffiebord.h"
using namespace std;

//leesgetal

<<<<<<< HEAD
int maak_getal (char c, int & getal) {
  if ('0' <= c && c <= '9') {
    if (getal <= 999) {

      getal = 10 * getal + (c - '0');

    }
  }

  return getal;
}



char input ( ) {
  char kar;
  kar = cin.get ( );

  while(kar == '\n') {
    cin.get (kar);
  }

  return kar;
}



int lees_getal (int bovengrens, int ondergrens) {
  char kar = input ( );
  int getal = 0;

  while (kar != '\n') {

    maak_getal (kar, getal);

    if (getal > bovengrens) {
      getal = bovengrens;
    } else if (getal < ondergrens) {
        getal = ondergrens;
      }

    cin.get (kar);
  }
  return getal;
}





void koffiebord::menu ( ) {
  druk_af ( );

  char letter;

    cout << endl << "(D)ruk af, (O)penen, (S)toppen." << endl;
    cout << "Kies een letter: ";
    letter = input ( );
    cout << endl;
    switch (letter) {
      case 'd': case 'D': {
        menu ( );
        break;
      }
      case 'o': case 'O': {
        bordvakje * o = coords ( );
        open (o);
        menu ( );
        break;
      }
      case 's': case 'S': {
        return;
      }
      default: {
        break;
      }
    }
}




bordvakje * koffiebord::coords ( ) {
  cout << "x coordinaat: ";
  int x = lees_getal( breedte - 1, 0);

  cout << "y coordinaat: ";
  int y = lees_getal (hoogte - 1, 0);

  // nog verder
}




void koffiebord::open (bordvakje * o) {
  o -> geopend = true;

  if (o -> koffie) {
    verloren = true;
    return;
  }

  // nog verder
}




void koffiebord::voor_voegen (bordvakje * & vorrig_vakje) {
  bordvakje * p = new bordvakje;
  p -> buren[2] = vorrig_vakje;

  if (vorrig_vakje != nullptr) {
    vorrig_vakje -> buren[6] = p;
  }

  vorrig_vakje = p;
}




bordvakje * koffiebord::maak_rij ( ) {
  bordvakje * ingang = nullptr;

  for (int i = 0; i < breedte; i++) {
    voor_voegen (ingang);
  }

  return ingang;
}




void koffiebord::rits (bordvakje * onder_rij, bordvakje * boven_rij) {
  while (boven_rij != nullptr) {

    boven_rij -> buren[4] = onder_rij;
    onder_rij -> buren[0] = boven_rij;

    boven_rij -> buren[5] = onder_rij -> buren[6];
    onder_rij -> buren[7] = boven_rij -> buren[6];

    boven_rij -> buren[3] = onder_rij -> buren[2];
    onder_rij -> buren[1] = boven_rij -> buren[2];

    boven_rij -> maak_aantal ( );

    boven_rij = boven_rij -> buren[2];
    onder_rij = onder_rij -> buren[2];
  }
}




void koffiebord::maak_bord ( ) {
  bordvakje * nieuwe_rij, * vorige_rij;
  ingang = maak_rij ( );
  vorige_rij = ingang;

  for (int j = 1; j < hoogte; j++) {

    nieuwe_rij = maak_rij ( );

    if (vorige_rij != nullptr) {

      rits (nieuwe_rij, vorige_rij);
    }

    vorige_rij = nieuwe_rij;
  }

  bordvakje * hulp = nieuwe_rij;

  while (hulp != nullptr) {

    hulp -> maak_aantal ( );
    hulp = hulp -> buren[2];
  }
}




void koffiebord::druk_af ( ) {
  int h = 1;

  bordvakje * eerste_rij = ingang;
  bordvakje * tweede_rij = eerste_rij -> buren[4];

  cout << '\t';

  // Printen x-coords
  for (int b = 0; b < breedte; b++) {
    cout << b % 10 << ' ';
  }

  cout << endl << endl;

  cout << '0' << '\t';

  while (eerste_rij != nullptr) {

    if (!eerste_rij -> geopend) {
      if (!eerste_rij -> gemarkeerd) {
        cout << ". ";
      }

      else {
        cout << "# ";
      }
    }

  else if (eerste_rij -> koffie) {
      cout << "M ";
    }
    else {
      cout << eerste_rij -> aantal << ' ';
    }

    eerste_rij = eerste_rij -> buren[2];

    // Printen y-coords
    if (eerste_rij == nullptr && tweede_rij != nullptr) {
      cout << endl << h % 10 << '\t';
      h++;
=======
 //bordvakje::bordvakje ( ) {
//  for(i = 0; buren < 8; )
//}//bordvakje::bordvakje

/*koffiebord::koffiebord ( ) {
  // TODO
}//koffiebord::koffiebord
>>>>>>> f4ee07ba19a45b2f60ae370ed9aaba425d1ae723

      eerste_rij = tweede_rij;
      tweede_rij = eerste_rij -> buren[4];
    }
  }

  cout << endl << endl;
}





bool bordvakje::maak_koffie ( ) {
  int v = rand ( ) % 100;
  return (v < perc);
}




void bordvakje::maak_aantal ( ) {
  if (koffie) {
    for (int i = 0; i <= 7; i++) {

      if (buren[i] != nullptr) {
        (buren[i]-> aantal)++;
      }
    }
  }
}
