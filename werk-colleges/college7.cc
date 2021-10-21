#include <iostream>
using namespace std;

void opdracht_2( ){
  char letter;

  cout << "Kies een letter (P): ";
  cin >> letter;

  while (letter != 'T' && letter != 't'){
    switch (letter) {
      case 'C': case 'c':
        cout << "C" << endl;
        break;
      case 'R': case 'r':
        cout << "R" << endl;
        break;
      case 'P': case 'p':
        cout << "P" << endl;
        break;
      case 'S': case 's':
        exit(1);
    } // switch

    cout << "Kies een letter (P): ";
    cin >> letter;
  } // while

  return;
}

void opdracht_1 ( ) {
  char letter;

  cout << "Kies een letter: ";
  cin >> letter;

  while (letter != 'S' && letter != 's'){
    switch (letter) {
      case 'C': case 'c':
        cout << "C" << endl;
        break;
      case 'R': case 'r':
        cout << "R" << endl;
        break;
      case 'P': case 'p':
        cout << "P" << endl;
        opdracht_2 ( );
        break;
    } // switch

    cout << "Kies een letter: ";
    cin >> letter;
  } // while
  cout << "stop";
} // void opdracht_1

void opdracht_3 ( ) {
  char kar;
  kar = cin.get( );

  while (kar == '\n') {
    kar = cin.get( );
  }
} //void opdracht_3

void opdracht_4( ){
  char kar;
  kar = cin.get( );
  int getal = 0;
  bool check;

  while (kar == '\n') {
    check = false;
    kar = cin.get( );
  } // while
  while (!check && kar !='\n'){
    if ('0' <= kar && kar <= '9' && getal * 10 < 1000) {
      getal = 10 * getal + (kar - '0');
    }
    kar = cin.get( );

  }
  cout << "Getal: " << getal << endl;


} // void

int main ( ) {
  //opdracht_1 ( );
  //opdracht_3 ( );
  opdracht_4 ( );
}
