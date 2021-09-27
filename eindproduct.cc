#include <iostream>
#include <ctime>
#include <math.h>
#include <cstdlib>
using namespace std;

/*
Auteurs: Sjouk Ketwaru en Ryan Sleeuwaegen
naam bestand: test.cc
Het programma determineerd of iemand een universiteit aan kan.
text editor: Atom, compiler: MinGW.
Laatst aan gewerkt op: 23-09-2021.
 */

int main ( ) {
    srand (time(NULL));// ranodmizen met behulp van huidige tijd
    int jaar, maand, dag;// moet de gebruiker invullen
    int leeftijd_jaar, leeftijd_maand, leeftijd_dag;// huidige - ingevuld
    int totaal_maanden;// hoeveel maanden oud de gebruiker is
    int aantal_jaren, aantal_maanden;// voor uitrekenen hoeveel dagen vanaf 1900
    int totaal, schikkel;// voor uitrekenen hoeveel dagen vanaf 1900
    int welke_dag;// voor berekenen welke dag
    char geborte_dag, geborte_dag2;// invullen letters voor welke dag geboren
    char juiste_dag, juiste_dag2;// juiste letters voor welke dag geboren
    float schrikkeljaar;// checken of dag mogelijk is
    int a, b, c;// variabelen voor kwadratische formule
    int max_dag;// maximaal aantal dagen wat men mag invullen
    int discriminant;
    int invoer_kwadraat, antwoord_kwadraat;
    double echt_antwoord_kwadraat1, echt_antwoord_kwadraat2;
    char cultuurvraag1, cultuurvraag2;
    tm s;
    time_t t;
    time (&t);
    s = * localtime (&t);
    int cdag = s.tm_mday;
    int cmaand = s.tm_mon + 1;// 1 voor januari
    int cjaar = s.tm_year + 1900;// vanaf 1900

// info blokje
    cout << "makers: Sjouk Ketwaru (s3287297),"
    << "Ryan Sleeuwaegen (s3122166)" << endl;
    cout << "jaar van aankomst: 2021" << endl;
    cout << "studierichting: Kunstmatige Intelligentie" << endl;
    cout << "opgave 1, gemaakt op 23-09-2021" << endl;
    cout << "Dit is een test om aangenomen te worden "
    << "aan de universiteit." << endl
    << endl << endl;
// jaar invullen + checks te oud en jong
    cout << "In welk jaar ben je geboren? (JJJJ)" << endl;
    cin >> jaar;
    if (jaar > cjaar - 10){
      cout << "Je bent te jong.";
      return 1;
    }
    if (jaar < cjaar - 100){
      cout << "Je bent te oud.";
      return 1;
    }
// maand invullen + checks te oud en jong en echte datum
    cout << "In welke maand ben je geboren? (MM)" << endl;
    cin >> maand;
    if (!cin || maand < 1 || maand > 12){
      cout << "Dit is geen echte datum." << endl;
      return 1;
    }
    if (jaar == cjaar - 10 && maand > cmaand){
      cout << "Je bent te jong.";
      return 1;
    }
    if (jaar == cjaar - 100 && maand < cmaand){
      cout << "Je bent te oud.";
      return 1;
    }
// dag invullen + checks te oud en jong en echte datum
    cout << "Op welke dag ben je geboren? (DD)" << endl;
    cin >> dag;
    if (maand == 1 || maand == 3 || maand == 5 || maand == 7 ||
    maand == 8 || maand == 10 || maand == 12){
      max_dag = 31;
    }else if (maand == 2){
        schrikkeljaar = jaar / 4.0;
        if (floor(schrikkeljaar) == schrikkeljaar){
          max_dag = 29;
        }else{
          max_dag = 28;
        }
      }else{
        max_dag = 30;
      }
    if (dag < 1 || dag > max_dag){
      cout << "Dit is geen echte datum." << endl;
      return 1;
    }
    if (jaar == cjaar - 10 && maand == cmaand && dag > cdag){
      cout << "Je bent te jong.";
      return 1;
    }
    if (jaar == cjaar - 100 && maand == cmaand && dag < cdag + 1){
      cout << "Je bent te oud.";
      return 1;
    }
// leeftijd berekenen in jaren en maanden + checks jarig en maandig
    leeftijd_jaar = cjaar - jaar;
    leeftijd_maand = cmaand - maand;
    if (leeftijd_maand == 0){
      leeftijd_dag = cdag - dag;
      if (leeftijd_dag >= 0){
        totaal_maanden = (leeftijd_jaar * 12) + maand + leeftijd_maand;
      }
    }else if (leeftijd_maand > 0){
        totaal_maanden = (leeftijd_jaar * 12) + maand + leeftijd_maand;
      }else{
        leeftijd_jaar = leeftijd_jaar - 1;
        totaal_maanden = (leeftijd_jaar * 12) + maand + leeftijd_maand;
      }
    cout << "je bent " << totaal_maanden << " maanden oud" << endl;
    cout << "je bent " << leeftijd_jaar << " jaren oud" << endl << endl;
    if (cdag == dag){
      cout << "Gefeliciteerd je bent maandig!" << endl << endl;
    }
    if (leeftijd_dag == 0){
      cout << "Gefeliciteerd je bent jarig!" << endl << endl;
    }
// aantal dagen berekenen voor geborte dag
    aantal_jaren = (jaar - 1901) * 365;
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
// alle dagen bij elkaar optellen + berekenen welke dag (modulo)
    totaal = aantal_jaren + aantal_maanden + schikkel + dag;
    welke_dag = totaal % 7;
    cout << "Op wat voor dag ben je geboren, ";
    cout << "vul de eerste letter in voor: " << endl;
    cout << "maandag, woensdag, vrijdag." << endl;
    cout << "Vul de eerste 2 letters in voor:" << endl;
    cout << "dinsdag, donderdag, zaterdag, zondag." << endl;
    cout << "(Geen hoofdletters)";
    cout << "(vul de letters appart in per regel)" << endl;
// letters invullen + modulo uitkomst koppelen aan letters
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
// check of ingevulde dag klopt voor di, do, za, zo
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
// check of ingevulde dag klopt voor ma, wo, vr
    }else if (juiste_dag == 'm' || juiste_dag == 'w'
    || juiste_dag == 'v'){
      if (geborte_dag == juiste_dag){
        cout << "Je hebt het goed!" << endl << endl;
      }else{
        cout << "Je hebt het fout!";
        return 1;
      }
    }
// abc formule + randomizer voor vergelijking
  a = rand ( ) % 1000000 + 1;
  b = rand ( ) % 1000000 - 500000;
  c = rand ( ) % 1000000 - 500000;
  cout << "Los op: " << a << "X^2 + " << b << "X + " << c << " = 0" << endl;
  discriminant = (double)b * b - 4.0 * a * c;
  cin >> invoer_kwadraat;
  if (discriminant == 0){
    antwoord_kwadraat = 1;
    echt_antwoord_kwadraat1 = (-b) / (2 * a);
    cout << "Het antwoord is: X = "
    << echt_antwoord_kwadraat1 << endl;
  }else if (discriminant > 0){
      antwoord_kwadraat = 2;
      echt_antwoord_kwadraat1 = (-b - sqrt(discriminant)) / (2 * a);
      echt_antwoord_kwadraat2 = (-b + sqrt(discriminant)) / (2 * a);
      cout << "De antwoorden zijn: X = " << echt_antwoord_kwadraat1
      << " en X = " << echt_antwoord_kwadraat2  << endl;
  }else{
    antwoord_kwadraat = 0;
    cout << "Er zijn geen antwoorden voor deze vergelijking." << endl;
  }
if (antwoord_kwadraat == invoer_kwadraat){
  if (leeftijd_jaar >= 30){ //netter aangesproken
  cout << "Gefeliciteerd u heeft het correcte antwoord, " << endl;
  cout << "u bent toegelaten tot de exacte studie!" << endl;
}else{
  cout << "Gefeliciteerd je hebt het correcte antwoord, " << endl;
  cout << "je bent toegelaten tot de exacte studie!" << endl;
}
//vraag splitsing voor leeftijd
}else if (leeftijd_jaar >= 30){
    cout << "Helaas uw antwoord klopt niet." << endl << endl;
// Vraag voor 30 +
    cout << "Nu volgt een kunst en literatuur vraag." << endl;
    cout << "Hoe wordt het schilderij de Mona Lisa genoemd in het Italiaans?"
    << endl;
    cout << "A. Piet Mondriaan" << endl;
    cout << "B. Ryan's pa" << endl;
    cout << "C. Broadway Boogie Woogie" << endl;
    cout << "D. La Gioconda" << endl;
    cout << "typ in uw antwoord A, B, C of D:" << endl;
// check of antwoord juist is
    cin >> cultuurvraag1;
    if (cultuurvraag1 == 'D' || cultuurvraag1 == 'd'){
      cout << "Gefeliciteerd, uw antwoord is juist!" << endl;
      cout << "U bent toegelaten tot de alfa studie." << endl;
    }else{
      cout << "helaas uw antwoord is fout." << endl;
      cout << "Het juiste antwoord is 'D'." << endl;
      cout << "U wordt niet aangenomen." << endl;
    }
// Vraag voor 30
  }else{
    cout << "Helaas je antwoord klopt niet." << endl << endl;
    cout << "Nu volgt een kunst en literatuur vraag." << endl;
    cout << "Het Chinese nieuwe jaar wordt bijna altijd " << endl;
    cout << "eind januari / begin februari gevierd." << endl;
    cout << "Elk jaar staat er een ander dier"
    << "centraal voor dat jaar." << endl;
    cout << "Welk dier stond centraal voor 2020?" << endl;
    cout << "A. Kat" << endl;
    cout << "B. Hond" << endl;
    cout << "C. Vleermuis" << endl;
    cout << "D. Rat" << endl;
    cout << "Type in je antwoord A, B, C of D:" << endl;
// check of antwoord juist is
    cin >> cultuurvraag2;
    if (cultuurvraag2 == 'D' || cultuurvraag2 == 'd'){
      cout << "Gefeliciteerd, je antwoord is juist!" << endl;
      cout << "Je bent toegelaten tot de alfa studie." << endl;
    }else{
      cout << "Helaas je  antwoord is fout." << endl;
      cout << "Het juiste antwoord is 'D'." << endl;
      cout << "Je wordt niet aangenomen." << endl;
    }
  }
  return 0;
}
