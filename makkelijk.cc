#include <iostream>
#include <ctime>
#include <math.h>
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
    int schikkel;
    int welke_dag;
    char geborte_dag;
    char geborte_dag2;
    char juiste_dag;
    char juiste_dag2;
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
            cout << endl;

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
                cout << "Je bent " << leeftijd_jaar << " jaar oud." << endl << endl;
                cout << "gefeliciteerd je bent maandig." << endl << endl;
                if (leeftijd_dag == 0){
                cout << "gefeliciteerd je bent jarig." << endl << endl;
                }
              }else{                                  // Je bent maandig
                leeftijd_jaar = leeftijd_jaar - 1;
                leeftijd_in_maand = (leeftijd_jaar * 12) + maand + leeftijd_maand;
                cout <<  "Je bent " << leeftijd_in_maand << " maanden oud." << endl;
                cout <<  "Je bent " << leeftijd_jaar << " jaar oud." << endl << endl;
                cout << "gefeliciteerd je bent maandig." << endl << endl;
              }
            }else{                                   // Bent al jarig geweest
              if (leeftijd_maand > 0){
                leeftijd_in_maand = (leeftijd_jaar * 12) + maand + leeftijd_maand;
                cout <<  "Je bent " << leeftijd_in_maand << " maanden oud." << endl;
                cout <<  "Je bent " << leeftijd_jaar << " jaar oud." << endl << endl;
            }else{                                  // Bent nog niet jarig geweest
            leeftijd_jaar = leeftijd_jaar - 1;
            leeftijd_in_maand = (leeftijd_jaar * 12) + maand + leeftijd_maand;
            cout <<  "Je bent " << leeftijd_in_maand << " maanden oud." << endl;
            cout <<  "Je bent " << leeftijd_jaar << " jaar oud." << endl << endl;
              }
            }
                //Hier verder met code! nog rekening houden met schikkeljaren!
                aantal_jaren = (jaar - 1901) * 365; // aantal dagen voor de jaren

                schikkel = (jaar - 1901) / 4 - 1;

                if (maand == 1){
                  aantal_maanden = 0;
                }
                if (maand == 2){
                  aantal_maanden = 31;
                }
                if (maand == 3){
                  aantal_maanden = 59;
                }
                if (maand == 4){
                  aantal_maanden = 90;
                }
                if (maand == 5){
                  aantal_maanden = 120;
                }
                if (maand == 6){
                  aantal_maanden = 151;
                }
                if (maand == 7){
                  aantal_maanden = 181;
                }
                if (maand == 8){
                  aantal_maanden = 212;
                }
                if (maand == 9){
                  aantal_maanden = 243;
                }
                if (maand == 10){
                  aantal_maanden = 273;
                }
                if (maand == 11){
                  aantal_maanden = 304;
                }
                if (maand == 12){
                  aantal_maanden = 334;
                }

                totaal = aantal_jaren + aantal_maanden + schikkel + dag;

                welke_dag = totaal % 7; // kijken welke dag het is
                cout << "Op wat voor dag ben je geboren, ";
                cout << "vul de eerste letter in voor: " << endl;
                cout << "maandag, woensdag, vrijdag." << endl;
                cout << "Vul de eerste 2 letters in voor:" << endl;
                cout << "dinsdag, donderdag, zaterdag, zondag." << endl;
                cout << "(Geen hoofdletters)";
                cout << "(vul de letters appart in per regel)" << endl;

                // welke_dag = 0 = dinsdag
                // welke_dag = 1 = woensdag etc.


                // check of ingevulde dag klopt, moet nog gedaan worden!
                cin >> geborte_dag;

                if (welke_dag == 0 || welke_dag == 2 || welke_dag == 4 || welke_dag == 5){
                cin >> geborte_dag2;
              }

                if (welke_dag == 0){
                  juiste_dag = 'd';
                  juiste_dag2 = 'i';
                }

                if (welke_dag == 1){
                  juiste_dag = 'w';
                  juiste_dag2 = 'o';
                }

                if (welke_dag == 2){
                  juiste_dag = 'd';
                  juiste_dag2 = 'o';
                }

                if (welke_dag == 3){
                  juiste_dag = 'v';
                  juiste_dag2 = 'r';
                }

                if (welke_dag == 4){
                  juiste_dag = 'z';
                  juiste_dag2 = 'a';
                }

                if (welke_dag == 5){
                  juiste_dag = 'z';
                  juiste_dag2 = 'o';
                }

                if (welke_dag == 6){
                  juiste_dag = 'm';
                  juiste_dag2 = 'a';
                }

                if (juiste_dag == 'd' && juiste_dag2 == 'i'){
                  if (geborte_dag == juiste_dag && geborte_dag2 == juiste_dag2){
                    cout << "Je hebt het goed!";
                  } else {
                    cout << "Je hebt het fout!";
                    return 1;
                  }
                }

                if (juiste_dag == 'd' && juiste_dag2 == 'o'){
                  if (geborte_dag == juiste_dag && geborte_dag2 == juiste_dag2){
                    cout << "Je hebt het goed!";
                  } else {
                    cout << "Je hebt het fout!";
                    return 1;
                  }
                }

                if (juiste_dag == 'z' && juiste_dag2 == 'a'){
                  if (geborte_dag == juiste_dag && geborte_dag2 == juiste_dag2){
                    cout << "Je hebt het goed!";
                  } else {
                    cout << "Je hebt het fout!";
                    return 1;
                  }
                }

                if (juiste_dag == 'z' && juiste_dag2 == 'o'){
                  if (geborte_dag == juiste_dag && geborte_dag2 == juiste_dag2){
                    cout << "Je hebt het goed!";
                  } else {
                    cout << "Je hebt het fout!";
                    return 1;
                  }
                }

                if (juiste_dag == 'm' || juiste_dag == 'w' || juiste_dag == 'v'){
                  if (geborte_dag == juiste_dag){
                    cout << "Je hebt het goed!";
                  } else {
                    cout << "Je hebt het fout!";
                    return 1;
                  }
                }



              }
            }
          }
        }
      }
    }
return 0;
}
