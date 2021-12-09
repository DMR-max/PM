#include <iostream>
using namespace std;

class vakje { // een struct mag ook
  public:
    // constructor (een destructor hoeft misschien niet)
    vakje ( ) { // beter niet "inline"
      info = 0; volgende = nullptr; }// constructor vakje
      int info;
      vakje* volgende;
};//vakje
class stapel { // de stapel zelf
  public:
      stapel ( ) {
        bovenste = nullptr; }// maak lege stapel
        ~stapel ( ); // destructor
        void zetopstapel (int); // push
        void haalvanstapel (int&); // pop
        bool isstapelleeg ( ) { // is stapel leeg?
          //return ( ( bovenste == nullptr ) ? true : false )
          if (bovenste == nullptr){
            return 1;
          }else{
            return 0;
          }

        // of: if ( bovenste == nullptr ) ...

        }//isstapelleeg

  private: // het begin van de lijst is
    vakje * bovenste; // de bovenkant van de stapel
};//stapel

void stapel::zetopstapel (int getal) { // push
  vakje * temp = new vakje;
  temp->info = getal;
  temp->volgende = bovenste;
  bovenste = temp;
  cout << bovenste << endl;
  cout << temp << endl;
}//stapel::zetopstapel
void stapel::haalvanstapel (int & getal) { // pop
  vakje * temp = bovenste;
  getal = bovenste->info;
  bovenste = bovenste->volgende;
  delete temp;
}//stapel::haalvanstapel
stapel::~stapel ( ) {
  int getal;
  while ( ! isstapelleeg ( ) ){
    haalvanstapel (getal);
  }
}//stapel::~stapels
int main ( ) {
  stapel S;
  int getal;
  cout << "geef getal op:" << endl;
  cin >> getal;
  S.zetopstapel(getal);
  S.haalvanstapel(bovenste);
  cout << bovenste << endl;
  return 0;
};
