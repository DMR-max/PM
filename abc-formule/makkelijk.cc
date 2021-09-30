#include <iostream>
#include <ctime>
#include <math.h>
using namespace std;

int main ( ) {
    int jaar, maand, dag; //Moet de gebruiker invullen
    int leeftijd_jaar, leeftijd_maand, leeftijd_dag; //Huidige - geborte
    int totaal_maanden; //Hoeveel maanden oud de gebruiker is
    int aantal_jaren, aantal_maanden; //Voor uitrekenen hoeveel dagen vanaf 1900
    int totaal, schikkel; //Voor uitrekenen hoeveel dagen vanaf 1900
    int welke_dag; //Voor berekenen welke dag
    char geborte_dag, geborte_dag2; //Invullen letters voor welke dag geboren
    char juiste_dag, juiste_dag2; //Juiste letters voor welke dag geboren
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
                totaal_maanden = (leeftijd_jaar * 12) + maand + leeftijd_maand;
                cout << "Je bent " << totaal_maanden << " maanden oud." << endl;
                cout << "Je bent " << leeftijd_jaar << " jaar oud." << endl << endl;
                cout << "gefeliciteerd je bent maandig." << endl << endl;
                if (leeftijd_dag == 0){
                cout << "gefeliciteerd je bent jarig." << endl << endl;
                }
              }else{                                  // Je bent maandig
                leeftijd_jaar = leeftijd_jaar - 1;
                totaal_maanden = (leeftijd_jaar * 12) + maand + leeftijd_maand;
                cout <<  "Je bent " << totaal_maanden << " maanden oud." << endl;
                cout <<  "Je bent " << leeftijd_jaar << " jaar oud." << endl << endl;
                cout << "gefeliciteerd je bent maandig." << endl << endl;
              }
            }else{                                   // Bent al jarig geweest
              if (leeftijd_maand > 0){
                totaal_maanden = (leeftijd_jaar * 12) + maand + leeftijd_maand;
                cout <<  "Je bent " << totaal_maanden << " maanden oud." << endl;
                cout <<  "Je bent " << leeftijd_jaar << " jaar oud." << endl << endl;
            }else{                                  // Bent nog niet jarig geweest
            leeftijd_jaar = leeftijd_jaar - 1;
            totaal_maanden = (leeftijd_jaar * 12) + maand + leeftijd_maand;
            cout <<  "Je bent " << totaal_maanden << " maanden oud." << endl;
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

                cin >> geborte_dag;

                if (geborte_dag == 'd' || geborte_dag == 'z'){
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
