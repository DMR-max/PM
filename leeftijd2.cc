#include <iostream>
#include <ctime>
#include <math.h>
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
    int a, b, c;
    double discriminant;
    int invoer_kwadraat, antwoord_kwadraat;
    double echt_antwoord_kwadraat1, echt_antwoord_kwadraat2;
    char cultuurvraag1, cultuurvraag2;
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
      return 1;
    }else{
      if (jaar < cjaar - 100){
        cout << "Je bent te oud.";
        return 1;
      }else{
        cout << "In welke maand ben je geboren: ";
        cin >> maand;
        if (maand > 12 || jaar >= 2022){
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
            if (maand == 1 || 3 || 5 || 7 || 9 || 11){
              cout << "Deze maand heeft 31 dagen.";
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
                if (cdag == dag){
                  cout << "gefeliciteerd je bent maandig" << endl;
                }
                if (leeftijd_maand == 0){
                  leeftijd_dag = cdag - dag;
                  if (leeftijd_dag >= 0){
                    totaal_maanden = (leeftijd_jaar * 12)
                    + maand + leeftijd_maand;
                    cout << "je bent " << totaal_maanden
                    << " maanden oud" << endl;
                    cout << "je bent " << leeftijd_jaar
                    << " jaren oud" << endl; //je bent .. jaar oud
                    if (leeftijd_dag == 0){
                      cout << "gefeliciteerd je bent jarig." << endl;
                    }
                  }
                }else{
                  if (leeftijd_maand > 0){
                    totaal_maanden = (leeftijd_jaar * 12)
                    + maand + leeftijd_maand;
                    cout << "je bent " << totaal_maanden
                    << " maanden oud" << endl;
                    cout << "je bent " << leeftijd_jaar
                    << " jaren oud" << endl; //je bent .. jaar oud
                  }else{
                    leeftijd_jaar = leeftijd_jaar - 1;
                    totaal_maanden = (leeftijd_jaar * 12)
                    + maand + leeftijd_maand;
                    cout << "je bent " << totaal_maanden
                    << " maanden oud"<< endl;
                    cout << "je bent " << leeftijd_jaar
                    << " jaren oud" << endl; //je bent .. jaar oud
                  }
                }

                aantal_jaren = (jaar - 1901) * 365; // aantal dagen voor de jaren
                aantal_maanden = (maand - 1) * 31; // aantal dagen voor de maanden (te veel)
                maanden_30 = maand / 2; // kijken hoeveel maanden met 30 ipv 31 dagen
                if (maand == 2 || maand == 4 || maand == 6
                || maand == 9 || maand == 11){ // voor alle even 30 dagen maanden
                  if (maand > 2){ // nog geen rekening met 28 dagen in feb
                    maanden_uiteindelijk = aantal_maanden - 1 - maanden_30; // te veel dagen afhalen zodat het klopt
                  }else{ // wel rekening met 28 dagen in feb
                    maanden_uiteindelijk = aantal_maanden + 1 - maanden_30; // te veel dagen afhalen zodat het klopt
                  }
                }else{ // voor alle 31 dagen maanden
                  if (maand > 2){ // nog geen rekening met 28 dagen in feb
                    maanden_uiteindelijk = aantal_maanden - 2 - maanden_30; // te veel dagen afhalen zodat het klopt
                  }else{ // wel rekening met 28 dagen in feb
                    maanden_uiteindelijk = aantal_maanden - maanden_30; // te veel dagen afhalen zodat het klopt
                  }
                }

                schikkel = (jaar - 1901) / 4 - 1;
                totaal = aantal_jaren + maanden_uiteindelijk + dag + schikkel; // alle dagen bij elkaar optellen
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
                    cout << "Je hebt het goed!" << endl;
                  }else{
                    cout << "Je hebt het fout!";
                    return 1;
                  }
                }
                if (juiste_dag == 'd' && juiste_dag2 == 'o'){
                  if (geborte_dag == juiste_dag && geborte_dag2 == juiste_dag2){
                    cout << "Je hebt het goed!" << endl;
                  }else{
                    cout << "Je hebt het fout!";
                    return 1;
                  }
                }
                if (juiste_dag == 'z' && juiste_dag2 == 'a'){
                  if (geborte_dag == juiste_dag && geborte_dag2 == juiste_dag2){
                    cout << "Je hebt het goed!" << endl;
                  }else{
                    cout << "Je hebt het fout!";
                    return 1;
                  }
                }
                if (juiste_dag == 'z' && juiste_dag2 == 'o'){
                  if (geborte_dag == juiste_dag && geborte_dag2 == juiste_dag2){
                    cout << "Je hebt het goed!" << endl;
                  }else{
                    cout << "Je hebt het fout!";
                    return 1;
                  }
                }
                if (juiste_dag == 'm' || juiste_dag == 'w'
                || juiste_dag == 'v'){
                  if (geborte_dag == juiste_dag){
                    cout << "Je hebt het goed!" << endl;
                  }else{
                    cout << "Je hebt het fout!";
                    return 1;
                  }
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
                  cout << "Het Gemeentemuseum in Den Haag organiseerde een "
                  << "expo over het leven en werk van Piet Mondriaan,"<< endl;
                  cout << "een van de protagonisten van De Stijl." << endl;
                  cout << "Het museum bezit ook het laatste schilderij "
                  << "van Mondriaan." << endl;
                  cout << "De kunstenaar begon het werk in 1942 in " << endl;
                  cout << "New York en liet het bij zijn dood " << endl;
                  cout << "in 1944 onafgewerkt achter." << endl << endl;
                  cout << "Wat is de titel van dit schilderij?" << endl;
                  cout << "a. Piet Mondriaan" << endl;
                  cout << "b. Ryan's pa" << endl;
                  cout << "c. Rembrandt van rijn" << endl;
                  cout << "d. Victory Boogie Woogie" << endl;
                  cout << "typ in je antwoord a,b,c of d:" << endl;
                  cin >> cultuurvraag1;
                  if (cultuurvraag1 == 'd'){
                    cout << "Gefeliciteerd uw antwoord is juist. Namelijk d. "
                    << "U bent toegelaten tot de alfa studie." << endl;
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

            }
          }
        }
      }
    }
return 0;
}
