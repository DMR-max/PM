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
      cursorhoogte = 12;
      cursorbreedte = 40;

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
    void glidergun ( );
    void een ( );
    void gaan ( );
    void menu ( );
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
  cout << "cursor coordinaten:" << "(" << cursorbreedte << ", "
  << cursorhoogte << ")" << endl;
  for ( i = schuif; i < hoogte; i++ ) { // hij start dus bij i = 1
    for ( j = schuifbreedte; j < breedte; j++ ) {

      if (i == MAX - 1 || i == 0 || j == MAX - 1 || j == 0) {
        dewereld[i][j] = false;
        cout << "=";
      }else if (dewereld[i][j]) { //BOVEN DE LIJN METEEN ALLEEN MAAR XSJES
        cout << kar_levend;
        if (i == cursorhoogte && j == cursorbreedte){
          cout << "#";
        }
      }
      else {
        cout << kar_dood;
        if (i == cursorhoogte && j == cursorbreedte){
          cout << "$";
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
    while (kar !='\n'){
      if ('0' <= kar && kar <= '9' && percentage * 10 < 101) {
        percentage = 10 * percentage + (kar - '0');
      }
      kar = cin.get( );
    }

    if (percentage > 100 && percentage < 110) {
      percentage = percentage / 10;
    }

    cout << "percentage: " << percentage << endl << endl;

  }
}

void life::heelschoon ( ) {
  int i, j;
  for ( i = 0; i < MAX; i++ ) { // hij start dus bij i = 1
    for ( j = 0; j < MAX; j++ ) {
      dewereld[i][j] = false;
    }
  }
  menu( );
}

void life::schoon ( ) {
  int i, j;
  for ( i = 0; i < hoogte; i++ ) { // hij start dus bij i = 1
    for ( j = 0; j < breedte; j++ ) {
      dewereld[i][j] = false;
    }//for j
  }//for i
  menu( );
}


int life::verschuif ( ) {
  int j, i = 0;
  char letterinvoer;
  cout << "voer een letter in: S = omlaag, W = omhoog, A = links, D = rechts" << endl;
  letterinvoer = cin.get( );
  while (letterinvoer == '\n') {
    letterinvoer = cin.get( );
  }
  switch (letterinvoer) {

    case 'S': case 's':
      if(hoogte + omlaag > MAX ){
        cout << "Dat lukte niet, de wereldrand wordt bereikt met deze verschuiving" << endl;
        omlaag = 1;
      }else{
        schuif = schuif + omlaag;
        cursorhoogte = cursorhoogte + omlaag;
        hoogte = hoogte + omlaag;
      }
      break;

    case 'W': case 'w':
      if(hoogte - omhoog < 0 ){ //BORDER DETECTIE TE SNEL AL BIJ 39 IPV 41!!
        cout << "Dat lukte niet, de wereldrand wordt bereikt met deze verschuiving" << endl;
        omhoog = 1;
      }else{
        schuif = schuif - omhoog;
        cursorhoogte = cursorhoogte - omhoog;
        hoogte = hoogte - omhoog;

      }
      break;

    case 'A': case 'a':
      if(breedte - links < 0 ){
        cout << "Dat lukte niet, de wereldrand wordt bereikt met deze verschuiving" << endl;
        links = 1;
      }else{
        schuifbreedte = schuifbreedte - links;
        cursorbreedte = cursorbreedte - links;
        breedte = breedte - links;
      }
      break;

    case 'D': case 'd':
      if(breedte + rechts > MAX ){
        cout << "Dat lukte niet, de wereldrand wordt bereikt met deze verschuiving" << endl;
        rechts = 1;
      }else{
        schuifbreedte = schuifbreedte + rechts;
        cursorbreedte = cursorbreedte + rechts;
        breedte = breedte + rechts;
      }
      break;
    }
  menu( );

return 1;
}

int life::verschuivingsstap ( ) {
  char omlaag_invoer, omhoog_invoer, links_invoer, rechts_invoer;
  cout << "voer in hoeveel u omlaag wil gaan in" << endl;
  LeesGetal();
  omlaag = getal;
  getal = 0;

  cout << "voer in hoeveel u omhoog wil gaan in" << endl;
  LeesGetal();
  omhoog = getal;
  getal = 0;

  cout << "voer in hoeveel u rechts wil gaan in" << endl;
  LeesGetal();
  rechts = getal;
  getal = 0;

  cout << "voer in hoeveel u links wil gaan in" << endl;
  LeesGetal();
  links = getal;
  getal = 0;

  verschuif( );
  return 1;
}

void life::Percentage ( ) {
  cout << "Kies een percentage tussen 1 en 100: ";
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


void life::parameters ( ) {
  char letter;
  bool fout;

  cout << "S = Stoppen, V = Verschuivingsstap grote, " << endl
       << "K = Twee versch karakters, P = Percentage, " << endl
       << "T = Terug." << endl << endl;

  while (letter != 'T' && letter != 't'){

    switch (letter) {

      case 'V': case 'v':
        cout << "Verschuiving" << endl << endl;
        verschuivingsstap ( );
        fout = false;
        break;

      case 'K': case 'k':
        cout << "Karakters" << endl << endl;
        karakters ( );
        fout = false;
        break;

      case 'P': case 'p':
        cout << "Percentage" << endl << endl;
        Percentage ( );
        fout = false;
        break;

      case 'S': case 's':
        cout << "Stop" << endl;
        exit(1);

    } // switch
    cout << "Kies een letter: " << endl;
    letter = cin.get( );

    while (letter == '\n') {
      letter = cin.get( );
    }

    if (fout == true) {
      cout << "Geen optie!" << endl << endl;
    }

    fout = true;


  } // while

    cout << "Terug" << endl << endl;

  return;
} // void submenu

void life::randomizer ( ) {
  static int randomgetal = 42;
  int i, j;
  int mogelijkheid;

    for ( i = 0; i < hoogte; i++ ) {
      for ( j = 0; j < breedte; j++ ) {

          randomgetal = ( 221 * randomgetal + 1 ) % 1000;
          mogelijkheid = 10 * percentage;

          if (randomgetal < mogelijkheid) {
            dewereld[i][j] = true;
          }

          else {
            dewereld[i][j] = false;
          }
        }
      }

    menu( );
}

void life::toggle ( ) {

}

void life::glidergun ( ) {
  string eigen_invoer;
  char kar, glidergun[90][90];
  int i = 0, j = 0;
  cout << "geef uw bestandsnaam op voor de glidergun" << endl;
  cin >> eigen_invoer;
  ifstream invoer (eigen_invoer, ios::in | ios::binary);
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
    }
    j++;


  }
  menu();

}

void life::een ( ) {
  int LevendeBuren;
  int a, b, i, j;
  bool buur;


  for ( i = 0; i < MAX; i++ ) {
    for ( j = 0; j < MAX; j++ ) {
      reserve[i][j] = dewereld[i][j];
    }
  }

  for ( i = 0; i < MAX; i++ ) {
    for ( j = 0; j < MAX; j++ ) {

      LevendeBuren = 0;
      buur = true;

      for (a = i - 1; a <= i + 1; a++) {
        for (b = i - 1; b <= j + 1; b++) {

          if (a < 0 || a > MAX || b < 0 || b > MAX){
            buur = false;
          }

          if (a == i && b == j) {
            buur = false;
          }

          if (buur && reserve[a][b]) {
            LevendeBuren++;
          }

        }
      }


      cout << i << ", " << j << ": Buren: " << LevendeBuren;
      if (reserve[i][j]) {
        cout << " Wereld: X ";
      }

      else {
        cout << " Wereld: O ";
      }

      cout << "Reserve: " << a << ", " << b << endl;


      if (LevendeBuren == 3) {
        dewereld[i][j] = true;
      }else if (LevendeBuren != 2) {
        dewereld[i][j] = false;
      }

    }
  }

  menu( );

}

void life::gaan ( ) {

}

void life::menu ( ) {
  char letter;
  bool fout;
  // life L;
  drukaf( );
  cout << "S = Stoppen, H = Heelschoon, C = Schoon, " << endl
       << "V = Verschuif, P = Parameters, R = Random, " << endl
       << "T = Toggle, L = Glidergun, E = Een, G = Gaan." << endl << endl;

  while (letter != 'S' && letter != 's'){

    switch (letter) {
      case 'K':
        cout << "voer getal in:" << endl;
        LeesGetal( );
        fout = false;
        break;

      case 'H': case 'h':
        cout << "Heelschoon" << endl << endl;
        heelschoon ( );
        fout = false;
        break;

      case 'C': case 'c':
        cout << "Schoon" << endl << endl;
        schoon ( );
        fout = false;
        break;

      case 'V': case 'v':
        cout << "verschuif" << endl << endl;
        verschuif ( );
        fout = false;
        break;

      case 'P': case 'p':
        cout << "Parameters" << endl << endl;
        parameters ( );
        fout = false;
        break;

      case 'R': case 'r':
        cout << "Random" << endl << endl;
        randomizer ( );
        fout = false;
        break;

      case 'T': case 't':
        cout << "Toggle" << endl << endl;
        toggle ( );
        fout = false;
        break;

      case 'L': case 'l':
        cout << "Glidergun" << endl << endl;
        glidergun ( );
        fout = false;
        break;

      case 'E': case 'e':
        cout << "Een" << endl << endl;
        een ( );
        fout = false;
        break;

      case 'G': case 'g':
        cout << "Gaan" << endl << endl;
        gaan ( );
        fout = false;
        break;

    } // switch

    cout << "Kies een letter: ";
    letter = cin.get( );

    while (letter == '\n') {
      letter = cin.get( );
    }

    if (fout == true) {
      cout << "Geen optie!" << endl << endl; //ERROR GEEN OPTIE
    }

    fout = true;

  } // while

  cout << "Stop" << endl;

} // void menu


int main ( ) {
  life M;
  M.menu ( );
}
