#include <iostream>
#include <stdlib.h>
using namespace std;

class life {
  public:
    life ( ) {
      hoogte = 20;
      breedte = 20;

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

  private:
    static const int MAX = 20;
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
};

void life::drukaf ( ){
  int i, j;

  for ( i = schuif; i < hoogte; i++ ) { // hij start dus bij i = 1
    for ( j = schuifbreedte; j < breedte; j++ ) {

      if (i == MAX - 1 || i == 0 || j == MAX - 1 || j == 0) {
        dewereld[i][j] = false;
        reserve[i][j] = false;
        cout << "= ";
      }else if (dewereld[i][j]) {
        cout << "X ";
      }
      else {
        cout << "  ";
      }
    }//for j
  cout << endl;
  }//for i
cout << endl;
}//life::drukaf

void life::LeesGetal ( ) {
  char kar;
  percentage = 0;

  cin.get ( );

  while (kar !='\n'){
    if ('0' <= kar && kar <= '9' && percentage * 10 < 101) {
      percentage = 10 * percentage + (kar - '0');
    }
    kar = cin.get( );
  }

  if (percentage > 100 && percentage < 110) {
    percentage = percentage / 10;
  }
}

void life::heelschoon ( ) {
  int i, j;
  for ( i = 0; i < MAX; i++ ) { // hij start dus bij i = 1
    for ( j = 0; j < MAX; j++ ) {
      dewereld[i][j] = false;
    }
  }
  drukaf( );
}

void life::schoon ( ) {
  int i, j;
  for ( i = 0; i < hoogte; i++ ) { // hij start dus bij i = 1
    for ( j = 0; j < breedte; j++ ) {
        dewereld[i][j] = false;
    }//for j
  }//for i
  drukaf( );
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
      schuif = schuif + omlaag;
      hoogte = hoogte + omlaag;
      cout << schuif << endl;
      break;

    case 'W': case 'w':
      schuif = schuif - omhoog;
      hoogte = hoogte - omhoog;
      break;

    case 'A': case 'a':
      schuifbreedte = schuifbreedte - links;
      breedte = breedte - links;
      break;

    case 'D': case 'd':
      schuifbreedte = schuifbreedte + rechts;
      breedte = breedte + rechts;
      break;
    }
    cout << hoogte << endl;
    cout << breedte << endl;
    cout << schuif << endl;
    cout << schuifbreedte << endl;
  drukaf( );

return 1;
}

int life::verschuivingsstap ( ) {
  char omlaag_invoer, omhoog_invoer, links_invoer, rechts_invoer;
  cout << "voer in hoeveel u omlaag wil gaan in" << endl;
  omlaag_invoer = cin.get( );
  while (omlaag_invoer == '\n') {
    omlaag_invoer = cin.get( );
  }
  omlaag = omlaag_invoer - '0';

  cout << "voer in hoeveel u omhoog wil gaan in" << endl;
  omhoog_invoer = cin.get( );
  while (omhoog_invoer == '\n') {
    omhoog_invoer = cin.get( );
  }
  omhoog = omhoog_invoer - '0';

  cout << "voer in hoeveel u rechts wil gaan in" << endl;
  rechts_invoer = cin.get( );
  while (rechts_invoer == '\n') {
    rechts_invoer = cin.get( );
  }
  rechts = rechts_invoer - '0';

  cout << "voer in hoeveel u links wil gaan in" << endl;
  links_invoer = cin.get( );
  while (links_invoer == '\n') {
    links_invoer = cin.get( );
  }
  links = links_invoer - '0';

  verschuif( );

  return 1;
}

void life::Percentage ( ) {
  cout << "Kies een percentage van 0 tot en met 100: ";
  LeesGetal ( );

  cout << endl;
}


void life::parameters ( ) {
  char letter;
  bool fout;

  cout << "(S)toppen, (V)erschuivingsstap grote, "
       << "Twee verschillende (k)arakters, (P)ercentage, "
       << "(T)erug." << endl << endl;

  while (letter != 'T' && letter != 't'){

    switch (letter) {

      case 'V': case 'v':
        verschuivingsstap ( );
        parameters ( );
        fout = false;
        break;

      case 'K': case 'k':
        parameters ( );
        fout = false;
        break;

      case 'P': case 'p':
        Percentage ( );
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

    cout << "Kies een letter: ";
    letter = cin.get( );

    while (letter == '\n') {
      letter = cin.get( );
    }

    cout << endl;

  } // while

  menu ( );
  return;
} // void submenu

void life::randomizer ( ) {
  static int randomgetal;                                                           //Check ff of dit mag bitch
  srand(randomgetal);
  int mogelijkheid;
  int i, j;

    for ( i = 0; i < hoogte; i++ ) {
      for ( j = 0; j < breedte; j++ ) {

          randomgetal = ( 221 * randomgetal + 1 ) % 1000;
          mogelijkheid = 10 * percentage;


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

    drukaf( );
}

void life::toggle ( ) {

}

void life::glidergun ( ) {

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

      if (dewereld[l][j]) {
        LevendeBuren++;
      }

      if (dewereld[r][j]) {
        LevendeBuren++;
      }

      if (dewereld[i][b]) {
        LevendeBuren++;
      }

      if (dewereld[i][o]) {
        LevendeBuren++;
      }

      if (dewereld[l][b]) {
        LevendeBuren++;
      }

      if (dewereld[r][b]) {
        LevendeBuren++;
      }

      if (dewereld[l][o]) {
        LevendeBuren++;
      }

      if (dewereld[r][o]) {
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

  drukaf( );

}

void life::gaan ( ) {
  int loop, a = 1;

  cout << "Hoeveel iteraties: ";
  cin >> loop;                                                                    // aanpassen

  for (a; a <= loop; a++) {
    een ( );
  }

}

void life::menu ( ) {
  char letter;
  bool fout;
  // life L;
  cout << "(S)toppen, (H)eelschoon, S(c)hoon, "
       << "(V)erschuif, (P)arameters, (R)andom, "
       << "(T)oggle, (F)ile, (E)en, (G)aan." << endl << endl;

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
        menu ( );
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
        glidergun ( );
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

    cout << "Kies een letter: ";
    letter = cin.get( );

    while (letter == '\n') {
      letter = cin.get( );
    }

    cout << endl;

  } // while

  cout << "Stop" << endl;

} // void menu


int main ( ) {
  life M;
  M.drukaf ( );
  M.menu ( );
}
