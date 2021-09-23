#include <iostream>
#include <ctime>
#include <math.h>
#include <cstdlib>
using namespace std;

int main ( ) {
  srand (time(NULL)); //ranodmizen met behulp van huidige tijd
    int jaar, maand, dag; //Moet de gebruiker invullen
    int leeftijd_jaar, leeftijd_maand, leeftijd_dag; //Huidige - geborte
    int totaal_maanden; //Hoeveel maanden oud de gebruiker is
    int aantal_jaren, aantal_maanden; //Voor uitrekenen hoeveel dagen vanaf 1900
    int totaal, schikkel; //Voor uitrekenen hoeveel dagen vanaf 1900
    int maanden_30, maanden_uiteindelijk; //Voor uitrekenen hoeveel dagen vanaf 1900
    int welke_dag; //Voor berekenen welke dag
    char geborte_dag, geborte_dag2; //Invullen letters voor welke dag geboren
    char juiste_dag, juiste_dag2; //Juiste letters voor welke dag geboren
    float schikkeljaar; //checken of dag mogelijk is
    int a, b, c; //variabelen voor kwadratische formule
    int max_dag; //maximaal aantal dagen wat men mag invullen
    double discriminant; //de discriminant double omdat het een kommagetal mag zijn.
    int invoer_kwadraat, antwoord_kwadraat; //hoeveel antwoorden men denkt dat er zijn op de kwadratische formule.
    double echt_antwoord_kwadraat1, echt_antwoord_kwadraat2; //het uiteindelijke antwoord van de kwadratische formule.
    char cultuurvraag1, cultuurvraag2; //de antwoorden voor de cultuur vragen
    tm s;

    time_t t;

    time (&t);
    s = * localtime (&t);
    int cdag = s.tm_mday;
    int cmaand = s.tm_mon + 1; // 0 voor januari
    int cjaar = s.tm_year + 1900; // vanaf 1900

    cout << "";

    cout << "In welk jaar ben je geboren: ";
    cin >> jaar;
    if(jaar >= 2022){
      cout << "voer aub een echte datum in" << endl;
      return 1;
    }
    if (jaar > cjaar - 10){
      cout << "Je bent te jong.";
      return 1;
    }else{
      if (jaar < cjaar - 100){
        cout << "Je bent te oud.";
        return 1;
      }else{
        cout << "In welke maand ben je geboren: ";
        cin >> maand;
        if (maand > 12){
          cout << "voer aub een echte datum in" << endl;
          return 1;
        }
        if (jaar == cjaar - 10 && maand > cmaand){
          cout << "Je bent te jong.";
          return 1;
        }else{
          if (jaar == cjaar - 100 && maand < cmaand){
            cout << "Je bent te oud.";
            return 1;
          }else{
            cout << "Op welke dag ben je geboren: ";
            cin >> dag;
            if (maand == 1 || maand == 3 || maand == 5 || maand == 7 ||
              maand == 8 || maand == 10 || maand == 12){
              max_dag = 31;
            }else{
              if (maand == 2){
                schikkeljaar = jaar/4.0;
                if (floor(schikkeljaar) == schikkeljaar){
                  max_dag = 29;
                }else{
                  max_dag = 28;
                }
              }else{
                max_dag = 30;
              }
            }
            if (dag > max_dag){
              cout << "voer aub een echte datum in" << endl;
              return 1;
            }
            cout << endl;
            if (jaar == cjaar - 10 && maand == cmaand && dag > cdag){
              cout << "Je bent te jong.";
              return 1;
            }else{
              if (jaar == cjaar - 100 && maand == cmaand && dag < cdag + 1){
                cout << "Je bent te oud.";
                return 1;
              }else{
                leeftijd_jaar = cjaar - jaar;
                leeftijd_maand = cmaand - maand;
                if (leeftijd_maand == 0){
                  leeftijd_dag = cdag - dag;
                  if (leeftijd_dag >= 0){
                    totaal_maanden = (leeftijd_jaar * 12)+maand+leeftijd_maand;
                  }
                }else{
                  if (leeftijd_maand > 0){
                    totaal_maanden = (leeftijd_jaar * 12)+maand+leeftijd_maand;
                  }else{
                    leeftijd_jaar = leeftijd_jaar - 1;
                    totaal_maanden = (leeftijd_jaar * 12)+maand+leeftijd_maand;
                  }
                }
                cout << "je bent " << totaal_maanden << " maanden oud" << endl;
                cout << "je bent " << leeftijd_jaar << " jaren oud"
                << endl << endl; //je bent .. jaar oud
                if (cdag == dag){
                  cout << "Gefeliciteerd je bent maandig!" << endl << endl;
                }
                if (leeftijd_dag == 0){
                  cout << "Gefeliciteerd je bent jarig!" << endl << endl;
                }

                aantal_jaren = (jaar - 1901) * 365; // aantal dagen voor de jaren
                if (jaar % 4 == 0){
                  if ( maand > 2 ){
                  schikkel = (jaar - 1901) / 4;
                }else{
                  schikkel = (jaar - 1901) / 4 - 1;
                }
              }else{
                  schikkel = (jaar - 1901) / 4 - 1;
                }

                if (maand == 1){
                  aantal_maanden = 0;
                }else if (maand == 2){
                  aantal_maanden = 31;
                }else if (maand == 3){
                  aantal_maanden = 59;
                }else if (maand == 4){
                  aantal_maanden = 90;
                }else if (maand == 5){
                  aantal_maanden = 120;
                }else if (maand == 6){
                  aantal_maanden = 151;
                }else if (maand == 7){
                  aantal_maanden = 181;
                }else if (maand == 8){
                  aantal_maanden = 212;
                }else if (maand == 9){
                  aantal_maanden = 243;
                }else if (maand == 10){
                  aantal_maanden = 273;
                }else if (maand == 11){
                  aantal_maanden = 304;
                }else if (maand == 12){
                  aantal_maanden = 334;
                }

                totaal = aantal_jaren + aantal_maanden + schikkel + dag; // alle dagen bij elkaar optellen
                welke_dag = totaal % 7; // kijken welke dag het is
                cout << "Op wat voor dag ben je geboren, ";
                cout << "vul de eerste letter in voor: " << endl;
                cout << "maandag, woensdag, vrijdag." << endl;
                cout << "Vul de eerste 2 letters in voor:" << endl;
                cout << "dinsdag, donderdag, zaterdag, zondag." << endl;
                cout << "(Geen hoofdletters)";
                cout << "(vul de letters appart in per regel)" << endl;

                cout << "welke dag: " << welke_dag << endl;
                cin >> geborte_dag;

                if (geborte_dag == 'd' || geborte_dag == 'z'){
                cin >> geborte_dag2;
              }
                if (welke_dag == 0){
                  juiste_dag = 'd';
                  juiste_dag2 = 'i';
                }else if (welke_dag == 1){
                  juiste_dag = 'w';
                }else if (welke_dag == 2){
                  juiste_dag = 'd';
                  juiste_dag2 = 'o';
                }else if (welke_dag == 3){
                  juiste_dag = 'v';
                }else if (welke_dag == 4){
                  juiste_dag = 'z';
                  juiste_dag2 = 'a';
                }else if (welke_dag == 5){
                  juiste_dag = 'z';
                  juiste_dag2 = 'o';
                }else if (welke_dag == 6){
                  juiste_dag = 'm';
                }

                if ((juiste_dag == 'd' &&
                (juiste_dag2 == 'i' || juiste_dag2 == 'o')) ||
                (juiste_dag == 'z' &&
                (juiste_dag2 == 'a' || juiste_dag2 == 'o'))){
                  if (geborte_dag == juiste_dag && geborte_dag2 == juiste_dag2){
                    cout << "Je hebt het goed!" << endl << endl;
                  }else{
                    cout << "Je hebt het fout!";
                    return 1;
                  }

                }else if (juiste_dag == 'm' || juiste_dag == 'w'
                || juiste_dag == 'v'){
                  if (geborte_dag == juiste_dag){
                    cout << "Je hebt het goed!" << endl << endl;
                  }else{
                    cout << "Je hebt het fout!";
                    return 1;
                  }
                }

              }

              a = rand ( ) % 40 + 1; //randomizen van kwadratische formule
              b = rand ( ) % 50 + 1;
              c = rand ( ) % 30 + 1;
              cout << "Los op: " << a << "x^2 + " << b << "x + " << c << endl;
              discriminant = (pow(b,2))-4*a*c; //discriminant berekenen
              cout << "Voer in: 0, 1 of 2 als aantal oplossingen." << endl;
              cin >> invoer_kwadraat;
              if (discriminant == 0){
                antwoord_kwadraat = 1;
              }if (discriminant > 0){
                antwoord_kwadraat = 2;
              }else{
                antwoord_kwadraat = 0;
              }
              if (antwoord_kwadraat == 2){
                echt_antwoord_kwadraat1 = (-b-sqrt(discriminant))/(2*a);
                echt_antwoord_kwadraat2 = (-b+sqrt(discriminant))/(2*a);
                cout << "De antwoorden zijn: x = " << echt_antwoord_kwadraat1
                << " en x = " << echt_antwoord_kwadraat2  << endl;
              }
            else{
              if (antwoord_kwadraat == 1){
                echt_antwoord_kwadraat1 = (-b)/(2*a);
                cout << "Het antwoord is: x = "
                << echt_antwoord_kwadraat1 << endl;
              }
            }
            if (antwoord_kwadraat == invoer_kwadraat){
              if (leeftijd_jaar >= 30){ //netter aangesproken
              cout << "Gefeliciteerd u heeft het correcte antwoord, " << endl;
              cout << "u bent toegelaten tot de exacte studie!" << endl;
            }else{
              cout << "Gefeliciteerd je hebt het correcte antwoord, " << endl;
              cout << "je bent toegelaten tot de exacte studie!" << endl;
            }
            }else{
              if (leeftijd_jaar >= 30){ //vraag splitsing voor groter dan 30
                cout << "Helaas uw antwoord klopt niet." << endl << endl;
                cout << "Nu volgt een kunst en literatuur vraag." << endl;
                cout << "Het Gemeentemuseum in Den Haag organiseerde een "
                << "expo over het leven en werk van Piet Mondriaan,"<< endl;
                cout << "een van de protagonisten van De Stijl." << endl;
                cout << "Het museum bezit ook het laatste schilderij "
                << "van Mondriaan." << endl;
                cout << "De kunstenaar begon het werk in 1942 in " << endl;
                cout << "New York en liet het bij zijn dood " << endl;
                cout << "in 1944 onafgewerkt achter." << endl << endl;
                cout << "Wat is de titel van dit schilderij?" << endl;
                cout << "A. Piet Mondriaan" << endl;
                cout << "B. Ryan's pa" << endl;
                cout << "C. Rembrandt van rijn" << endl;
                cout << "D. Victory Boogie Woogie" << endl;
                cout << "typ in je antwoord A, B, C of D:" << endl;
                cin >> cultuurvraag1;
                if (cultuurvraag1 == 'D' || cultuurvraag1 == 'd'){
                  cout << "Gefeliciteerd, uw antwoord is juist!" << endl;
                  cout << "U bent toegelaten tot de alfa studie." << endl;
                }else{
                  cout << "helaas uw antwoord is fout." << endl;
                  cout << "Het juiste antwoord is 'D'." << endl;
                  cout << "U wordt niet aangenomen." << endl;
                }
              }else{
                cout << "Helaas je antwoord klopt niet." << endl << endl;
                cout << "Nu volgt een kunst en literatuur vraag." << endl;
                cout << "Het Chinese nieuwe jaar wordt bijna altijd " << endl;
                cout << "eind januari / begin februari gevierd." << endl;
                cout << "Elk jaar staat er een ander dier"
                << "centraal voor dat jaar." << endl;
                cout << "Welk dier staat dit jaar centraal (2020)?" << endl;

                cout << "A. Kat" << endl;
                cout << "B. Hond" << endl;
                cout << "C. Vleermuis" << endl;
                cout << "D. Rat" << endl;
                cout << "Type in je antwoord A, B, C of D:" << endl;
                cin >> cultuurvraag2;
                if (cultuurvraag2 == 'D' || cultuurvraag2 == 'd'){
                  cout << "Gefeliciteerd, uw antwoord is juist!" << endl;
                  cout << "U bent toegelaten tot de alfa studie." << endl;
                }else{
                  cout << "Helaas uw antwoord is fout." << endl;
                  cout << "Het juiste antwoord is 'D'." << endl;
                  cout << "U wordt niet aangenomen." << endl;
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
