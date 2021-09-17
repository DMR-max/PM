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
    int aantal_jaren;
    int aantal_maanden;
    int maand2;
    int maand3;
    int maand4;
    int totaal;
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
              if (leeftijd_maand == 0){
              leeftijd_dag = cdag - dag;
              if (leeftijd_dag >= 0){                   // Je bent jarig en maandig
                leeftijd_in_maand = (leeftijd_jaar * 12) + maand + leeftijd_maand;
                cout << "Je bent " << leeftijd_in_maand << " maanden oud." << endl;
                cout << "Je bent " << leeftijd_jaar << " jaar oud." << endl;
                cout << "gefeliciteerd je bent maandig" << endl;
                if (leeftijd_dag == 0){
                cout << "gefeliciteerd je bent jarig." << endl;
                }
              }else{                                  // Je bent maandig
                leeftijd_jaar = leeftijd_jaar - 1;
                leeftijd_in_maand = (leeftijd_jaar * 12) + maand + leeftijd_maand;
                cout <<  "Je bent " << leeftijd_in_maand << " maanden oud." << endl;
                cout <<  "Je bent " << leeftijd_jaar << " jaar oud." << endl;
                cout << "gefeliciteerd je bent maandig" << endl;
              }
            }else{                                   // Bent al jarig geweest
              if (leeftijd_maand > 0){
                leeftijd_in_maand = (leeftijd_jaar * 12) + maand + leeftijd_maand;
                cout <<  "Je bent " << leeftijd_in_maand << " maanden oud." << endl;
                cout <<  "Je bent " << leeftijd_jaar << " jaar oud." << endl;
            }else{                                  // Bent nog niet jarig geweest
            leeftijd_jaar = leeftijd_jaar - 1;
            leeftijd_in_maand = (leeftijd_jaar * 12) + maand + leeftijd_maand;
            cout <<  "Je bent " << leeftijd_in_maand << " maanden oud." << endl;
            cout <<  "Je bent " << leeftijd_jaar << " jaar oud." << endl;
              }
            }
                //Hier verder met code! nog rekening houden met schikkeljaren!
                aantal_jaren = (jaar - 1901) * 365; // aantal dagen voor de jaren
                aantal_maanden = (maand - 1) * 31; // aantal dagen voor de maanden (te veel)
                maand2 = maand / 2; // kijken hoeveel maanden met 30 ipv 31 dagen
                if (maand == 2 || maand == 4 || maand == 6 || maand == 9 || maand == 11){ // voor alle even 30 dagen maanden
                  if (maand > 2){ // nog geen rekening met 28 dagen in feb
                maand3 = aantal_maanden - 1 - maand2;
              } else{ // wel rekening met 28 dagen in feb
                  maand3 = aantal_maanden + 1 - maand2; // te veel dagen afhalen zodat het klopt
                }
                cout << "maanden: " << maand3 << endl; // kan weg uiteindelijk
              } else{
                if (maand > 2){ // nog geen rekening met 28 dagen in feb
                maand3 = aantal_maanden - 2 - maand2;
              } else{ // wel rekening met 28 dagen in feb
                maand3 = aantal_maanden - maand2; // te veel dagen afhalen zodat het klopt
              }
                cout << "maanden: " << maand3 << endl; // kan uiteindelijk weg
              }
                totaal = aantal_jaren + maand3 + dag; // alle dagen bij elkaar optellen

                cout << totaal;

              }
            }
          }
        }
      }
    }



return 0;
}
