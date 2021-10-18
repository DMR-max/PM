/*
Auteurs: Sjouk Ketwaru en Ryan Sleeuwaegen
naam bestand: KetwaruSleeuwaegen2.cc

Het programmma maakt een begin aan het compileren
van een C++ programma. Al het commentaar dat begint
met // wordt verwijdert. De gebruiker kan
aangeven hoeveel spaties elke tab inspringt. De gebruiker
geeft een 3 letter combinatie, en het programma kijkt
hoe vaak die combinatie voor komt. Er wordt gecontroleerd
of het collatz vermoeden waar is voor alle getallen.

Text editor: Atom (ubuntu), Compiler: G++.
Laatst aan gewerkt op: 17-10-2021.
*/



#include <iostream>
#include <fstream>
#include <climits>
#include <string>
using namespace std;

// Functie met alle informatie over de makers en het programma
void infoblokje ( ) {
  cout << "Makers: Sjouk Ketwaru (s3287297), "
  << "Ryan Sleeuwaegen (s3122166)" << endl
  << "Jaar van aankomst: 2021" << endl
  << "Studierichting: Kunstmatige Intelligentie" << endl
  << "Opgave 2, gemaakt op 18-10-2021" << endl
  << "Dit is een programma dat een foutloos te compileren C++programma " << endl
  << "een klein beetje probeert te begrijpen." << endl
  << "Commentaar wordt weggelaten. De gebruiker moet aangeven " << endl
  << "hoeveel spaties een tab is. De gebruiker moet 3 letters " << endl
  << "invoeren, en er wordt gecontroleerd hoe vaak die combinatie "<< endl
  << "voor komt. Als laatst wordt voor elk getal gecontroleerd of " << endl
  << "Collatz vermoeden waar is." << endl << endl;
} // Void infoblokje

// Functie om commentaar te filteren
void comments (ofstream & uitvoer, char & kar,
  char & kar_vorige, char & kar_vorige2, bool & commentaar) {

  // Commentaar begint
  if (kar == '/' && kar_vorige == '/') {
    commentaar = true;
  }

  // Normaal geen / printen, tenzij er GEEN / voor of achter staat
  if (kar != '/' && kar_vorige == '/' && kar_vorige2 != '/') {
    uitvoer.put ('/');
  }

  // Commentaar eindigt
  if (commentaar && kar == '\n') {
      commentaar = false;
  }
} // Void comments

// Funcite om tabs toe te voegen en spaties weg te halen
void tabs (char & kar, char & kar_vorige, bool & nr,
  int & diepte, ofstream & uitvoer, bool & commentaar, int & d) {

  // Spatie / tab aan begin regel detecteren
  if (kar_vorige == '\n' && (kar == ' ' || kar == '\t')) {
    nr = true;
  }

  // Eind van spaties aan het begin van regel detecteren
  if (nr && kar != ' ' && kar != '\t') {
   nr = false;
  }

  // { Detecteren en 1 er bij optellen
  if (kar_vorige == '{' && ! commentaar) {
    diepte++;
  }

  // } Detecteren en 1 er van af halen
  if (kar == '}' && ! commentaar) {
    diepte--;
  }

  // Spaties voor tabs printen
  if (kar_vorige == '\n') {

    for (int i=0; i < diepte * d; i++) {
      uitvoer.put (' ');
    }
  }
} // Void tabs

// Functie voor 3 letters vragen
void letterinvoer (char & a, char & b, char & c, bool & letters) {

  cout << "Vul aub 3 verschillende kleine letters in (1 per keer)." << endl;
  cout << "Vul een letter in: ";
  cin >> a;
  cout << "Vul een letter in: ";
  cin >> b;
  cout << "Vul een letter in: ";
  cin >> c;
  cout << endl;

  // Letters vragen tot alle letters verschillend zijn en kleine letters zijn
  while (!letters) {
    if (a < 97 || a > 122 || b < 97 || b > 122 || c < 97 || c > 122 ||
    a == b || a == c || b == c) {
      cout << "Er is iets fout!" << endl;
      cout << "Vul aub 3 verschillende kleine letters in (1 per keer)." << endl;
      cout << "Vul een letter in: ";
      cin >> a;
      cout << "Vul een letter in: ";
      cin >> b;
      cout << "Vul een letter in: ";
      cin >> c;
      cout << endl;
    } else {
      letters = true;
      }
  } // While
} // Void letterinvoer

// Functie om 3 gevraagde letters ook te detecteren als er hoofdletters zijn
void convertie (char & a, char & b, char & c, char & kar,
  char & kar_vorige, char & kar_vorige2, int & aantal_letters) {

  // Hoofdletters en kleine letters detecteren voor 3 letter combinatie
  if ((kar_vorige2 == a || kar_vorige2 == a - 32) &&
  (kar_vorige == b || kar_vorige == b - 32) &&
  (kar == c || kar == c - 32)) {
    aantal_letters++;
  }
} // Void convertie

// Functie om Collatz vermoeden te berekenen en getallen te detecteren
void collatz (char & kar_vorige, char & kar, int & getal,
  int & iteraties, bool & commentaar) {

  // Loop totdat gehele getal is gedetecteerd
  if ('0' <= kar_vorige && kar_vorige <= '9' && ! commentaar) {
    getal = 10 * getal + (kar_vorige - '0');
    if (! ('0' <= kar && kar <= '9')) {
      cout << "Getal: " << getal << endl;

      //Loop om Collatz vermoeden te berekenen
      while (getal != 1 && getal > 0 && getal <= INT_MAX) {

        if (getal % 2 == 0) {
          getal = getal / 2;
          iteraties++;
        } else {
            getal = 3 * getal + 1;
            iteraties++;
          }
      } // While

      // Print het uiteindelijke getal en aantal iteraties om dat te betrijken
      cout << "Eindgetal: " << getal << endl;
      cout << "Iteraties: " << iteraties << endl;

      if ( getal != 1) {
        cout << "Boven INT_MAX of getal = 0 dus gestopt." << endl;
      }
      cout << endl;
      // Reset aantal iteraties en getal voor het volgende getal
      getal = 0;
      iteraties = 0;
    } // Tweede if (r. 129)
  } // Eerste if (r. 125)
} // Void collatz

// Functie om invoer en uitvoer file te openen
void filenaam (string & eigen_invoer,
  string & eigen_uitvoer, ifstream & invoer) {

  cout << "Voer de naam van het invoer bestand in (.txt niet invullen): ";
  cin >> eigen_invoer;
  eigen_invoer = eigen_invoer + ".txt";
  invoer.open (eigen_invoer.c_str ( ));
  if (invoer.fail ( )){
    cout << "Dit bestand bestaat niet." << endl;
    exit(1);
  }
  cout << "Voer de naam van het uitvoer bestand in (.txt niet invullen): ";
  cin >> eigen_uitvoer;
  eigen_uitvoer = eigen_uitvoer + ".txt";
  cout << endl;
}

// Functie met de grote while loop en alle andere functies waarin
// alles wordt gecontroleerd en wordt geprint in het uitvoer bestand
void hoofdvoid ( ) {
  // Eigen textbestanden
  string eigen_invoer;
  string eigen_uitvoer;
  ifstream invoer (eigen_invoer, ios::in | ios::binary);

  filenaam(eigen_invoer, eigen_uitvoer, invoer);

  // Bestand maken of bestand
  ofstream uitvoer (eigen_uitvoer, ios::out | ios::binary);
  // Karakters inlezen, en de vorige 2 karakters
  char kar;
  char kar_vorige, kar_vorige2;
  // Booleans om loops aan en uit te zetten (nr = nieuwe regel)
  bool commentaar, letters, nr;
  // d is door de gebruiker ingevulde aantal spaties
  int d, diepte = 0, getal = 0, iteraties = 0, aantal_letters = 0;
  // de 3 door de gebruiker ingevulde letters
  char a, b, c;


  cout << "Aantal spaties voor een tab: ";
  cin >> d;
  cout << endl;

  letterinvoer (a, b, c, letters);
  kar = invoer.get ( );

  // Main while loop om karakters te printen
  while (! invoer.eof ( )) {

    convertie (a, b, c, kar, kar_vorige, kar_vorige2, aantal_letters);
    comments (uitvoer, kar, kar_vorige, kar_vorige2, commentaar);
    tabs (kar, kar_vorige, nr, diepte, uitvoer, commentaar, d);
    collatz (kar_vorige, kar, getal, iteraties, commentaar);

    // Hier mogen de meeste karakters pas worden geprint
    // Commentaar, slashes (worden eerder al geprint als er geen /
    // voor of achter staat) en spaties / tabs aan het begin van
    // een regel worden niet geprint
    if(! commentaar && kar != '/' && ! nr){
      uitvoer.put (kar);
    }

    // karakters worden geupdate
    kar_vorige2 = kar_vorige;
    kar_vorige = kar;
    kar = invoer.get ( );
  } // While

  cout << "Aantal letter combinaties: " << aantal_letters << endl << endl;

  // Check of er even veel { als } zijn
  if (diepte != 0){
    cout << "Niet goed gepaarde accolades!" << endl;
  } else{
    cout << "Goed gepaarde accolades!" << endl;
  }
} // Void hoofdvoid

int main ( ){
  infoblokje ( );
  hoofdvoid ( );
} // Int main
