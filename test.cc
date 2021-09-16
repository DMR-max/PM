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

    cout <<"In welk jaar ben je geboren: ";
    cin >> jaar;

    if (jaar > cjaar - 10 && jaar < cjaar){
        cout << "Sorry je bent te jong.";
}else{
      if (jaar < cjaar - 100){
      cout << "Sorry je bent te oud.";
    }else{
        cout <<"In welke maand ben je geboren: ";
        cin >> maand;
      }
        if (jaar == cjaar - 10 && maand < cmaand){
        cout << "Sorry je bent net te jong.";
      } else{
          if (jaar == cjaar + 100 && maand > cmaand){
          cout << "Sorry je bent net te oud.";
        }else{
        cout <<"Op welke dag ben je geboren: ";
        cin >> dag;
      }
        if (jaar == cjaar - 10 && maand == cmaand && dag < cdag){
        cout << "Sorry je bent echt net te jong.";
      }else{
          if  (jaar == cjaar + 100 && maand == cmaand && dag > cdag - 1){
          cout << "Sorry je bent echt net te oud.";
        }

          else{
          cout << "Je bent zo oud:";
        }
        }
      }

  cin >> dag;
  leeftijd_jaar = cjaar - jaar;
  leeftijd_maand = cmaand - maand;
  if (leeftijd_maand >= 0){
  leeftijd_dag = cdag - dag;
  if (leeftijd_dag >= 0){
    leeftijd_jaar = leeftijd;
  }else{
    leeftijd_jaar = leeftijd - 1;
  }

}
  else{
  return 1;
}
}
return 0;
}
