#include <iostream>
#include <ctime>
using namespace std;

int main ( ) {
    int jaar;
    int maand;
    int dag;
    int leeftijd_dag;
    int leeftijd_jaar;
    int leeftijd_maand;
    int leeftijd;
    tm s;
    time_t t;

    time (&t);
    s = * localtime (&t);
    int cdag = s.tm_mday;
    int cmaand = s.tm_mon + 1; // 0 voor januari
    int cjaar = s.tm_year + 1900; // vanaf 1900
    cin >> jaar;
    cin >> maand;
  cin >> dag;
  leeftijd_jaar = cjaar - jaar;
  leeftijd_maand = cmaand - maand;
  if (leeftijd_maand == 0){
  leeftijd_dag = cdag - dag;
  if (leeftijd_dag >= 0){
    cout << leeftijd_jaar << endl;
    cout << "gefeliciteerd je bent maandig" << endl;
  }else{
    leeftijd_jaar = leeftijd_jaar - 1;
    cout << leeftijd_jaar << endl;
  }
}else{
  if (leeftijd_maand > 0){
    cout << leeftijd_jaar << endl;
}else{
leeftijd_jaar = leeftijd_jaar - 1;
cout << leeftijd_jaar << endl;
  }
}

return 0;

}
