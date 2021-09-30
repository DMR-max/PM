#include <iostream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cstring>
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
    char cultuurvraag1;
    char cultuurvraag2;
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
                leeftijd_in_maand = (leeftijd_jaar * 12) + maand+leeftijd_maand;
                cout << leeftijd_in_maand << endl;
                cout << leeftijd_jaar << endl; //je bent .. jaar oud
                if (leeftijd_dag == 0){
                cout << "gefeliciteerd je bent jarig." << endl;
                }
              }
            }else{
              if (leeftijd_maand > 0){
                leeftijd_in_maand = (leeftijd_jaar * 12) + maand+leeftijd_maand;
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
            cout << "los op: " << a << "x^2 + " << b << "x + " << c << endl;
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
            if (antwoord_kwadraat == 2){
              echt_antwoord_kwadraat1 = (-b-sqrt(discriminant))/(2*a);
              echt_antwoord_kwadraat2 = (-b+sqrt(discriminant))/(2*a);
              cout << "De antwoorden zijn: x=" << echt_antwoord_kwadraat1 <<
              " en x=" << echt_antwoord_kwadraat2  << endl;
            }
          else{ if (antwoord_kwadraat == 1){
            echt_antwoord_kwadraat1 = (-b)/(2*a);
            cout << "Het antwoord is: x=" << echt_antwoord_kwadraat1 << endl;
                }

          }if (antwoord_kwadraat == invoer_kwadraat){
            cout << "Gefeliciteerd u heeft het correcte antwoord, " <<
             "u bent toegelaten tot de exacte studie." << endl;
          }else{
              cout << "Helaas het antwoord klopt niet." << endl;
              cout << "Nu volgt een kunst en literatuur vragen" << endl;
              if(leeftijd_jaar > 30){
                cout <<"Het Gemeentemuseum in Den Haag organiseerde een expo "<<
                "over het leven en werk van Piet Mondriaan, een van de " <<
                "protagonisten van De Stijl. Het museum bezit ook het laatste"<<
                " schilderij van Mondriaan. De kunstenaar begon het werk in " <<
                "1942 in New York en liet het bij zijn dood in 1944 " <<
                "onafgewerkt achter. Wat is de titel van dit schilderij?"<<endl;
                cout << "a. Piet Mondriaan" << endl;
                cout << "b. Ryan's pa" << endl;
                cout << "c. Rembrandt van rijn" << endl;
                cout << "d. Victory Boogie Woogie" << endl;
                cout << "typ in je antwoord a,b,c of d:" << endl;
                cin >> cultuurvraag1;
                if (cultuurvraag1 == 'd'){
                  cout<<"Gefeliciteerd uw antwoord is juist. Namelijk d."<<
                  " U bent toegelaten tot de alfa studie." << endl;
                }else{
                  cout << "helaas uw antwoord is fout." <<endl;
              }
            }else{
              cout << "Het Chinese nieuwe jaar wordt bijna altijd eind januari"
               << " / begin februari gevierd. Elk jaar staat er een ander dier"
              << "centraal voor dat jaar."
               << "Welk dier staat dit jaar centraal (2020)?" << endl;
               cout << "a. kat" << endl;
               cout << "b. Hond" << endl;
               cout << "c. Vleermuis" << endl;
               cout << "d. Rat" << endl;
               cout << "typ in je antwoord a,b,c of d:" << endl;
               cin >> cultuurvraag2;
               if (cultuurvraag2 == 'd'){
                 cout<<"Gefeliciteerd uw antwoord is juist. Namelijk d."<<
                 " U bent toegelaten tot de alfa studie." << endl;
               }else{
                 cout << "helaas uw antwoord is fout." <<
                  " U wordt niet aangenomen." <<endl;
             }
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
