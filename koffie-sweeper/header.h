#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

class bordvakje {
  public:
    bordvakje ( );

    bool geopend_zichtbaar;
    bool is_koffie;
    bool gemarkeerd;
    int aantal_buren;
    int x, y;

    bordvakje * buren[8];
};

/*
bordvakje::bordvakje ( ) {
  this -> is_koffie = false;
  this -> gemarkeerd = false;
  this -> geopend_zichtbaar = false;
  this -> aantal_buren = 0;
}
*/

class koffiebord {
  public:
    koffiebord ( );
    ~koffiebord ( );

    void LeesGetal ( );

    bool klaar ( );
    void drukaf ( );
    void zet_mens ( );
    void zet_computer ( );
    void strooi_koffie ( );
    void initialisatie (int h, int b, int p);

  private:
    int h, b;
    int aantal_koffie;
    int zetten;
    int percentage;

    bordvakje * ingang;
    bordvakje * maak_rij ( );
    bordvakje * ga_naar (int i, int j);

    void voeg_voor ( );
    void bouw_bord ( );
};
