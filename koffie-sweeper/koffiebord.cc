#include <iostream>
#include "koffiebord.h"
using namespace std;


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



int lees_getal (int eerstegrens, int tweedegrens) {
  char kar = input ( );
  int getal = 0;

  while (kar != '\n') {

    maak_getal (kar, getal);

    if (getal > eerstegrens) {
      getal = eerstegrens;
    } else if (getal < tweedegrens) {
        getal = tweedegrens;
      }

    cin.get (kar);
  }
  return getal;
}





void koffiebord::menu ( ) {
  char letter;
  druk_af ( );

    cout << endl << "(D)ruk af, (O)penen, (M)arkeren, (S)toppen." << endl;
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
      case 'm': case 'M': {
        markeren ( );
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
  int x = lees_getal(breedte, 0);

  cout << "y coordinaat: ";
  int y = lees_getal (hoogte, 0);

  cout << endl;

  bordvakje * c = ingang;
  for (int i = 0; i < x; i++) {
    c = c -> buren[2];
  }

  for (int j = 0; j < y; j++) {
    c = c -> buren[4];
  }

  return c;
}




void koffiebord::open (bordvakje * o) {
  o -> geopend = true;

  if (o -> koffie) {
    verloren = true;
    return;
  }

  if (o -> aantal == 0) {
    for (int r = 0; r <= 7; r++) {
      if (o -> buren[r] != nullptr && !o -> buren[r] -> geopend) {
        open (o -> buren[r]);
      }
    }
  }
}

void koffiebord::markeren (bordvakje * m) {
  
}




void koffiebord::vakjes_toevoegen (bordvakje * & huidig_vakje) {
  bordvakje * nieuw_vakje = new bordvakje;
  nieuw_vakje -> buren[2] = huidig_vakje;

  if (huidig_vakje != nullptr) {
    huidig_vakje -> buren[6] = nieuw_vakje;
  }

  huidig_vakje = nieuw_vakje;
}


bordvakje * koffiebord::maak_rij ( ) {
  bordvakje * ingang = nullptr;

  for (int i = 0; i < breedte; i++) {
    vakjes_toevoegen (ingang);
  }

  return ingang;
}


void koffiebord::pointers (bordvakje * eerste_rij, bordvakje * tweede_rij) {
  while (eerste_rij != nullptr) {

    eerste_rij -> buren[4] = tweede_rij;
    tweede_rij -> buren[0] = eerste_rij;

    eerste_rij -> buren[5] = tweede_rij -> buren[6];
    tweede_rij -> buren[7] = eerste_rij -> buren[6];

    eerste_rij -> buren[3] = tweede_rij -> buren[2];
    tweede_rij -> buren[1] = eerste_rij -> buren[2];

    eerste_rij -> maak_aantal ( );

    eerste_rij = eerste_rij -> buren[2];
    tweede_rij = tweede_rij -> buren[2];
  }
}


void koffiebord::maak_bord ( ) {
  bordvakje * tweede_rij, * eerste_rij;
  ingang = maak_rij ( );
  eerste_rij = ingang;

  for (int j = 1; j < hoogte; j++) {

    tweede_rij = maak_rij ( );

    if (eerste_rij != nullptr) {

      pointers (eerste_rij, tweede_rij);
    }

    eerste_rij = tweede_rij;
  }

  bordvakje * aantal = tweede_rij;

  while (aantal != nullptr) {

    aantal -> maak_aantal ( );
    aantal = aantal -> buren[2];
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

/*
        if (eerste_rij -> koffie) {
          cout << "K ";

        } else {
          cout << ". ";
        }

*/
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

      eerste_rij = tweede_rij;
      tweede_rij = eerste_rij -> buren[4];
    }
  }

  cout << endl << endl;
}


bool bordvakje::maak_koffie ( ) {
  int v = rand ( ) % 50;
  return (v < perc);
}


void bordvakje::maak_aantal ( ) {
  if (koffie) {
    for (int i = 0; i <= 7; i++) {

      if (buren[i] != nullptr) {
        (buren[i] -> aantal)++;
      }
    }
  }
}
