#include <iostream>
#include "koffiebord.h"
using namespace std;

class vakje { // een struct mag ook
  public:
    // constructor (een destructor hoeft misschien niet)
    vakje ( ) { // beter niet "inline"
      info = 0; volgende = nullptr; }// constructor vakje
      bordvakje * info;
      koffiebord * info_kar;
      bordvakje* volgende;
};//vakje
class stapel { // de stapel zelf
  public:
      stapel ( ) {
        bovenste = nullptr;
        bovenste_kar = nullptr;
       }// maak lege stapel
        ~stapel ( ); // destructor
        void zetopstapel (bordvakje * koffiebord); // push
        void haalvanstapel (bordvakje * koffiebord, int breedte, int hoogte); // pop
        bool isstapelleeg ( ) { // is stapel leeg?
          //return ( ( bovenste == nullptr ) ? true : false )
          if (bovenste == nullptr){
            return 1;
          }else{
            return 0;
          }

        //stapel * pok;

        // of: if ( bovenste == nullptr ) ...

        }//isstapelleeg

  private: // het begin van de lijst is
    bordvakje * bovenste; // de bovenkant van de stapel
    bordvakje * bovenste_kar;
};//stapel

extern stapel S;
