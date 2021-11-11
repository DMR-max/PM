#include <iostream>
using namespace std;

class life {
  public:
    life ( ) {
      hoogte = 6;
      breedte = 6;

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
    static const int MAX = 6;
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
        cout << "= ";
      }else if (dewereld[i][j]) {
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

  drukaf( );

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
