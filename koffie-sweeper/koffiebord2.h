
int lees_getal (int bovengrens);


class bordvakje {

  public:
    bordvakje ( ) {
      geopend = false;
      gemarkeerd = false;
      aantal = 0;
      perc = 20;
      koffie = maak_koffie ( );
      volgende = nullptr;
    }
    bool geopend;
    int perc;
    bool koffie;
    bool gemarkeerd;
    bordvakje* var;
    bordvakje* info;
    bordvakje* volgende;
    int aantal;            //     7 0 1
    bordvakje * buren[8];  //     6   2
    bool maak_koffie ( );  //     5 4 3
    void maak_aantal ( );
    int percentage ( );

};

class koffiebord {
  private:
    bordvakje * ingang;
    int hoogte, breedte;
    bool verloren, gewonnen;
    int zetten = 0;
    int aantal_koffie;
    int teller = 0;

  public:
    koffiebord ( ) {
      verloren = false;
      gewonnen = false;
      aantal_koffie = 0;
      //info_kar = 0;
      //volgende = nullptr;
    }

    //~koffiebord ( );
    void infoblokje ( );
    bordvakje * druk_af ( );
    bordvakje * koffiebord_geheel;
    //bordvakje * save ( );
    //koffiebord  info_kar;
    //koffiebord  volgende;
    void menu ( );
    void stapje_terug( );
    void grootte_bord ( );
    void vakjes_toevoegen (bordvakje * & tst);
    bordvakje * maak_rij ( );
    void maak_bord ( );
    void print_rij (bordvakje * rij);
    void pointers (bordvakje * tweede, bordvakje * eerste);
    void open (bordvakje * o);
    void markeren (bordvakje * m);
    void gewonnen_check ( );
    bordvakje * coords ( );
    bordvakje * random_zet ( );
};
