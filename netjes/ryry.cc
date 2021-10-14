#include <iostream>
#include <fstream>
using namespace std;

/*
Auteurs: Sjouk Ketwaru en Ryan Sleeuwaegen
naam bestand: KetwaruSleeuwaegen.cc
*Beschrijving van t bestand*
text editor: Atom, compiler: MinGW.
Laatst aan gewerkt op: .
*/

void infoblokje ( ) {
  cout << "Makers: Sjouk Ketwaru (s3287297), "
  << "Ryan Sleeuwaegen (s3122166)" << endl
  << "Jaar van aankomst: 2021" << endl
  << "Studierichting: Kunstmatige Intelligentie" << endl
  << "opgave 2, gemaakt op 18-10-2021" << endl
  << "Dit is een programma dat een foutloos te compileren C++-programma "
  << "een klein beetje probeert te begrijpen." << endl << endl;
}

void copy ( ) {
  ifstream invoer ("invoer.txt", ios::in | ios::binary);
  ofstream uitvoer ("uitvoer.txt", ios::out | ios::binary);
  char kar = invoer.get ( );
  char kar_vorige;
  char kar_vorige2;
  bool commentaar;
  bool tabs;
  bool letters;
  bool nr;
  int d, diepte = 0;
  char a, b, c;

  cout << "Aantal spaties: ";
  cin >> d;

  cout << "Vul een letter in: ";
  cin >> a;
  cout << "Vul een letter in: ";
  cin >> b;
  cout << "Vul een letter in: ";
  cin >> c;

  while (!letters){
    if (a < 97 || a > 122 || b < 97 || b >122 || c < 97 || c > 122 ||
    a == b || a == c || b == c) {
      cout << "er is iets fout" << endl;
      cout << "Vul een letter in: ";
      cin >> a;
      cout << "Vul een letter in: ";
      cin >> b;
      cout << "Vul een letter in: ";
      cin >> c;
    } else{
      letters = true;
      }
  }

  while (! invoer.eof ( )) {
    if ((kar_vorige2 == a || kar_vorige2 == a - 32) &&  // ipv - 32 een functie maken
    (kar_vorige == b || kar_vorige == b - 32) &&
    (kar == c || kar == c - 32)){
      cout << "letter combinatie gevonden" << endl;
    }

    if (kar == '/' && kar_vorige == '/'){
      commentaar = true;
    }

    if (kar == '/' && kar_vorige != '/'){
     commentaar = false;
    }

    if (kar != '/' && kar_vorige == '/' && kar_vorige2 != '/'){
      uitvoer.put('/');
    }

    if (commentaar && kar == '\n'){
        commentaar = false;
    }


    if (kar_vorige == '\n' && kar == ' '){
      nr = true;
      uitvoer.put('F');
    }

    if (nr && kar != ' '){
      nr = false;
      uitvoer.put('S');
    }



   if (kar_vorige == '{' && ! commentaar){
      diepte++;
    }

    if (kar == '}' && ! commentaar){
      diepte--;
    }

    if (kar_vorige == '\n'){
      cout << diepte << endl;

      for (int i=0; i < diepte * d; i++){
        uitvoer.put(' ');
      }
    }

    if(! commentaar && kar != '/' && !nr){
      uitvoer.put(kar);
    }

    kar_vorige2 = kar_vorige;
    kar_vorige = kar;
    kar = invoer.get();

  /*  if (kar == '\n' && kar_vorige == '{'){
      diepte++;
      cout << diepte << endl;
      cout << d << endl;
    }
    if (kar_vorige == '}'){
      diepte--;
    }

    for (int i; i < diepte * d; i++){
      uitvoer.put(' ');
    }
    //if (! commentaar && diepte > 0){

  //  }

  //  if (commentaar == true){ // comments mist een slash
    //  while(kar != '\n'){
    //   uitvoer.put(' ');
    //   kar = invoer.get ( );
    //  }
    //  commentaar = false;
  //  }
  /*   if (inspringen == true){ //inspringen niet werkend
      uitvoer.put('\n');
        for(int i; i < diepte; i++){
          uitvoer.put(' ');
        }
    } */
    //for (int i; i < d; i++){
    //}
    }

    if (diepte != 0){
      cout << "Niet goed gegaan" << endl;
    }
}

int main ( ){
  infoblokje ( );
  copy ( );
}
