#include <iostream>
#include "koffiebord.h"
using namespace std;

void koffiebord::infoblokje ( ) {
  cout << "Makers: Sjouk Ketwaru (s3287297), "
  << "Ryan Sleeuwaegen (s3122166)" << endl
  << "Jaar van aankomst: 2021" << endl
  << "Studierichting: Kunstmatige Intelligentie" << endl
  << "Opgave 4, gemaakt op 13-12-2021" << endl << endl;

  cout << "==================== KOFFIE-SWEEPER ====================" << endl << endl;
}


// Berekent volgende tiental
int maak_getal (char c, int & getal) {
  if ('0' <= c && c <= '9') {
    getal = 10 * getal + (c - '0');
  }
  return getal;
} // Int maak_getal

// Loopt zolang input een enter is
char input ( ) {
  char kar;
  kar = cin.get ( );

  while(kar == '\n') {
    cin.get (kar);
  }

  return kar;
} // Char input

// Leest getallen in
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
  } // While

  return getal;
} // Int lees_getal

// Hoofdmenu
void koffiebord::menu ( ) {
  char letter;

  // Als de computer speelt niet nog een keer afdrukken op het laatst
  if (comp) {
    comp = false;
  }

  druk_af ( );

  // Aantal zetten tellen
  zetten++;

  // Als je verloren hebt, daarna reset
  if (verloren) {
    cout << endl << "Helaas! Je bent dood na: " << zetten - 1 << " zet(ten)." << endl;
    cout << "==========================================================" << endl << endl;
    reset ( );
    maak_bord ( );
    menu ( );
  }

  // Als je gewonnen hebt, daarna reset
  if (gewonnen) {
    cout <<  endl << "Gefeliciteerd! Je hebt gewonnen na: " << zetten  - 1 << " zet(ten)." << endl;
    cout << "==========================================================" << endl << endl;
    reset ( );
    maak_bord ( );
    menu ( );
  }

  cout << endl << "(N)ieuw bord, (O)penen, (M)arkeren, "
  << "(P)ercentage, (G)rootte bord, (R)andom zet, (S)toppen." << endl;
  cout << "Kies een letter: ";

  letter = input ( );
  cout << endl;

  switch (letter) {
    // Nieuw spel starten
    case 'n': case 'N': {
      reset ( );
      maak_bord ( );
      menu ( );
      break;
    }
    // Vakje openen
    case 'o': case 'O': {
      cout << "Openen: " << endl;
      bordvakje * o = coords ( );
      open (o);
      menu ( );
      break;
    }
    // Vakje markeren
    case 'm': case 'M': {
      cout << "Markeren: " << endl;
      bordvakje * m = coords ( );
      markeren (m);
      // Omdat menu wordt aangeroepen wordt zetten++ gedaan
      // maar markeren telt niet als zet dsu daarom zetten--
      zetten--;
      menu ( );
      break;
    }
    // Nieuw percentage kiezen, en daarom ook nieuw spel starten
    case 'p': case 'P': {
      reset ( );
      percentage ( );
      maak_bord ( );
      menu ( );
      break;
    }
    // Dimensies bord aanpassen, en daarom ook nieuw spel starten
    case 'g': case 'G': {
      grootte_bord ( );
      reset ( );
      maak_bord ( );
      menu ( );
      break;
    }
    // Random vakje openen
    case 'r': case 'R': {
      bordvakje * r = random_zet ( );
      open (r);
      menu ( );
      break;
    }
    // Computer laten spelen
    case 'c': case 'C': {
      computer ( );
      break;
    }
    // Stoppen
    case 's': case 'S': {
      return;
      break;
    }
  } // Switch

} // Void menu

// Reset alle waardes om een nieuw spel te starten
void koffiebord::reset ( ) {
  zetten = 0;
  aantal_koffie = 0;
  verloren = false;
  gewonnen = false;
} // Void reset

// Aan het begin keuze maken of mens of computer speelt
// Na computer klaar is wordt t menu aangeroepen
void koffiebord::keuze ( ) {
  char keuze;

  cout << "(M)ens of (C)omputer: ";
  keuze = input ( );
  cout << endl;

  switch (keuze) {
    // Mens laten spelen
    case 'm': case 'M': {
      menu ( );
      break;
    }
    // Computer laten spelen
    case 'c': case 'C': {
      computer ( );
      break;
    }
  } // Switch

} // Void keuze

// Computer een gekeuze aantal spellen laten spelen
void koffiebord::computer ( ) {
  comp = true;
  int spellen, meeste_zetten;

  meeste_zetten = zetten;

  // Maximaal 100000 spellen spelen (kan worden aangepast)
  cout << "Aantal potjes (Max = 1000000): ";
  spellen = lees_getal (1000000, 1);
  cout << endl;

  // Spellen blijven spelen totdat aantal berijkt is
  for (int p = 0; p < spellen; p++) {

    // Random zetten blijven doen totdat gewonnen of verloren is
    while (!gewonnen && !verloren) {
      bordvakje * t = random_zet ( );
      open (t);
      zetten++;
    } // While

    // Eerste spel wordt er een zet te veel opgeteld, daarom deze if - else
    // Nadat een potje is gespeeld wordt het laatste bord van dat potje geprint
    if (p == 0) {
      zetten--;
    }

    // Als je verloren hebt, aantal potjes verloren wordt bijgewerkt
    // Nieuw potje wordt gestart
    if (verloren) {
      verlies[zetten]++;

      if (zetten > meeste_zetten) {
        meeste_zetten = zetten;
      }

      reset ( );
      maak_bord ( );
    }

    // Als je gewonnen hebt, aantal potjes gewonnen wordt bijgewerkt
    // Nieuw potje wordt gestart
    if (gewonnen) {
      win[zetten]++;

      if (zetten > meeste_zetten) {
        meeste_zetten = zetten;
      }

      reset ( );
      maak_bord ( );
    }


  } // For

  for (int i = 0; i <= meeste_zetten; i++) {
    cout << "Zetten: " << i << ", Win: " << win[i] << ", Verlies: " << verlies[i] << endl;
    win[i] = 0;
    verlies[i] = 0;
  }

  cout << endl;
  menu ( );

} // Void computer

// 1 Random zet doen, en loopen zolang het gekozen vakje al open is
bordvakje * koffiebord::random_zet ( ) {
  int x, y;
  bool hulp = true;
  bordvakje * d;

  // Zolang hulp true is blijven loopen
  // Hulp wordt false als een ongeopend vakje is gevonden
  while (hulp) {
    bordvakje * c = ingang;

    // Random x en y-coordinaten maken
    x = rand ( ) % breedte;
    y = rand ( ) % hoogte;

    // Naar x-coordinaat gaan
    for (int i = 0; i < x; i++) {
      c = c -> buren[2];
    }

    // Naar y-coordinaat gaan
    for (int j = 0; j < y; j++) {
      c = c -> buren[4];
    }

    // Als een ongeopend vakje gevonden is stoppen met loopen
    if (!c -> geopend && !c -> gemarkeerd) {
      hulp = false;
      d = c;
    }

  } // While

  // Alleen gekozen random coordinaat printen als de computer niet speelt
  // Anders krijg je heeeeeel veeeeel gekozen coordinaten te zien
  if (comp == false) {
    cout << "Vakje geopend: (" << x << ", " << y << ")" << endl << endl;
  }

  return d;
} // Randomzet

// Dimensies van het bord kunnen aanpassen
void koffiebord::grootte_bord ( ) {
  cout << "Breedte (Min = 2, Max = 100): ";
  breedte = lees_getal(100, 1);

  if (breedte < 2) {
    breedte = 2;
  }

  cout << "Hoogte (Min = 2, Max = 100): ";
  hoogte = lees_getal(100, 1);

  if (hoogte < 2) {
    hoogte = 2;
  }

  cout << endl;
} // Void grootte_bord

// Checken of alle vakjes zijn geopend
void koffiebord::gewonnen_check ( ) {
  bordvakje * a = ingang;
  bordvakje * b = ingang -> buren[4];

  // Alle vakjes na gaan
  while (a != nullptr) {

    // Als een vakje niet is geopend en geen koffie is stoppen
    if (!a -> geopend && !a -> koffie) {
      return;
    }
    else {
      a = a -> buren[2];

      // Als einde van de rij is berijkt naar de volgende rij gaan
      if (a == nullptr && b != nullptr) {
        a = b;
        b = a -> buren[4];
      }
    }
  } // While

  gewonnen = true;
} // Void gewonnen_check

// Coordinaten kunnen kiezen
bordvakje * koffiebord::coords ( ) {
  bordvakje * c = ingang;

  cout << "X coordinaat: ";
  int x = lees_getal(breedte, 0);

  cout << "Y coordinaat: ";
  int y = lees_getal (hoogte, 0);

  cout << endl;

  // Naar x-coordinaat gaan
  for (int i = 0; i < x; i++) {
    c = c -> buren[2];
  }

  // Naar y-coordinaat gaan
  for (int j = 0; j < y; j++) {
    c = c -> buren[4];
  }

  return c;
} // coords

// Vakje kunnen openen
void koffiebord::open (bordvakje * o) {

  // Als een vakje gemarkeerd is kan hij niet geopend worden
  if (!o -> gemarkeerd) {
    o -> geopend = true;

    // Als de eerste zet koffie is, wordt die koffie false
    if ((zetten == 1 || zetten == 0) && o -> koffie) {
      o -> koffie = false;
      aantal_koffie--;
    }
    else if (o -> koffie) {
      verloren = true;
      }

    // Recursie, als een vakje 0 koffie buren heeft, alle omliggende openen
    // en dit blijven doen zolang die buren ook 0 koffie buren hebben
    if (o -> aantal == 0 && !o -> koffie) {
      for (int r = 0; r <= 7; r++) {
        if (o -> buren[r] != nullptr && !o -> buren[r] -> geopend) {
          open (o -> buren[r]);
        }
      } // For
    }

    // Checken of aan winconditie wordt voldaan
    gewonnen_check ( );
  }

} // Void open


// Vakjes kunnen markeren
void koffiebord::markeren (bordvakje * m) {
  // Als je een vakje markeerd, kan je ook de-markeren
  // (nodig als je perongeluk een verkeerd vakje markeerd)
  if (m -> gemarkeerd == true) {
    m -> gemarkeerd = false;
  } else {
      m -> gemarkeerd = true;
  }
} // Void markeren

// Een nieuw vakje voor voegen
// (dit is de enige plek waar nieuwe vakjes worden gemaakt)
void koffiebord::vakjes_toevoegen (bordvakje * & huidig_vakje) {
  bordvakje * nieuw_vakje = new bordvakje;
  // Nieuwe vakje wordt links van het huidige vakje geplaatst
  nieuw_vakje -> buren[2] = huidig_vakje;

  if (huidig_vakje != nullptr) {

    // Randomizer, vakje wordt misschien koffie
    randomizer (huidig_vakje);

    huidig_vakje -> buren[6] = nieuw_vakje;
  }

  huidig_vakje = nieuw_vakje;
} // Void vakjes_toevoegen

// Een rij maken
bordvakje * koffiebord::maak_rij ( ) {
  bordvakje * ingang = nullptr;

  // Nieuwe vakjes voor voegen totdat de breedte berijkt is
  for (int i = 0; i < breedte; i++) {
    vakjes_toevoegen (ingang);
  }

  return ingang;
} // maak_rij

// Alle pointers tussen 2 rijen maken
void koffiebord::pointers (bordvakje * eerste_rij, bordvakje * tweede_rij) {
  while (eerste_rij != nullptr) {

    // Verticale pointers
    eerste_rij -> buren[4] = tweede_rij;
    tweede_rij -> buren[0] = eerste_rij;

    // Diagonale pointers naar beneden
    eerste_rij -> buren[5] = tweede_rij -> buren[6];
    eerste_rij -> buren[3] = tweede_rij -> buren[2];

    // Diagonale pointers naar boven
    tweede_rij -> buren[7] = eerste_rij -> buren[6];
    tweede_rij -> buren[1] = eerste_rij -> buren[2];

    eerste_rij -> maak_aantal ( );

    // Horizontale pointers (naar buren[6] wordt al gemaakt bij vakjes_toevoegen)
    eerste_rij = eerste_rij -> buren[2];
    tweede_rij = tweede_rij -> buren[2];
  } // while

} // Void pointers

// Maakt het bord
void koffiebord::maak_bord ( ) {
  bordvakje * tweede_rij, * eerste_rij;
  //Eerste rij maken (ingang)
  ingang = maak_rij ( );
  eerste_rij = ingang;

  // Loopen totdat de hoogte berijkt is
  for (int j = 1; j < hoogte; j++) {

    // Tweede rij aanmaken
    tweede_rij = maak_rij ( );

    if (eerste_rij != nullptr) {
      // Pointer verbindingen maken tussen de 2 rijen
      pointers (eerste_rij, tweede_rij);
    }

    // De 2e rij wordt nu rij 1, en er wordt daarna een nieuwe rij 2 gemaakt
    eerste_rij = tweede_rij;
  } // For

  bordvakje * aantal = tweede_rij;

  // Aantal koffie buren tellen
  while (aantal != nullptr) {

    aantal -> maak_aantal ( );
    aantal = aantal -> buren[2];

  } // While

} // Void maak_bord

// Het bord printen
void koffiebord::druk_af ( ) {
  int h = 1;

  bordvakje * eerste_rij = ingang;
  bordvakje * tweede_rij = eerste_rij -> buren[4];

  cout << '\t';

  // Printen x-coordinaten
  for (int b = 0; b < breedte; b++) {
    cout << b % 10 << ' ';
  }

  cout << endl << endl;

  // Print 1e y-coordinaat
  cout << '0' << '\t';

  while (eerste_rij != nullptr) {

    // Als vakje niet geopend en niet gemarkeerd is een . printen
    if (!eerste_rij -> geopend) {
      if (!eerste_rij -> gemarkeerd) {
        cout << ". ";
      }
      // Als vakje gemarkeerd is # printen
      else {
        cout << "# ";
      }
    }
    // Als een koffie wordt geopend K printen
    else if (eerste_rij -> koffie) {
      cout << "K ";
    }
    // Anders het aantal koffie buren printen
    else {
      cout << eerste_rij -> aantal << " ";
    }

    // Naar volgende vakje gaan in de rij
    eerste_rij = eerste_rij -> buren[2];

    // Printen y-coordinaat
    if (eerste_rij == nullptr && tweede_rij != nullptr) {
      cout << endl << h % 10 << '\t';
      h++;

      // Naar de volgende rij gaan
      eerste_rij = tweede_rij;
      tweede_rij = eerste_rij -> buren[4];
    }
  } // While

  cout << endl << endl;

  // Print welke beurt je bent en hoeveel koffie er nog is
  cout << "Beurt: " << zetten <<  "\t" << "Koffie: " << aantal_koffie << endl;
} // Void druk_af

// Percentage koffie kunnen aangeven
void koffiebord::percentage ( ) {
  cout << "Percentage (Min = 1, Max = 100): ";
  perc = lees_getal (100, 1);
  cout << endl;
} // Void percentage

// Randomizer om te bepalen of een vakje koffie wordt
void koffiebord::randomizer (bordvakje* p) {
  int randomgetal = rand ( ) % 1000000;

    if (randomgetal <= (perc * 10000)) {
      p -> koffie = true;
      aantal_koffie++;
    }
    else {
      p -> koffie = false;
    }
} // Void randomizer

// Aantal buren dat koffie is maken
void bordvakje::maak_aantal ( ) {

  // Als een vakje koffie is, wordt het aantal bij alle buren 1 meer
  if (koffie) {
    for (int i = 0; i <= 7; i++) {

      if (buren[i] != nullptr) {
        (buren[i] -> aantal)++;
      }

    } // For
  }
} // Void maak_aantal
