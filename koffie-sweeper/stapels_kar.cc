#include <iostream>
#include "stapel.h"
using namespace std;

void stapel::zetopstapel (char karakter) { // push
  vakje * temp = new vakje;
  temp->info = karakter;
  temp->volgende = bovenste;
  bovenste = temp;
  cout << temp << endl;

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
void stapel::haalvanstapel ( char & karakter, int breedte, int hoogte ) { // pop
  int teller;
  vakje * temp = bovenste;
  karakter = bovenste->info;
  bovenste = bovenste->volgende;
  teller = 1;
  while (breedte*hoogte > teller){

    /*if (!temp -> geopend) {
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

    temp = temp -> buren[2]; */
    karakter = bovenste->info;
    bovenste = bovenste->volgende;
    cout << karakter << endl;
    teller ++;
  }

}//stapel::haalvanstapel

stapel::~stapel ( ) {
  int getal;

  bordvakje * temp = getal;
  temp->info = getal;
  temp->volgende = bovenste;
  bovenste = temp;




































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



#include <iostream>
#include "stapel.h"
using namespace std;

void stapel::zetopstapel (bordvakje * getal, char karakter) { // push
  cout << "getal van te voren" << getal << endl;
  bordvakje * temp_kar = getal;
  temp_kar->info_kar = karakter;
  temp_kar->volgende = bovenste_kar;
  bovenste_kar = temp_kar;
  cout << karakter << endl;
  cout << getal << endl;

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
void stapel::haalvanstapel (char & karakter, int breedte, int hoogte) { // pop
  bordvakje * temp = bovenste;
  bovenste = bovenste->info_kar;
  //bovenste = bovenste->volgende;
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
}//stapel::haalvanstapel

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

#include <iostream>
#include "stapel.h"
using namespace std;

void stapel::zetopstapel (bordvakje * getal, char karakter) { // push
  bordvakje * temp_kar = new bordvakje;
  temp_kar->info_kar = karakter;
  temp_kar->volgende = bovenste_kar;
  bovenste_kar = temp_kar;

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
void stapel::haalvanstapel (int breedte, int hoogte) { // pop
  bordvakje * temp = bovenste_kar;
  char karakter;
  int teller;
  int h = 1;
  int hoogte_meter = 1;
  /*cout << bovenste_kar << endl;
  karakter = bovenste_kar ->info_kar;
  bovenste_kar = bovenste_kar->volgende; */
  teller = 0;
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
      }
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
