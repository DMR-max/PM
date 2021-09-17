#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
using namespace std;

int main ( ) {
  srand (time(NULL)); //ranodmizen met behulp van huidige tijd
    int jaar;
    int maand;
    int dag;
    int leeftijd_dag;
    int leeftijd_jaar;
    int leeftijd_maand;
    int leeftijd;
    int leeftijd_in_maand;
    int a;
    int b;
    int c;
    double discriminant;
    int invoer_kwadraat;
    int antwoord_kwadraat;
    double echt_antwoord_kwadraat1;
    double echt_antwoord_kwadraat2;
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
            a = rand ( ) % 40;
            b = rand ( ) % 50;
            c = rand ( ) % 30;
            cout << "los op: " << a << "x^2 + " << b << "x + " << c << endl; //formule
            discriminant = (pow(b,2))-4*a*c;
            cout << "voer in 0, 1 of 2 als aantal oplossingen" << endl;
            cin >> invoer_kwadraat;
            if (discriminant == 0){
              antwoord_kwadraat = 1;
            }else if (discriminant > 0){
              antwoord_kwadraat = 2;
            }else{
              antwoord_kwadraat = 0;
            }
            if (antwoord_kwadraat == invoer_kwadraat){
              cout << "Gefeliciteerd u heeft het correcte antwoord" << endl;
            }else{
              cout << "Helaas het antwoord klopt niet." << endl;
            }
            if (antwoord_kwadraat == 2){
              echt_antwoord_kwadraat1 = (-b-sqrt(discriminant))/(2*a);
              echt_antwoord_kwadraat2 = (-b+sqrt(discriminant))/(2*a);
              cout << "De antwoorden zijn: x=" << echt_antwoord_kwadraat1 << " en x=" << echt_antwoord_kwadraat2  << endl;
            }
          else{ if (antwoord_kwadraat == 1){
            echt_antwoord_kwadraat1 = (-b)/(2*a);
            cout << "Het antwoord is: x=" << echt_antwoord_kwadraat1 << endl;
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
