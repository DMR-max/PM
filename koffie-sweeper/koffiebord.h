int lees_getal (int bovengrens);

class bordvakje {

  public:
    bordvakje ( ) {
      geopend = false;
      gemarkeerd = false;
      aantal = 0;
      
      for (int i = 0; i <= 8; i++) {
        buren[i] = nullptr;
      }

    }
    bool geopend;
    bool koffie;
    bool gemarkeerd;
    int aantal;            //     7 0 1
    bordvakje * buren[8];  //     6   2
    bool maak_koffie ( );  //     5 4 3
    void maak_aantal ( );

};

class koffiebord {
  private:
    bordvakje * ingang;
    int hoogte, breedte;
    bool verloren, gewonnen;
    int zetten;
    int aantal_koffie;
    int perc;
    bool comp;
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
