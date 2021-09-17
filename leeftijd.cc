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
    int leeftijd_in_maand;
    tm s;
    time_t t;

    time (&t);
    s = * localtime (&t);
    int cdag = s.tm_mday;
    int cmaand = s.tm_mon + 1; // 0 voor januari
    int cjaar = s.tm_year + 1900; // vanaf 1900

    cout << "In welk jaar ben je geboren: ";
    cin >> jaar;

    if (jaar > cjaar - 10){
      cout << "Je bent te jong.";
      return 0;
    }
    else{
      if (jaar < cjaar - 100){
        cout << "Je bent te oud.";
        return 0;
      }
      else{
        cout << "In welke maand ben je geboren: ";
        cin >> maand;

        if (jaar == cjaar - 10 && maand > cmaand){
          cout << "Je bent te jong.";
          return 0;
        }
        else{
          if (jaar == cjaar - 100 && maand < cmaand){
            cout << "Je bent te oud.";
            return 0;
          }
          else{
            cout << "Op welke dag ben je geboren: ";
            cin >> dag;

            if (jaar == cjaar - 10 && maand == cmaand && dag > cdag){
              cout << "Je bent te jong.";
              return 0;
            }
            else{
              if (jaar == cjaar - 100 && maand == cmaand && dag < cdag + 1){
                cout << "Je bent te oud.";
                return 0;
              }
              else{
              leeftijd_jaar = cjaar - jaar;
              leeftijd_maand = cmaand - maand;
              if(cdag == dag){
                cout << "gefeliciteerd je bent maandig" << endl;
              }
              if (leeftijd_maand == 0){
              leeftijd_dag = cdag - dag;
              if (leeftijd_dag >= 0){
                leeftijd_in_maand = (leeftijd_jaar * 12) + maand + leeftijd_maand;
                cout << leeftijd_in_maand << endl;
                cout << leeftijd_jaar << endl; //je bent .. jaar oud
                if (leeftijd_dag == 0){
                cout << "gefeliciteerd je bent jarig." << endl;
                }
              }
            }else{
              if (leeftijd_maand > 0){
                leeftijd_in_maand = (leeftijd_jaar * 12) + maand + leeftijd_maand;
                cout << leeftijd_in_maand << endl;
                cout << leeftijd_jaar << endl; //je bent .. jaar oud
            }else{
            leeftijd_jaar = leeftijd_jaar - 1;
            leeftijd_in_maand = (leeftijd_jaar * 12) + maand + leeftijd_maand;
            cout << leeftijd_in_maand << endl;
            cout << leeftijd_jaar << endl; //je bent .. jaar oud
              }
            }
                //Hier verder met code!

              }
            }
          }
        }
      }
    }



return 0;
}
