#include <iostream>
using namespace std;
int u = 8;
int v = 12;
int antwoord;
int macht;
double nummer;
int b, z, a, i, len;
int getal;

void infoblokje(){
  cout << "makers: Sjouk Ketwaru (s3287297),"
  << "Ryan Sleeuwaegen (s3122166)" << endl;
  cout << "jaar van aankomst: 2021" << endl;
  cout << "studierichting: Kunstmatige Intelligentie" << endl;
  cout << "opgave 1, gemaakt op 23-09-2021" << endl;
  cout << "Dit is een test om aangenomen te worden "
  << "aan de universiteit." << endl;
}

int telop (int x, int y){
  antwoord = x + y;
  return antwoord;
}

void telop2(int x, int y, int & z){
  z = x + y;
}

//void telop3(int x1, int x2, int y1, int y2, int & z1, int & z2){
  //z1 = (x1 * y2) + (y1 * x2);
  //z2 = x2 * y2;
//}

int main ( ) {
  infoblokje();

  telop(11,12);
  telop(u,v);
  cout << telop(11,12) << endl;
  u = telop(11,12);
  cout << u << endl;

  telop2(11, 12, z);
  cout << z << endl << endl;

  //telop3(1, 6, 1, 5);
  //cout << z1 << "/" << z2 << endl;

  cin >> macht;
  cin >> nummer;
  for (i = 0; i != macht;){
    a = nummer * nummer;
    i++;
  }
  cout << a << endl;
  cin >> getal;
  if(getal>0){
    for (len=0; getal>0; len++){
      getal = getal / 10;
    }
  }
  cout << len << endl;


  cout << getal << endl;
  return 0;
}//main
