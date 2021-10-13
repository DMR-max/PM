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
  bool commentaar;
  int d, diepte = 0;
  cin >> d;
  while ( ! invoer.eof ( ) ) {
    if (kar == '/' && kar_vorige == '/'){
      commentaar = true;
    }
    if (kar == '/' && kar_vorige != '/'){
     commentaar = false;
    }

    if (commentaar){
      if (kar == '\n'){
        commentaar = false;
      }
    }

   if (kar_vorige == '{'){
      diepte++;
    }
    if (kar == '}'){
      diepte--;
    }
    if (diepte > 0 && kar_vorige == '\n'){
      cout << diepte << endl;
      cout << d << endl;
      for (int i=0; i < diepte * d; i++){
        uitvoer.put(' ');
      }
    }
    if(! commentaar){
      uitvoer.put(kar);
    }
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
}




int main ( ){
  infoblokje ( );
  copy ( );
}
