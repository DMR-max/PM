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

  private:
    static const int MAX = 1000;
    bool dewereld[1][1]; // array!!!
    bool reserve[3][4];
    int hoogte, breedte;
    int percentage, schuif;
};

void life::drukaf ( ){
  int i, j;
  for ( i = 0; i < hoogte; i++ ) { // hij start dus bij i = 1
    for ( j = 0; j < breedte; j++ ) {
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

void LeesGetal ( ) {
  char kar;
  int getal = 0;

  kar = cin.get ( );

  while (kar != '\n') {
    if ('0' <= kar && kar <= '9') {
      getal = 10 * getal + (kar - '0');
    }
    kar = cin.get( );
  }
  cout << "Getal: " << getal << endl;
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
  int j, i, ingv;
  char omlaag;

  cout << "voer in hoeveel u omlaag wil gaan in" << endl;
  omlaag = cin.get( );
  while (omlaag == '\n') {
    omlaag = cin.get( );
  }
  cout << omlaag << endl;
  hoogte = hoogte + omlaag;
  i = 0;
  i = omlaag;
  for ( i; i < hoogte; i++ ) { // hij start dus bij i = 1
    for ( j = 0; j < breedte; j++ ) {
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
return 1;
}




void life::verschuivingsstap ( ) {


}

void life::Percentage ( ) {
  //int percentage;
  //cout << "Vul een getal tussen 1 en 100 in: " << LeesGetal ( );

}


void life::parameters ( ) {
  char letter;
  bool fout;

  cout << "S = Stoppen, V = Verschuivingsstap grote, " << endl
       << "K = Twee versch karakters, P = Percentage." << endl << endl;

  while (letter != 'T' && letter != 't'){

    switch (letter) {

      case 'V': case 'v':
        cout << "Verschuiving" << endl << endl;
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

  return;
} // void submenu

void life::randomizer ( ) {

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
