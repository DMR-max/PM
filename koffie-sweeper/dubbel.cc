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
    element* vorige;
    int info;
    element* volgende;
};//element

class lijst {
  private:
    element* ingang;
    element* uitgang;
    element* huidige;
    element* nieuwe;
  public:
    lijst ( );
    void afdrukkenVA ( );
    void afdrukkenAV ( );
    void bouwlijst (int n);
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
  while (p != uitgang) {
    cout << " # " << p -> info << " | ";
    p = p -> volgende;
  }
  cout << endl;
  // TODO
}//lijst::afdrukkenVA

// druk lijst af, van achter naar voor
void lijst::afdrukkenAV ( ) {
  element* p = uitgang -> vorige;
  while (p != nullptr) {
    cout << " # " << p -> info << " | ";
    p = p -> vorige;
  }
  cout << endl;
  // TODO
}//lijst::afdrukkenAV

// maak lijst met n elementen, bevattende 10,20,...,10*n
void lijst::bouwlijst (int n) {
  huidige = new element;
  ingang = huidige;

  for (int i = 1; i <= n; i++) {
    huidige -> info = 10 * i;
    nieuwe = new element;
    nieuwe -> vorige = huidige;
    huidige -> volgende = nieuwe;
    huidige = nieuwe;
  }

  uitgang = nieuwe;
  // TODO
}//lijst::bouwlijst

int main () {
  lijst L;
  L.bouwlijst (6);
  L.afdrukkenVA ( );
  L.afdrukkenAV ( );
  return 0;
}//main
