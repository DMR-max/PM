#include <iostream>
#include "stapel.h"
using namespace std;

void stapel::zetopstapel (bordvakje * koffiebord) { // push
  bordvakje * temp = new bordvakje;
  temp->info = koffiebord;
  temp->volgende = bovenste;
  bovenste = temp;
  cout << koffiebord -> geopend << endl;

  /*bordvakje * temp = getal;
  temp->info = getal;
  temp->volgende = bovenste;
  bovenste = temp; */

  // Printen y-coords
  //if (temp == nullptr && bovenste != nullptr) {
    //cout << endl << h % 10 << '\t';
    //h++;

    //temp = bovenste;
    //bovenste = temp -> buren[4];
  //}
//}
  //printf("%d\n", getal);

}//stapel::zetopstapel
void stapel::haalvanstapel (bordvakje * koffiebord, int breedte, int hoogte) { // pop
  bordvakje* temp = bovenste;
  koffiebord = bovenste->info;
  bovenste = bovenste->volgende;
  int teller = 0;
  while (breedte*hoogte > teller){
    cout << bovenste << endl;
    teller ++;
  }
  //delete temp;
}

//stapel::haalvanstapel

stapel::~stapel ( ) {
  int getal;
  //while ( ! isstapelleeg ( ) ){
    //haalvanstapel (getal);
  //}
}//stapel::~stapels

/*int main ( ) {
  //stapel S;
  int getal;
  cout << "geef getal op:" << endl;
  cin >> getal;
  //cout << buren[2] << endl;
  //S.zetopstapel(getal);
  //S.haalvanstapel(getal);
  cout << getal << endl;
  return 0;
}; */

/*bordvakje * temp = bovenste_kar;
char karakter;
int teller;
int h = 1;
int hoogte_meter = 1;
/*cout << bovenste_kar << endl;
karakter = bovenste_kar ->info_kar;
bovenste_kar = bovenste_kar->volgende; */
/*teller = 0;
for (int b = 0; b < breedte; b++) {
  if (b == 0){
    cout << '\t' << b % 10 << ' ';
  }else{
    cout << b % 10 << ' ';
  }
}
cout << endl << endl << "0" << '\t';
  while (breedte*hoogte > teller){
    karakter = bovenste_kar->info_kar;
    bovenste_kar = bovenste_kar->volgende;
    cout << karakter << " ";
    if (h == breedte && hoogte_meter != hoogte){
      cout << endl << hoogte_meter % 10 << '\t';
      h = 0;
      hoogte_meter++;
      /*if (hoogte_meter == hoogte - 1){
        h = 1;
      }else{
        h = 1;
      }*/
    /*}
    teller ++;
    h++;
  }

/*  while (bovenste_kar != nullptr) {



    if (!bovenste_kar -> geopend) {
      if (!bovenste_kar -> gemarkeerd) {
        //if (bovenste_kar -> koffie && zetten ==1) {
          //aantal_koffie++;
        //}
       cout << ". ";
      }
      else {
        cout << "# ";
      }
    }
    else if (bovenste_kar -> koffie) {
      cout << "K ";
    }
    else {
      cout << bovenste_kar -> aantal << " ";
    }

    bovenste_kar = bovenste_kar -> buren[2];

    // Printen y-coords
    if (bovenste_kar == nullptr) {
      cout << endl << h % 10 << '\t';
      h++;

    }*/



/*for (int i = 0; i < 1; i++){
//while (bovenste != nullptr){

  if (!temp -> geopend) {
    if (!temp -> gemarkeerd) {
      //if (temp -> koffie && zetten ==1) {
        //aantal_koffie++;
      //}
      cout << ". ";
    }
    else {
      cout << "# ";
    }
  }
  else if (temp -> koffie) {
    cout << "K ";
  }
  else {
    cout << temp -> aantal << " ";
  }

  temp = temp -> buren[2];
  //getal = bovenste->info;
  bovenste = bovenste->volgende;
}*/

/*int teller;
bordvakje * temp_kar = bovenste_kar;
karakter = bovenste_kar->info_kar;
bovenste_kar = bovenste_kar->volgende;
teller = 1;

while (breedte*hoogte > teller){
  karakter = bovenste_kar->info_kar;
  bovenste_kar = bovenste_kar->volgende;
  cout << karakter << endl;
  teller ++;
}*/
