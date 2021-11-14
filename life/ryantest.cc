#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

class life {
  public:
    life ( ) {
      hoogte = 25;
      breedte = 80;
      cursorhoogte = hoogte / 2;
      cursorbreedte = breedte / 2;

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
    static const int MAX = 1000;
    bool dewereld[MAX][MAX]; // array!!!
    bool reserve[MAX][MAX];
    int hoogte, breedte;
    int percentage;
    int schuif = 0;
    int schuifbreedte = 0;
    int omlaag = 1;
    int omhoog = 1;
    int rechts = 1;
    int links = 1;
    int getal = 0;
    char kar_levend = 'X';
    char kar_dood = ' ';
    int cursorhoogte, cursorbreedte;
};

void life::drukaf ( ){
  int i = 0, j = 0;
  for ( i = schuif; i < hoogte; i++ ) { // hij start dus bij i = 1
    for ( j = schuifbreedte; j < breedte; j++ ) {

      if (i == MAX - 1 || i == 0 || j == MAX - 1 || j == 0 ) {
        dewereld[i][j] = false;
        cout << "=";
      }else if (dewereld[i][j]) { //BOVEN DE LIJN METEEN ALLEEN MAAR XSJES
        if (i == cursorhoogte && j == cursorbreedte){
          cout << "#";
        }else{
          cout << kar_levend;
        }
      }
      else {
        if (i == cursorhoogte && j == cursorbreedte){
          cout << "$";
        }else{
          cout << kar_dood;
        }
      }

    }//for j
  cout << endl;
  }//for i
cout << endl;
}//life::drukaf

void life::LeesGetal ( ) {
  char kar;

  kar = cin.get ( );
  if (percentage != 1){
    while (kar == '\n'){
      kar = cin.get( );
    }
    while (kar !='\n'){
      if ('0' <= kar && kar <= '9' && getal < 1000) {
        getal= 10 * getal + (kar - '0');
      }
      kar = cin.get( );
    }
  }else{
    percentage = 0;
    kar = cin.get( );
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

}


void life::heelschoon ( ) {
  int i, j;
  for ( i = 0; i < MAX; i++ ) { // hij start dus bij i = 1
    for ( j = 0; j < MAX; j++ ) {
      dewereld[i][j] = false;
    }
  }
}

void life::schoon ( ) {
  int i, j;
  for ( i = 0; i < hoogte; i++ ) { // hij start dus bij i = 1
    for ( j = 0; j < breedte; j++ ) {
      dewereld[i][j] = false;
    }//for j
  }//for i
}


int life::verschuif ( ) {
  int j, i = 0;
  char letterinvoer;
  cout << endl << "Z = Omlaag, W = Omhoog, A = Links, D = Rechts " << endl
       << "Voer een letter in: ";
  letterinvoer = cin.get( );
  while (letterinvoer == '\n') {
    letterinvoer = cin.get( );
  }
  switch (letterinvoer) {

    case 'Z': case 'z':
      if (hoogte + omlaag > MAX){
        cout << "Dat lukte niet, de wereldrand wordt bereikt met deze verschuiving." << endl;
        omlaag = 1;
      }else{
        schuif = schuif + omlaag;
        cursorhoogte = cursorhoogte + omlaag;
        hoogte = hoogte + omlaag;
      }
      break;

    case 'W': case 'w':
      if (schuif - omhoog < 0){ //BORDER DETECTIE TE SNEL AL BIJ 39 IPV 41!!
        cout << "Dat lukte niet, de wereldrand wordt bereikt met deze verschuiving." << endl;
        omhoog = 1;
      }else{
        schuif = schuif - omhoog;
        cursorhoogte = cursorhoogte - omhoog;
        hoogte = hoogte - omhoog;

      }
      break;

    case 'A': case 'a':
      if (schuifbreedte - links < 0){
        cout << "Dat lukte niet, de wereldrand wordt bereikt met deze verschuiving." << endl;
        links = 1;
      }else{
        schuifbreedte = schuifbreedte - links;
        cursorbreedte = cursorbreedte - links;
        breedte = breedte - links;
      }
      break;

    case 'D': case 'd':
      if (breedte + rechts > MAX){
        cout << "Dat lukte niet, de wereldrand wordt bereikt met deze verschuiving." << endl;
        rechts = 1;
      }else{
        schuifbreedte = schuifbreedte + rechts;
        cursorbreedte = cursorbreedte + rechts;
        breedte = breedte + rechts;
      }
      break;
    }

return 1;
}

int life::verschuivingsstap ( ) {
  char omlaag_invoer, omhoog_invoer, links_invoer, rechts_invoer;
  cout << endl << "Voer in hoeveel u omhoog wil gaan in: ";
  LeesGetal();
  omlaag = getal;
  getal = 0;

  cout << "Voer in hoeveel u omlaag wil gaan in: ";
  LeesGetal();
  omhoog = getal;
  getal = 0;

  cout << "Voer in hoeveel u naar rechts wil gaan in: ";
  LeesGetal();
  rechts = getal;
  getal = 0;

  cout << "Voer in hoeveel u naar links wil gaan in:  ";
  LeesGetal();
  links = getal;
  getal = 0;

  verschuif( );
  return 1;
}

void life::randomizer ( ) {
  static int randomgetal;                                                           //Check ff of dit mag bitch
  srand(randomgetal);
  int mogelijkheid;
  int i, j;

    for ( i = 0; i < hoogte; i++ ) {
      for ( j = 0; j < breedte; j++ ) {

          randomgetal = ( 221 * randomgetal + 1 ) % 1000;
          mogelijkheid = 1000 / 100 * percentage;

          if (randomgetal < mogelijkheid) {
            dewereld[i][j] = true;
          }

          /*
          if (percentage != 0) {
            dewereld[i][j] = ((randomgetal % 100) <= percentage);
          }
          */

          else {
            dewereld[i][j] = false;
          }
        }
      }
}

void life::toggle ( ) {

  /*
  string regel;
  char n;
  int i, regellengte = 0;
  cin >> n;
  getline (cin, regel);
  regel = n + regel;
  cout << regel << endl;
  regellengte = regel.length ( );
  cout << regellengte << endl;
  for (i = 0; i < regellengte; i++){
    if (cursorbreedte + 1 >= breedte || cursorhoogte + 1 >= hoogte ||
      cursorhoogte - 1 <= schuif || cursorbreedte - 1 <= schuifbreedte){
        //cout << "Dat lukte niet probeer de view aan te passen: " << endl;
        if (cursorbreedte >= breedte && cursorbreedte < (breedte / 2) - MAX){
          schuifbreedte = 80 + schuifbreedte;
        }
        if (cursorhoogte >= hoogte && cursorhoogte < (hoogte / 2) - MAX){
          schuif = 25 + schuif;
        }
        if (cursorbreedte <= schuifbreedte && cursorbreedte > (breedte / 2)){
          schuifbreedte = schuifbreedte - 80;
        }
        if (cursorhoogte >= hoogte && cursorhoogte < (hoogte / 2) ){
          schuif = schuif - 25;
        }
        //menu();
      }else{
      switch (regel[i]) {
          case 'T': case 't':
            if(dewereld[cursorhoogte][cursorbreedte]){
              dewereld[cursorhoogte][cursorbreedte] = false;
            }else{
              dewereld[cursorhoogte][cursorbreedte] = true;
            }
            break;
            case 'D': case 'd':
              cursorbreedte = cursorbreedte + 1;
              break;
            case 'A': case 'a':
              cursorbreedte = cursorbreedte - 1;
              break;
            case 'W': case 'w':
              cursorhoogte = cursorhoogte - 1;
              break;
            case 'Z': case 'z':
              cursorhoogte = cursorhoogte + 1;
              break;
        }
    }
  }

  */
}

void life::file ( ) {

  /*
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
  */
}

void life::een ( ) {
  int LevendeBuren;
  int l, r, b, o, i, j;


  for ( i = 1; i < MAX - 1; i++ ) {
    for ( j = 1; j < MAX - 1; j++ ) {
      reserve[i][j] = dewereld[i][j];
    }
  }

  for ( i = 1; i < MAX - 1; i++ ) {
    for ( j = 1; j < MAX - 1; j++ ) {

      l = i + 1;
      r = i - 1;
      b = j + 1;
      o = j - 1;

      LevendeBuren = 0;

      if (reserve[l][j]) {
        LevendeBuren++;
      }

      if (reserve[r][j]) {
        LevendeBuren++;
      }

      if (reserve[i][b]) {
        LevendeBuren++;
      }

      if (reserve[i][o]) {
        LevendeBuren++;
      }

      if (reserve[l][b]) {
        LevendeBuren++;
      }

      if (reserve[r][b]) {
        LevendeBuren++;
      }

      if (reserve[l][o]) {
        LevendeBuren++;
      }

      if (reserve[r][o]) {
        LevendeBuren++;
      }

      dewereld[i][j] = false;

      if ((reserve[i][j] && LevendeBuren == 2) || (reserve[i][j] && LevendeBuren == 3)) {
        dewereld[i][j] = true;
      }else if (! reserve[i][j] && LevendeBuren == 3) {
        dewereld[i][j] = true;
      }

    }
  }

}

void life::gaan ( ) {
  int a = 1;

  cout << endl << "Hoeveel iteraties: ";
  LeesGetal( );

  for (a; a <= getal; a++) {
    een ( );
    drukaf ( );
  }

  getal = 0;
}

void life::Percentage ( ) {
  cout << endl << "Kies een percentage tussen 0 en 100: ";
  percentage = 1;
  LeesGetal ( );

}

void life::karakters ( ) {
  cout << "Kies een karakter voor levende cellen: ";
  kar_levend = cin.get( );
  while (kar_levend == '\n') {
    kar_levend = cin.get( );
  }
  cout << "Kies een karakter voor dode cellen: ";
  kar_dood = cin.get( );
  while (kar_dood == '\n') {
    kar_dood = cin.get( );
  }

}

void life::view ( ) {
  cout << endl << "Voer de hoogte van de view in: ";
  LeesGetal();
  hoogte = getal;
  cursorhoogte = hoogte / 2;
  getal = 0;

  cout << "Voer de breedte van de view in: ";
  LeesGetal();
  breedte = getal;
  cursorbreedte = breedte / 2;
  getal = 0;
}


void life::parameters ( ) {
  char letter;
  bool fout;

  cout << endl << "(S)toppen, (V)erschuivingsstap grote, "
       << "Twee verschillende (k)arakters, (P)ercentage, "
       << "(A)anpassen view, (T)erug." << endl;

  cout << "Kies een letter: ";

  letter = cin.get( );

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
    if (fout == true) {
     cout << "Geen optie!" << endl << endl;
     parameters ( );
  }

    fout = true;
    cout << endl;

  } // while

  menu ( );
  return;

} // void menu

void life::menu ( ) {
  char letter;
  bool fout;
  // life L;

  cout << endl << "Cursor Coordinaten:" << "(" << cursorbreedte << ", "
  << cursorhoogte << ")" << endl;

  drukaf( );

  cout << "(S)toppen, (H)eelschoon, S(c)hoon, "
       << "(V)erschuif, (P)arameters, (R)andom, "
       << "(T)oggle, (F)ile, (E)en, (G)aan." << endl;

  cout << "Kies een letter: ";

  letter = cin.get( );

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

    if (fout == true) {
      cout << "Geen optie!" << endl << endl;
      menu ( );
    }

    fout = true;
    cout << endl;

  } // while

  cout << "Stop" << endl;
  exit(1);

} // void menu


int main ( ) {
  life M;
  M.menu ( );
}
