/*
Auteurs: Sjouk Ketwaru en Ryan Sleeuwaegen
naam bestand: KetwaruSleeuwaegen3.cc

Het programma is in staat LIFE te spelen via een menu-systeem.
Er is gekozen voor een eindige wereld van 1000 x 1000, dit om
problemen te voorkomen. De gebruiker ziet een klein deel van deze
wereld, de view. Via het menu kan de gebruiker uit meerde opties kiezen.

Menu
Stoppen: Stopt het programma.
Heelschoon: Maakt alle cellen in de wereld dood.
Schoon: Maakt alle cellen in de view dood.
Verschuif: Verschuif je view naar links, rechts, boven of onder.
Random: Vult de view met random levende en doden cellen.
Toggle: Klapt levend en dood om voor de cursor, die ook verplaatst kan worden.
File: Leest een txt bestand in en plaatst deze in de wereld.
Een: Er wordt één generatie van life gedaan.
Gaan: Er worden een hele serie generaties van life gedaan, en allemaal getoond.
Parameters: Opent het submenu om parameters in te stellen.

Parameters
Verschuivings-stapgrootte: Hoeveel cellen verschuif per kant op gaat.
Percentage: Het percentage cellen dat levend moet zijn bij de optie random.
Twee verschillende karakters: Kies de karakters voor levende en dode cellen.
View: Bepaal hoe groot de view is.

Text editor: Atom (ubuntu), Compiler: G++.
Laatst aan gewerkt op: 15-11-2021.
*/



#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

class life {
  public:
    life ( ) {
      hoogte = 25; //Hoogte van de view, kan worden aangepast
      breedte = 80; //Breedte van de view, kan worden aangepast
      cursorhoogte = hoogte / 2; //Verticale positie v.d. cursor
      cursorbreedte = breedte / 2; //Horizontale positive v.d. cursor

    }
    void drukaf ( );
    void heelschoon ( );
    void schoon ( );
    int verschuif ( );
    int verschuivingsstap ( );
    void Percentage ( );
    void parameters ( );
    void randomizer ( );
    void toggle ( );
    void file ( );
    void een ( );
    void gaan ( );
    void menu ( );
    void view ( );
    void LeesGetal ( );
    void karakters ( );

  private:
    static const int MAX = 1000; //Grootte v.d. wereld
    bool dewereld[MAX][MAX]; //De wereld
    bool reserve[MAX][MAX]; //Backup van de wereld
    int hoogte, breedte; //Voor de view
    int percentage; //Percentage voor randomizer
    int schuif = 0;
    int schuifbreedte = 0;
    int omlaag = 1;
    int omhoog = 1;
    int rechts = 1;
    int links = 1;
    int getal = 0;
    char kar_levend = 'X'; //Levende cellen, kan worden aangepast
    char kar_dood = ' '; //Dode cellen, kan worden aangepast
    int cursorhoogte, cursorbreedte;
    int verschil_breedte = 80;
    int verschil_hoogte = 25;
};

//Functie om je view te printen
void life::drukaf ( ){
  int i = 0, j = 0;

  for ( i = schuif; i < hoogte; i++ ) {
    for ( j = schuifbreedte; j < breedte; j++ ) {

      //Check voor world border (is altijd dood, en is een '=')
      if (i == MAX - 1 || i == 0 || j == MAX - 1 || j == 0 ) {
        dewereld[i][j] = false;
        cout << "=";

      //Cursor als de cel levend is
      }else if (dewereld[i][j]) {
        if (i == cursorhoogte && j == cursorbreedte){
          cout << "#";
        }else{
          cout << kar_levend;
        }
      }

      //Cursor als de cel dood is
      else {
        if (i == cursorhoogte && j == cursorbreedte){
          cout << "$";
        }else{
          cout << kar_dood;
        }
      }

    }//for j

  //Naar volgende regel van view
  cout << endl;
  }//for i
}//life::drukaf

// Functie om inputs te filteren zodat het alleen getallen zijn
void life::LeesGetal ( ) {
  char kar;

  kar = cin.get ( );

  // != 1 om het verschil tussen percentage en getal weer te geven
  // (percentage mag niet voorbij 100, getal niet voorbij 1000)
  if (percentage != 1){

    // Zolang input een enter is opnieuw letter vragen
    while (kar == '\n'){
      kar = cin.get( );
    }

    // Zorgen dat elk getal (behalve percentage) niet groter dan 1000 kan zijn
    while (kar !='\n'){
      if ('0' <= kar && kar <= '9' && getal < 1000) {
        getal= 10 * getal + (kar - '0');
      }
      kar = cin.get( );
    }

  }else{
    percentage = 0;
    kar = cin.get( );

    //Zorgen dat percentage niet groter dan 100 kan zijn
    while (kar !='\n'){
      if ('0' <= kar && kar <= '9' && percentage * 10 < 101) {
        percentage = 10 * percentage + (kar - '0');
      }
      kar = cin.get( );
    }

    if (percentage > 100 && percentage < 110) {
      percentage = percentage / 10;
    }

    cout << "Percentage: " << percentage << endl;
  }
} //life::leesGetal

//Functie om alle cellen in de wereld dood te maken
void life::heelschoon ( ) {
  int i, j;

  for ( i = 0; i < MAX; i++ ) {
    for ( j = 0; j < MAX; j++ ) {
      dewereld[i][j] = false;
    } //for j
  } //for i
} //life::heelschoon

//Functie om alle cellen in de view dood te maken
void life::schoon ( ) {
  int i, j;

  for ( i = 0; i < hoogte; i++ ) {
    for ( j = 0; j < breedte; j++ ) {
      dewereld[i][j] = false;
    } //for j
  } //for i
} //life::schoon

//Functie om je view te verschuiven
int life::verschuif ( ) {
  int j, i = 0;
  char letterinvoer;

  cout << endl << "Z = Omlaag, W = Omhoog, A = Links, D = Rechts " << endl
       << "Voer een letter in: ";
  letterinvoer = cin.get( );

  //Zolang input een enter is nieuwe input vragen
  while (letterinvoer == '\n') {
    letterinvoer = cin.get( );
  }

  //Switch voor naar links, rechts, boven en onder
  switch (letterinvoer) {

    //Omlaag gaan
    case 'Z': case 'z':
      if (hoogte + omlaag > MAX){
        cout << "Dat lukte niet, de wereldrand wordt "
             << "bereikt met deze verschuiving." << endl;
        omlaag = 1;
      }else{
        cout << omlaag << endl;
        schuif = schuif + omlaag;
        cursorhoogte = cursorhoogte + omlaag;
        hoogte = hoogte + omlaag;
      }
      break;

    //Omhoog gaan
    case 'W': case 'w':
      if (schuif - omhoog < 0){ //BORDER DETECTIE TE SNEL AL BIJ 39 IPV 41!!
        cout << "Dat lukte niet, de wereldrand wordt "
             << "bereikt met deze verschuiving." << endl;
        omhoog = 1;
      }else{
        cout << omhoog << endl;
        schuif = schuif - omhoog;
        cursorhoogte = cursorhoogte - omhoog;
        hoogte = hoogte - omhoog;

      }
      break;

    //Naar links gaan
    case 'A': case 'a':
      if (schuifbreedte - links < 0){
        cout << "Dat lukte niet, de wereldrand wordt "
             << "bereikt met deze verschuiving." << endl;
        links = 1;
      }else{
        schuifbreedte = schuifbreedte - links;
        cursorbreedte = cursorbreedte - links;
        breedte = breedte - links;
      }
      break;

    //Naar rechts gaan
    case 'D': case 'd':
      if (breedte + rechts > MAX){
        cout << "Dat lukte niet, de wereldrand wordt "
             << "bereikt met deze verschuiving." << endl;
        rechts = 1;
      }else{
        schuifbreedte = schuifbreedte + rechts;
        cursorbreedte = cursorbreedte + rechts;
        breedte = breedte + rechts;
      }
      break;
  } //Switch

  return 1;
} //life::verschuiving

//Functie om de groote van elke verschuiving te bepalen
int life::verschuivingsstap ( ) {
  char omlaag_invoer, omhoog_invoer, links_invoer, rechts_invoer;

  //Aantal cellen omlaag gaan
  cout << endl << "Voer in hoeveel u omlaag wil gaan in: ";
  LeesGetal();
  omlaag = getal;
  getal = 0;

  //Aantal cellen omhoog gaan
  cout << "Voer in hoeveel u omhoog wil gaan in: ";
  LeesGetal();
  omhoog = getal;
  getal = 0;

  //Aantal cellen naar rechts gaan
  cout << "Voer in hoeveel u naar rechts wil gaan in: ";
  LeesGetal();
  rechts = getal;
  getal = 0;

  //Aantal cellen naar links gaan
  cout << "Voer in hoeveel u naar links wil gaan in:  ";
  LeesGetal();
  links = getal;
  getal = 0;

  //Naar de verschuif functie
  verschuif( );
  return 1;
} //life::verschuivingsstap

//Functie om view met random cellen te vullen (wordt hier niet afgedrukt)
void life::randomizer ( ) {
  static int randomgetal = 42; //Seed
  int mogelijkheid;
  int i, j;

  for ( i = 0; i < hoogte; i++ ) {
    for ( j = 0; j < breedte; j++ ) {

      //Random getallen genereren
      randomgetal = ( 221 * randomgetal + 1 ) % 1000;

      //De mogelijkheid dat een cel levend is:
      //Doordat je % 1000 doet bij de randomizer zijn er 1000 getallen
      //mogelijk (0 t/m 999). Vervolgens deel je dat door 100 % en
      //vermenigvuldig je het met het opgegeven percentage. Bij een
      //percentage van 100 is mogelijkheid 1000, en dat is dus altijd groter
      //dan je randomgetal (max = 999). Bij percentage van 0 is
      //mogelijkheid 0, en dat is dus nooit groter dan randomgetal (min = 0)
      mogelijkheid = 1000 / 100 * percentage;

      if (randomgetal < mogelijkheid) {
        dewereld[i][j] = true;
      }

      else {
        dewereld[i][j] = false;
      }
    } //for j
  } //for i
} //life::randomizer

//Functie om de cursor levend of dood te maken, en te verplaatsen
void life::toggle ( ) {
  string regel;
  bool error = false;
  char n;
  int i, regellengte = 0;

  cin >> n;
  getline (cin, regel);
  regel = n + regel;
  cout << regel << endl;
  regellengte = regel.length ( );
  cout << regellengte << endl;
  for (i = 0; i < regellengte; i++){

        //cout << "Dat lukte niet probeer de view aan te passen: " << endl;
        if (cursorbreedte >= breedte && breedte <= MAX - 40 ){ // MAX VERSCHUIF TOCH NOG VERDER?!
          schuifbreedte = verschil_breedte + schuifbreedte;
          breedte = breedte + verschil_breedte;
          cout << schuifbreedte << endl;
          cout << breedte << endl;
        }
        if (cursorhoogte <= hoogte){
          schuif = schuif - verschil_hoogte;
          hoogte = hoogte - verschil_hoogte;
        }
        if (cursorbreedte < schuifbreedte){
          schuifbreedte = schuifbreedte - verschil_breedte;
          breedte = breedte - schuifbreedte;
        }
        if (cursorhoogte >= hoogte){
          schuif = schuif + verschil_hoogte;
          hoogte = hoogte + verschil_hoogte;
        }
        //menu();
      //}else{
      switch (regel[i]) {
          case 'T': case 't':
            if(dewereld[cursorhoogte][cursorbreedte]){
              dewereld[cursorhoogte][cursorbreedte] = false;
            }else{
              dewereld[cursorhoogte][cursorbreedte] = true;
            }
            break;
            case 'D': case 'd':
              if (cursorbreedte + 1 >= MAX - 1){
                error == true;
              }else{
                cursorbreedte = cursorbreedte + 1;
              }
              break;
            case 'A': case 'a':
              if (cursorbreedte - 1 <= 0){
                error == true;
              }else{
                cursorbreedte = cursorbreedte - 1;
              }
              break;
            case 'W': case 'w':
              if (cursorhoogte - 1 <= 0){
                error == true;
              }else{
                cursorhoogte = cursorhoogte - 1;
              }
              break;
            case 'Z': case 'z':
              if (cursorhoogte + 1 >= MAX - 1){
                error == true;
              }else{
                cursorhoogte = cursorhoogte + 1;
              }
              break;
        }
    }
      if (error == true){
        cout << "u gaat buiten de wereld" << endl;
      }
}

//Functie om een txt file in te lezen en in de wereld te zeten (zoals glidergun)
void life::file ( ) {
  string eigen_invoer;
  char kar, glidergun[90][90];
  int i = 0, j = 0;
  cout << "Geef uw bestandsnaam op:" << endl;
  cin >> eigen_invoer;
  ifstream invoer (eigen_invoer, ios::in | ios::binary);
  if (invoer.fail ( )){
    cout << "Dit bestand bestaat niet." << endl;
    exit(1);
  }

  cout << eigen_invoer << endl;

  // Main while loop om karakters te printen
  while (! invoer.eof ( )) {
    kar = invoer.get ( );
    if (kar == '\n'){
      i++;
      j = 0;
    }
    if (kar == 'x'){
      dewereld[i][j] = true;
    }else{
    dewereld[i][j] = false;
    }
    j++;
  }
}

//Functie om 1 generatie te doen
void life::een ( ) {
  int LevendeBuren;
  int l, r, b, o, i, j;

  //Backup van de wereld maken, zodat alle cellen tegelijk kunnen
  //worden verandert
  for ( i = 1; i < MAX - 1; i++ ) {
    for ( j = 1; j < MAX - 1; j++ ) {
      reserve[i][j] = dewereld[i][j];
    } //for j
  } //for i

  for ( i = 1; i < MAX - 1; i++ ) {
    for ( j = 1; j < MAX - 1; j++ ) {

      //Links van je huidige cel
      l = i - 1;
      //Rechts van je huidige cel
      r = i + 1;
      //Boven je huidige cel
      b = j - 1;
      //Onder je huidige cel
      o = j + 1;

      //Aantal levende buren resetten
      LevendeBuren = 0;

      //Cel links van huidige cel checken
      if (reserve[l][j]) {
        LevendeBuren++;
      }

      //Cel rechts van huidige cel checken
      if (reserve[r][j]) {
        LevendeBuren++;
      }

      //Cel boven huidige cel checken
      if (reserve[i][b]) {
        LevendeBuren++;
      }

      //Cel onder huidige cel checken
      if (reserve[i][o]) {
        LevendeBuren++;
      }

      //Cel links boven van huidige cel checken
      if (reserve[l][b]) {
        LevendeBuren++;
      }

      //Cel rechts boven van huidige cel checken
      if (reserve[r][b]) {
        LevendeBuren++;
      }

      //cel links onder van huidige cel checken
      if (reserve[l][o]) {
        LevendeBuren++;
      }


      //Cel rechts onder van huidige cel checken
      if (reserve[r][o]) {
        LevendeBuren++;
      }

      //Alle cellen op dood zetten
      dewereld[i][j] = false;

      //Als de cel levend was en 2 of 3 buren heeft, dan blijft hij leven
      if ((reserve[i][j] && LevendeBuren == 2)
          || (reserve[i][j] && LevendeBuren == 3)) {
        dewereld[i][j] = true;

      //Als de cel dood was en 3 buren heeft, dan wordt hij levend
      }else if (! reserve[i][j] && LevendeBuren == 3) {
        dewereld[i][j] = true;
      }

    } //for j
  } //for i
} //life::een

//Functie om meerdere generaties te doen
void life::gaan ( ) {
  int a = 1;

  //Aantal generaties vragen
  cout << endl << "Hoeveel generaties: ";
  LeesGetal( );

  //For loop om alle generaties te printen
  for (a; a <= getal; a++) {
    een ( );
    drukaf ( );
  }

  //Getal resetten (van LeesGetal) zodat die niet wordt opgeslagen
  getal = 0;
}//life::gaan

//Functie om percentage op te vragen
void life::Percentage ( ) {
  cout << endl << "Kies een percentage tussen 0 en 100: ";
  percentage = 1;
  LeesGetal ( );
} //life::Percentage

//Functie om je karakter voor levende en dode cellen te kiezen
void life::karakters ( ) {

  //Karakter voor levende cellen kiezen
  cout << "Kies een karakter voor levende cellen: ";
  kar_levend = cin.get( );

  //Zolang input een enter is nieuwe input vragen
  while (kar_levend == '\n') {
    kar_levend = cin.get( );
  }

  //Karakter voor dode cellen kiezen
  cout << "Kies een karakter voor dode cellen: ";
  kar_dood = cin.get( );

  //Zolang input een enter is nieuwe input vragen
  while (kar_dood == '\n') {
    kar_dood = cin.get( );
  }
} //life::karakters

//Functie om de grootte van je view te bepalen
void life::view ( ) {

  //Hoogte van je view bepalen
  cout << endl << "Voer de hoogte van de view in: ";
  LeesGetal();
  hoogte = getal;
  verschil_hoogte = getal;

  //Verticale positie cursor bepalen
  cursorhoogte = hoogte / 2;
  getal = 0;

  //Breedte van je view bepalen
  cout << "Voer de breedte van de view in: ";
  LeesGetal();
  breedte = getal;
  verschil_breedte = getal;

  //Horizontale positie cursor bepalen
  cursorbreedte = breedte / 2;
  getal = 0;
} //life::view

//Submenu voor parameters
void life::parameters ( ) {
  char letter;
  bool fout; //Check of de input wel een optie is

  cout << endl << "(S)toppen, (V)erschuivingsstap grote, "
       << "Twee verschillende (k)arakters, (P)ercentage, "
       << "(A)anpassen view, (T)erug." << endl;
  cout << "Kies een letter: ";

  letter = cin.get( );

  //Zolang input een enter is nieuwe input vragen
  while (letter == '\n') {
    letter = cin.get( );
}

  while (letter != 'T' && letter != 't'){

    switch (letter) {

      case 'V': case 'v':
        verschuivingsstap ( );
        menu ( );
        fout = false;
        break;

      case 'K': case 'k':
        karakters ( );
        parameters ( );
        fout = false;
        break;

      case 'P': case 'p':
        Percentage ( );
        parameters ( );
        fout = false;
        break;

      case 'A': case 'a':
        view ( );
        parameters ( );
        fout = false;
        break;

      case 'S': case 's':
        exit(1);
    } // switch

    // Als de input geen optie is dit printen en opnieuw submenu weergeven
    if (fout == true) {
     cout << "Geen optie!" << endl << endl;
     parameters ( );
  }

    //Fout check resetten
    fout = true;
    cout << endl;
  } // while

  //Terug naar het menu als input T of t is
  menu ( );
  return;
} //life::parameters

//Functie voor hoofdmenu
void life::menu ( ) {
  char letter;
  bool fout; //Check of de input wel een optie is

  //Cursor coordinaten weergeven
  cout << endl << "Cursor Coordinaten:" << "(" << cursorbreedte << ", "
  << cursorhoogte << ")" << endl;

  //Eerst de view printen, daarna opnieuw het menu weergeven
  drukaf( );

  cout << "(S)toppen, (H)eelschoon, S(c)hoon, "
       << "(V)erschuif, (P)arameters, (R)andom, "
       << "(T)oggle, (F)ile, (E)en, (G)aan." << endl;
  cout << "Kies een letter: ";

  letter = cin.get( );

  //Zolang input een enter is nieuwe input vragen
  while (letter == '\n') {
    letter = cin.get( );
  }

  while (letter != 'S' && letter != 's'){

    switch (letter) {

      case 'H': case 'h':
        heelschoon ( );
        menu ( );
        fout = false;
        break;

      case 'C': case 'c':
        schoon ( );
        menu ( );
        fout = false;
        break;

      case 'V': case 'v':
        verschuif ( );
        menu ( );
        fout = false;
        break;

      case 'P': case 'p':
        parameters ( );
        fout = false;
        break;

      case 'R': case 'r':
        randomizer ( );
        menu ( );
        fout = false;
        break;

      case 'T': case 't':
        toggle ( );
        menu ( );
        fout = false;
        break;

      case 'F': case 'f':
        file ( );
        menu ( );
        fout = false;
        break;

      case 'E': case 'e':
        een ( );
        menu ( );
        fout = false;
        break;

      case 'G': case 'g':
        gaan ( );
        menu ( );
        fout = false;
        break;
    } // switch

    // Als de input geen optie is dit printen en opnieuw hoofdmenu weergeven
    if (fout == true) {
      cout << "Geen optie!" << endl << endl;
      menu ( );
    }

    //Fout check resetten
    fout = true;
    cout << endl;
  } // while

  //Stoppen als input S of s is
  cout << "Stop" << endl;
  exit(1);
} //life::menu

//Main functie om de code te runnen, begint met de functie menu runnen
int main ( ) {
  life M;
  M.menu ( );
} //main
