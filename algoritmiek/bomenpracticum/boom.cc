//============================================================================
// Name        : boom.cc
//
// Dit file bevat de implementatie van de klasse binaireboom.
//
// Behorend bij het bomenpracticum van het college Algoritmiek
// binnen de studie Informatica. De student wordt geacht een aantal
// member functies van de klasse `binaireboom' uit te werken.
// Er staan al skeletten van deze functies in dit bestand.
//
// Auteur: Jeroen Laros
// Aangepast door: Tijn Witsenburg
// Verder aangepast door: Rudy van Vliet, 15 februari 2011 / 6 februari 2012
// Verder aangepast door: Erik Massop en Rudy van Vliet, 14/15/19 februari 2013
// Aangepast door : Nelleke Louwe Kooijmans, 21 januari 2015
//============================================================================

#include <iostream> // Gebruikt voor cout.
#include <cmath>    // Gebruikt voor pow().
#include "boom.h"

using namespace std;

// Constructor : maak een lege boom en stel de beeldbuffer in
binaireboom::binaireboom() : wortel( nullptr ) {
}

// De destructor, verwijder de boom.
// Globale veranderingen: De wortel en subbomen worden verwijderd.
binaireboom::~binaireboom() {
  verwijder(wortel);
}

/****************************************************************************
 * Opgave 1: Geef het aantal bladeren in de boom.
 ****************************************************************************/
// Wrapper-functie aantalbladeren die de private functie aantalbladeren_p aanroept
int binaireboom::aantalbladeren(void) {
  return aantalbladeren_p(wortel);
}

// Private functie aantalbladeren_p
int binaireboom::aantalbladeren_p(knoop *ingang) {
  int teller = 0;
  bool test = false;

  if (ingang != nullptr && ingang -> links != nullptr){
    teller += aantalbladeren_p(ingang -> links);
    test = true;
  }

  if (ingang != nullptr && ingang -> rechts != nullptr){
    teller += aantalbladeren_p(ingang -> rechts);
    test = true;
  }

  if (!test){
    test = false;
    teller++;
  }
  return teller;
}

/****************************************************************************
 * Opgave 2: Geef de hoogte van de boom.
 ****************************************************************************/
// Wrapper-functie hoogte die de private functie hoogte_p aanroept
int binaireboom::hoogte(void) {
  return hoogte_p(wortel);
}

//Private functie hoogte_p
int binaireboom::hoogte_p(knoop *ingang) {
  // TODO: deze functie implementeren
  cout << "Functie hoogte_p nog niet geimplementeerd. ";
  return 6;
}

/****************************************************************************
 * Opgave 3: Initialiseer het niveau veld van elke knoop in de boom.
 ****************************************************************************/
// Wrapper-functie initniveau
void binaireboom::initniveau(void) {
  int fouten = 0;

  initniveau_p(wortel);

  checkniveaus(wortel, fouten);
  if (fouten == 0)
    cout << "Alle niveau's worden correct geinitialiseerd.";
  cout << endl;
}

//Private functie initniveau_p
void binaireboom::initniveau_p(knoop *ingang) {
  // TODO: deze functie implementeren
  cout << "Functie initniveau_p nog niet geimplementeerd." << endl;
}

/****************************************************************************
 * Opgave 4: Vul het niveau veld met het niveau van de knoop.
 ****************************************************************************/
// Wrapper-functie
void binaireboom::vulniveau(void) {
  int fouten = 0;

  vulniveau_p(wortel, 0);

  checkniveaus(wortel, 0, fouten);
  if (fouten == 0)
    cout << "Alle niveau's kloppen.";
  cout << endl;
}

//Private functie vulniveau_p
void binaireboom::vulniveau_p(knoop *ingang, int niveau) {
  // TODO: deze functie implementeren
  cout << "Functie vulniveau_p nog niet geimplementeerd." << endl;
}

/****************************************************************************
 * Opgave 5: Geef de maximale waarde van de info velden in de boom.
 ****************************************************************************/
// Wrapper-functie
char binaireboom::maxinfowaarde(void) {
  return maxinfowaarde_p(wortel);
}

// Private functie maxinfowaarde_p
char binaireboom::maxinfowaarde_p(knoop *ingang) {
  // TODO: deze functie implementeren
  cout << "Functie maxinfowaarde_p nog niet geimplementeerd. ";
  return '0';
}

/****************************************************************************
 * Opgave 6: Druk d.m.v een postorde wandeling de info en niveau velden af.
 ****************************************************************************/
// Wrapper-functie
void binaireboom::doepostorde(void) {
  doepostorde_p(wortel);
  cout << endl;
}

// Private functie doepostorde_p
void binaireboom::doepostorde_p(knoop *ingang) {
  // TODO: deze functie implementeren
  cout << "Functie doepostorde_p nog niet geimplementeerd." << endl;
}

/****************************************************************************
 * Opgave 7: Zoek de grootste waarde kleiner dan de waarde van de root
 * eis: NIET recursief
 ****************************************************************************/
// Private functie grootstekleinere
knoop *binaireboom::grootstekleinere(knoop *ingang, knoop *&ouder) {
  // TODO: deze functie implementeren
  cout << "Functie grootstekleinere nog niet geimplementeerd." << endl;
  return nullptr;
}

/****************************************************************************
 * Opgave 8: Zoek de kleinste waarde groter dan de waarde van de root
 * eis: NIET recursief
 ****************************************************************************/
// Private functie kleinstegrotere
knoop *binaireboom::kleinstegrotere(knoop *ingang, knoop *&ouder) {
  // TODO: deze functie implementeren
  cout << "Functie kleinstegrotere nog niet geimplementeerd." << endl;
  return nullptr;
}

/****************************************************************************
 * Opgave 9: Kijk of een binaire boom een binaire zoekboom is.
 * eissen: WEL recursief en gebruik de functies van opgave 7 en 8
 ****************************************************************************/
// Wrapper-functie
bool binaireboom::isbzboom(void) {
  return isbzboom_p(wortel);
}

// Private functie isbzboom_p
bool binaireboom::isbzboom_p(knoop *ingang) {
  // TODO: deze functie implementeren
  cout << "Functie isbzboom_p nog niet geimplementeerd." << endl;
  return false;
}

/****************************************************************************
 * Opgave 10: Retourneer een pointer naar de knoop in een binaire zoekboom die de waarde bevat.
 ****************************************************************************/
// Wrapper-functie
knoop *binaireboom::bzoek(char waarde) {
  knoop *ouder = nullptr;

  return bzoek_p(waarde, ouder);
}

// Private functie bzoek_p
knoop *binaireboom::bzoek_p(char waarde, knoop *&ouder) {
  // TODO: deze functie implementeren
  cout << "Functie bzoek_p nog niet geimplementeerd." << endl;
  return nullptr;
}

/****************************************************************************
 * Opgave 11: Voeg een waarde toe aan een binaire zoekboom.
 ****************************************************************************/
// Wrapper-functie
void binaireboom::bzvoegtoe(char waarde) {
  bzvoegtoe_p(waarde);
}

// Private functie bzvoegtoe_p
void binaireboom::bzvoegtoe_p(char waarde) {
  // TODO: deze functie implementeren
  cout << "Functie bzvoegtoe_p nog niet geimplementeerd." << endl;
}

/****************************************************************************
 * Opgave 12: Verwijder een waarde uit een binaire zoekboom.
 ****************************************************************************/
// Wrapper-functie
void binaireboom::bzverwijder(char waarde) {
  bzverwijder_p(waarde);
}

// Private functie bzverwijder_p
void binaireboom::bzverwijder_p(char waarde) {
  // TODO: deze functie implementeren
  cout << "Functie bzverwijder_p nog niet geimplementeerd." << endl;
}

/****************************************************************************
 * Voorgedefinieerde functies.
 ****************************************************************************/

/****************************************************************************
 * Functies voor het opbouwen van een boom.
 ****************************************************************************/

// Publieke functie maak: roept de private functie bouw aan met de juiste parameters
// Maak een boom van de string preorde.
// Argumenten: char *preorde: De 'preorde' string van de boom.
// Globale veranderingen: De wortel wordt uigebreid met subbomen.
// Notitie: char *preorde mag niet leeg zijn en moet een geldige codering voor
//     die boom zijn. Een geldige codering is een preorde-wandeling waaraan is
//     is toegevoegd dat voor elke lege subboom een '0' genoteerd wordt.

void binaireboom::maak(char *preorde) {
  int i = 0; // positie in string
  wortel = new knoop();
  bouw(wortel, preorde, i);
}

// Private functie bouw
// Maak een boom met wortel ingang en inhoud preorde.
// Argumenten: knoop *ingang ; De wortel van de nieuwe boom.
//             char *preorde ; De inhoud van de boom.
//             int &i        ; De positie in de preorde string.
// Notitie: char *preorde mag niet leeg zijn en moet een geldige codering voor
//     die boom zijn. Een geldige codering is een preorde-wandeling waaraan is
//     is toegevoegd dat voor elke lege subboom een '0' genoteerd wordt.

void binaireboom::bouw(knoop *ingang, char *preorde, int &i) {
  ingang->info = preorde[i];
  i++;

  if (preorde[i] != '0') {            // Moet de linker subboom niet leeg worden?
    ingang->links = new knoop();
    bouw(ingang->links, preorde, i);
  }

  i++;

  if (preorde[i] != '0') {            // Moet de rechter subboom niet leeg worden?
    ingang->rechts = new knoop();
    bouw(ingang->rechts, preorde, i);
  }
}

/****************************************************************************
 * Functies voor het verwijderen van een boom.
 ****************************************************************************/

// Private functie verwijder
// Verwijder een boom met wortel ingang.
// Argumenten: knoop *ingang ; De wortel van de te verwijderen boom.
// Na afloop wordt de knoop ingang op nullptr gezet.

void binaireboom::verwijder(knoop * & ingang) {
  if (ingang != nullptr) {                // Is de ingang niet nullptr?
    verwijder(ingang->links);
    verwijder(ingang->rechts);
    delete ingang;
    ingang = nullptr;
  }
}

/****************************************************************************
 * Functies voor het weergeven van een boom.
 ****************************************************************************/

// Publieke functie drukaf. Deze roept de private functie teken aan met de juiste parameters.
// Druk de boom af m.v.b. de beeldbuffer.
// Globale veranderingen: De beeldbuffer wordt veranderd.

void binaireboom::drukaf() {
  // int hoog = hoogte();
  int hoog = 6;
  int breed = 6 * pow( 2, hoog );
  beeldbuffer buffer = beeldbuffer( breed, 2 * hoog );

  // Teken de boom in de beeldbuffer
  int midden = buffer.getWidth() / 2;
  teken( wortel, buffer, midden, 0 );

  buffer.drukaf();
}

// Private functie teken
// Teken een boom met wortel ingang in de beeldbuffer.
// Argumenten: knoop *ingang ; De wortel van de boom.
//             int x         ; De x positie van de wortel.
//             int y         ; De y positie van de wortel.
// Globale veranderingen: De beeldbuffer wordt veranderd.

void binaireboom::teken(knoop *ingang, beeldbuffer & buffer, int x, int y) {
  if (ingang == nullptr)
    return;

  int wijdte = (int)( buffer.getWidth() * 0.25 * pow( 0.5, 0.5 * y ) );

  buffer.set( x, y, ingang->info );

  if (ingang->links != nullptr) {
    buffer.horline( x - wijdte, x, y + 1 );
    teken( ingang->links, buffer, x - wijdte, y + 2 );
  }
  if (ingang->rechts != nullptr) {
    buffer.horline( x, x + wijdte, y + 1 );
    teken( ingang->rechts, buffer, x + wijdte, y + 2 );
  }
}

/****************************************************************************
 * Functies voor het checken van de niveaus in de boom
 ****************************************************************************/

// Check of alle niveaus op 0 staan.
// Argumenten: knoop *ingang ; de te checken boom.
//             int &fouten   ; tellertje voor fouten.

void binaireboom::checkniveaus(knoop* ingang, int& fouten) {
  if (ingang == nullptr)
    return;

  if (ingang->niveau != 0) {
    if (fouten == 0)
      cout << "De volgende niveau's staan nog niet op '0':";
    if (fouten % 12 == 0)
      cout << "\b\b\b\b" << endl; // 4 backspaces
    cout << ingang->info << ":" << ingang->niveau << "    ";
    fouten++;
  }
  checkniveaus(ingang->links, fouten);
  checkniveaus(ingang->rechts, fouten);
}

// Check of alle niveaus kloppen.
// Argumenten: knoop *ingang      ; de te checken boom.
//             int controleniveau ; het correcte niveau.
//             int &fouten        ; tellertje voor fouten.

void binaireboom::checkniveaus(knoop* ingang, int controleniveau, int& fouten) {
  if (ingang == nullptr)
    return;

  if (ingang->niveau != controleniveau) {
    if (fouten == 0)
      cout << "De volgende niveau's zijn nog niet correct:";
    if (fouten % 10 == 0)
      cout << endl;
    cout << ingang->info << ":" << ingang->niveau << "(" << controleniveau << ")  ";
    fouten++;
  }
  checkniveaus(ingang->links, controleniveau+1, fouten);
  checkniveaus(ingang->rechts, controleniveau+1, fouten);
}
