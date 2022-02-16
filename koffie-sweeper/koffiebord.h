/*
Auteurs: Sjouk Ketwaru en Ryan Sleeuwaegen
Student nummers: s3287297 en s3122166
naam bestanden: koffiebord.cc, koffiebord.h, hoofd.cc

Het programma is in staat om koffiesweeper te spelen via een menu-systeem.
Aan de hand van het menu is het spel speelbaar en anders kan de computer spelen.
Ook is het mogelijk om random zetten te doen.

Text editor: Atom (ubuntu), Compiler: G++ versie: 9.3.0.
Laatst aan gewerkt op: 13-12-2021.
*/

int lees_getal (int bovengrens);

class bordvakje {

  public:
    bordvakje ( ) {
      geopend = false;
      gemarkeerd = false;
      aantal = 0;

      /*
      for (int i = 0; i <= 8; i++) {
        buren[i] = nullptr;
      }
      */

    }
    bool geopend; // check of vakje geopend is.
    bool koffie; // check of koffie heeft.
    bool gemarkeerd; // check of vakje gemarkeerd is.
    int aantal;            //     7 0 1
    bordvakje * buren[8];  //     6   2
    bool maak_koffie ( );  //     5 4 3
    void maak_aantal ( );

};

class koffiebord {
  private:
    int hoogte, breedte;
    bool verloren, gewonnen;
    int zetten;
    int aantal_koffie;
    bordvakje * ingang;
    int perc;
    bool comp; //niet printen van coordinaten
    int win[10000];
    int verlies[10000];

  public:
    koffiebord ( ) {
      comp = false;
      verloren = false;
      gewonnen = false;
      zetten = 0;
      aantal_koffie = 0;

      for (int i = 0; i <= 10000; i++) {
        win[i] = 0;
        verlies[i] = 0;
      }

    }

    //~koffiebord ( );
    void infoblokje ( );
    void reset ( );
    void percentage ( );
    void computer ( );
    void druk_af ( );
    void keuze ( );
    void randomizer (bordvakje* p);
    void menu ( );
    void grootte_bord ( );
    void vakjes_toevoegen (bordvakje * & tst);
    bordvakje * maak_rij ( );
    void maak_bord ( );
    void pointers (bordvakje * tweede, bordvakje * eerste);
    void open (bordvakje * o);
    void markeren (bordvakje * m);
    void gewonnen_check ( );
    bordvakje * coords ( );
    bordvakje * random_zet ( );
};
