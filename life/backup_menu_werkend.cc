#include <iostream>
using namespace std;

class life {
  public:
    life ( ) {
      hoogte = 4;
      breedte = 4;

    }
    void drukaf ( );
    void heelschoon ( );
    void schoon ( );
    int verschuif ( );
    void verschuivingsstap ( );
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
    static const int MAX = 1000;
    bool dewereld[1][1]; // array!!!
    bool reserve[3][4];
    int hoogte, breedte;
    int percentage, schuif = 0;
    int schuifbreedte = 0;
};

void life::drukaf ( ){
  int i, j;
  for ( i = schuif; i < hoogte; i++ ) { // hij start dus bij i = 1
    for ( j = schuifbreedte; j < breedte; j++ ) {
      if ( dewereld[i][j] ) {
        cout << "X ";
      }
      else {
        cout << "O ";
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

  cout << "Getal: " << percentage << endl << endl;
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
        cout << "O ";
    }//for j
  cout << endl;
  }//for i
cout << endl;
}

int life::verschuif ( ) {
  int j, i = 0, omlaag = 1, omhoog = 1, links = 1, rechts = 1;
  char letterinvoer;
  letterinvoer = cin.get( );
  while (letterinvoer == '\n') {
    letterinvoer = cin.get( );
  }
  switch (letterinvoer) {

    case 'S': case 's':
      schuif = schuif + omlaag;
      hoogte = hoogte + omlaag;
      break;

    case 'W': case 'w':
      schuif = schuif - omhoog;
      hoogte = hoogte - omhoog;
      break;

    case 'L': case 'l':
      schuifbreedte = schuifbreedte - links;
      breedte = breedte - links;
      break;

    case 'R': case 'r':
      schuifbreedte = schuifbreedte + rechts;
      breedte = breedte + rechts;
      break;
    }
  drukaf();

return 1;
}




void life::verschuivingsstap ( ) {
  char omlaag, omhoog, rechts, links;

  cout << "voer in hoeveel u omlaag wil gaan in" << endl;
  omlaag = cin.get( );
  while (omlaag == '\n') {
    omlaag = cin.get( );
  }
  schuif = schuif + omlaag - '0';

  cout << "voer in hoeveel u omhoog wil gaan in" << endl;
  omhoog = cin.get( );
  while (omhoog == '\n') {
    omhoog = cin.get( );
  }
  schuif = schuif - omhoog - '0';

  cout << "voer in hoeveel u rechts wil gaan in" << endl;
  rechts = cin.get( );
  while (rechts == '\n') {
    rechts = cin.get( );
  }
  schuifbreedte = schuifbreedte + rechts - '0';

  cout << "voer in hoeveel u links wil gaan in" << endl;
  links = cin.get( );
  while (links == '\n') {
    links = cin.get( );
  }
  schuif = schuifbreedte - links - '0';


}

void life::Percentage ( ) {
  cout << "Kies een percentage tussen 1 en 100: ";
  LeesGetal ( );

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

    if (fout == true) {
      cout << "Geen optie!" << endl << endl;
    }

    fout = true;

    cout << "Kies een letter: " << endl;
    letter = cin.get( );

    while (letter == '\n') {
      letter = cin.get( );
    }

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

    drukaf( );
}

void life::toggle ( ) {

}

void life::glidergun ( ) {

}

void life::een ( ) {

}

void life::gaan ( ) {

}

void life::menu ( ) {
  char letter;
  bool fout;
  // life L;
  cout << "S = Stoppen, H = Heelschoon, C = Schoon, " << endl
       << "V = Verschuif, P = Parameters, R = Random, " << endl
       << "T = Toggle, L = Glidergun, E = Een, G = Gaan." << endl << endl;

  while (letter != 'S' && letter != 's'){

    switch (letter) {

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

    if (fout == true) {
      cout << "Geen optie!" << endl << endl;
    }

    fout = true;

    cout << "Kies een letter: ";
    letter = cin.get( );

    while (letter == '\n') {
      letter = cin.get( );
    }

  } // while

  cout << "Stop" << endl;

} // void menu


int main ( ) {
  life M;
  M.drukaf ( );
  M.menu ( );
}
