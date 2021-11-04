#include <iostream>
using namespace std;

void heelschoon ( ) {

}

void schoon ( ) {

}

void verschuif ( ) {

}

void verschuivingsstap ( ) {


}

void Percentage ( ) {

}


void parameters ( ) {
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

void randomizer ( ) {

}

void toggle ( ) {

}

void glidergun ( ) {

}

void een ( ) {

}

void gaan ( ) {

}

void menu ( ) {
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
  menu ( );
}
