#include <iostream>
#include "koffiebord.h"
using namespace std;

void koffiebord::infoblokje ( ) {
  cout << "Makers: Sjouk Ketwaru (s3287297), "
  << "Ryan Sleeuwaegen (s3122166)" << endl
  << "Jaar van aankomst: 2021" << endl
  << "Studierichting: Kunstmatige Intelligentie" << endl
  << "Opgave 4, gemaakt op 13-12-2021" << endl << endl;

  cout << "=============== KOFFIE-SWEEPER ===============" << endl << endl;
}


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
  zetten++;
  druk_af ( );

  cout << "Beurt: " << zetten - 1 <<  "\t" << "Koffie: " << aantal_koffie << endl;

  if (verloren) {
    cout << endl << "Helaas! Je bent dood na: " << zetten - 1 << " zet(ten)." << endl;
    cout << "==========================================================" << endl << endl;
    zetten = 0;
    aantal_koffie = 0;
    verloren = false;
    hulp = true;
    maak_bord ( );
    menu ( );

  }
  if (gewonnen || aantal_koffie == 0) {
    cout <<  endl << "Gefeliciteerd! Je hebt gewonnen na: " << zetten - 1 << " zet(ten)." << endl;
    if (aantal_koffie == 0) {
      cout << "(Je hebt alle koffie gemarkeerd!)" << endl;
      cout << "==========================================================" << endl << endl;
    }
    else {
      cout << "(Je hebt alle lege vakjes geopend!)" << endl;
      cout << "==========================================================" << endl << endl;
    }
    zetten = 0;
    aantal_koffie = 0;
    gewonnen = false;
    hulp = true;
    maak_bord ( );
    menu ( );
  }

  cout << endl << "(N)ieuw bord, (O)penen, (M)arkeren, "
  << "(P)ercentage, (G)rootte bord, (R)andom zet, (S)toppen." << endl;
  cout << "Kies een letter: ";
  letter = input ( );
  cout << endl;
  switch (letter) {
    case 'n': case 'N': {
      maak_bord ( );
      aantal_koffie = 0;
      zetten = 0;
      hulp = true;
      menu ( );
      break;
    }
    case 'o': case 'O': {
      cout << "Openen: " << endl;
      bordvakje * o = coords ( );
      open (o);
      menu ( );
      break;
    }
    case 'm': case 'M': {
      cout << "Markeren: " << endl;
      bordvakje * m = coords ( );
      markeren (m);
      zetten--;
      menu ( );
      break;
    }
    case 'p': case 'P': {
      percentage ( );
      maak_bord ( );
      aantal_koffie = 0;
      zetten = 0;
      hulp = true;
      menu ( );
      break;
    }
    case 'g': case 'G': {
      grootte_bord ( );
      maak_bord ( );
      aantal_koffie = 0;
      zetten = 0;
      hulp = true;
      menu ( );
      break;
    }
    case 'r': case 'R': {
      bordvakje * r = random_zet ( );
      open (r);
      menu ( );
      break;
    }
    case 's': case 'S': {
      return;
      break;
    }

  }
}



bordvakje * koffiebord::random_zet ( ) {
  int x, y;
  bool hulp = true;
  bordvakje * d;

  while (hulp) {
    bordvakje * c = ingang;

    x = rand ( ) % breedte;
    y = rand ( ) % hoogte;

    for (int i = 0; i < x; i++) {
      c = c -> buren[2];
    }

    for (int j = 0; j < y; j++) {
      c = c -> buren[4];
    }

    if (!c -> geopend) {
      hulp = false;
      d = c;
    }

  }

  cout << "Vakje geopend: (" << x << ", " << y << ")" << endl << endl;

  return d;
}



void koffiebord::grootte_bord ( ) {
  cout << "Breedte: ";
  breedte = lees_getal(200, 1);

  cout << "Hoogte: ";
  hoogte = lees_getal(200, 1);

  cout << endl;
}



bordvakje * koffiebord::coords ( ) {
  cout << "X coordinaat: ";
  int x = lees_getal(breedte, 0);

  cout << "Y coordinaat: ";
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

void koffiebord::gewonnen_check ( ) {
  bordvakje * a = ingang;
  bordvakje * b = ingang -> buren[4];
  while (a != nullptr) {

    if (!a -> geopend && !a -> koffie) {
      return;
    }
    else {
      a = a -> buren[2];

      if (a == nullptr && b != nullptr) {
        a = b;
        b = a -> buren[4];
      }
    }

  }
  gewonnen = true;
}



void koffiebord::open (bordvakje * o) {
  o -> geopend = true;

    if (zetten == 1 && o -> koffie) {
      o -> koffie = false;
      aantal_koffie--;
    }
    else if (o -> koffie) {
      verloren = true;
    }

  if (o -> aantal == 0) {
    for (int r = 0; r <= 7; r++) {
      if (o -> buren[r] != nullptr && !o -> buren[r] -> geopend) {
        open (o -> buren[r]);
      }
    }
  }
  gewonnen_check ( );
}

void koffiebord::markeren (bordvakje * m) {
  if (m -> gemarkeerd == true) {
    m -> gemarkeerd = false;
    if (m -> koffie) {
      aantal_koffie = aantal_koffie + 2;
    }
  } else {
      m -> gemarkeerd = true;
  }

  if (m -> koffie == true) {
    aantal_koffie--;
  }
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

    if (hulp) {
      randomizer (eerste_rij);
      eerste_rij -> maak_aantal ( );
    }


    if (!eerste_rij -> geopend) {
      if (!eerste_rij -> gemarkeerd) {
        cout << ". ";
      }
      else {
        cout << "# ";
      }
    }
    else if (eerste_rij -> koffie) {
      cout << "K ";
    }
    else {
      cout << eerste_rij -> aantal << " ";
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
   hulp = false;
  cout << endl << endl;
}


/*
bool bordvakje::maak_koffie ( ) {
  int v = rand ( ) % 100;
  return (v < perc);
}
*/


void koffiebord::percentage ( ) {
  cout << "Percentage: ";
  perc = lees_getal (100, 0);
  cout << endl;
}



void koffiebord::randomizer (bordvakje* p) {
  int randomgetal = rand ( ) % 1000000;

    if (randomgetal <= (perc * 10000)) {
      p -> koffie = true;
      aantal_koffie++;
    }
    else {
      p -> koffie = false;
    }
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
