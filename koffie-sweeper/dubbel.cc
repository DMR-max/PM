//
// Programmeermethoden 2021
//
// http://www.liacs.leidenuniv.nl/~kosterswa/pm/dubbel.cc
// C++-programma om te oefenen in het gebruik van pointers, deel 2.
// Er moet een dubbelverbonden pointerlijst gefabriceerd worden,
// waarbij de "elementen" die met elkaar verbonden worden bestaan uit
//   1. Een int(eger)
//   2. Een pointer naar het vorige element (of nullptr)
//   3. Een pointer naar het volgende element (of nullptr)
// Schrijf de functies afdrukken (2x) en bouwlijst. Gebruik een eigen
// hulpfunctie voegvoor.
//
// Compiler: GNU g++
// Datum: 1 november 2021
// Auteur: Walter Kosters, Informatica Universiteit Leiden
//         email w.a.kosters@liacs.leidenuniv.nl
//

#include <iostream>
using namespace std;

class element {
  public:
    int info;
    element* buren[8];
};//element

class lijst {
  private:
    element* ingang;
    element* uitgang;
    element* huidige;
    element* nieuwe;
    int b, h, i, j;
  public:
    lijst ( );
    void afdrukkenVA ( );
    void afdrukkenAV ( );
    void bouwlijst ( );
};//lijst

//   +-----+      +-----+----+-----+        +-----+----+-----+      +-----+
//   |   --+----> | NULL| 10 |   --+------> |  |  | 20 | NULL| <----+--   |
//   +-----+      +-----+--+-+-----+        +-----+--+-+-----+      +-----+
//  L.ingang                    ^---------------                   L.uitgang
//
// L.ingang (L van klasse lijst) wijst dus het eerste element uit een serie
// elementen aan, waarbij ieder element informatie bevat (het info-veld),
// en twee pointers: naar het vorige en volgende element;
// voor het voorbeeld hierboven zijn in totaal twee new's nodig.

//constructor
lijst::lijst ( ) {
  ingang = nullptr; // of NULL
  uitgang = nullptr; // of NULL
}//lijst::lijst

// druk lijst af, van voor naar achter
void lijst::afdrukkenVA ( ) {
  element* p = ingang;
  int test = 0;

    while (p != uitgang) {
      cout << p -> info;
      p = p -> buren[2];
      test++;
      if (test == b) {
        cout << endl;
        test = 0;
      }
    }
    cout <<
  // TODO
}//lijst::afdrukkenVA

/* druk lijst af, van achter naar voor
void lijst::afdrukkenAV ( ) {
  element* p = uitgang -> vorige;

    while (p != nullptr) {
      cout << " # " << p -> info << " | ";
      p = p -> vorige;
    }
    cout << endl;

  // TODO
}//lijst::afdrukkenAV */

void lijst::bouwlijst ( ) {
  huidige = new element;
  ingang = huidige;

  cout << "Hoogte: ";
  cin >> h;
  cout << "Breedte: ";
  cin >> b;
  cout << endl;

  for (j = 1; j <= 1; j++) {
      for (i = 1; i <= b * h; i++) {

        huidige -> info = i;
        nieuwe = new element;
        nieuwe -> buren[6] = huidige;
        huidige -> buren[2] = nieuwe;
        huidige = nieuwe;
      }
  uitgang = nieuwe;
  }
}//lijst::bouwlijst

int main () {
  lijst L;
  L.bouwlijst ( );
  L.afdrukkenVA ( );
  return 0;
}//main
