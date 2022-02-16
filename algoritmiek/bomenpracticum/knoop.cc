//============================================================================
// Name        : knoop.cc
//
// Dit file bevat de implementatie van de klasse knoop
// deze wordt gebruikt door de klasse binaireboom
//
// Behorend bij het bomenpracticum van het college Algoritmiek binnen de studie
// Informatica (en Economie). De student wordt geacht een aantal
// member functies van de klasse `binaireboom' uit te werken.
//
// Auteur: Jeroen Laros
// Aangepast door: Tijn Witsenburg
// Verder aangepast door: Rudy van Vliet, 15 februari 2011 / 6 februari 2012
// Verder aangepast door: Erik Massop en Rudy van Vliet, 14/15/19 februari 2013
// Aangepast door : Nelleke Louwe Kooijmans, 21 januari 2015
//============================================================================

#include <cstdlib>  // Gebruikt voor rand().
#include "knoop.h"

using namespace std;

// Maak een knoop en initialiseer die met echte waarden.
knoop::knoop(char waarde, int niv) {
  links = NULL;
  rechts = NULL;
  info = waarde;
  niveau = niv;
}

// Initialiseer een knoop met standaard waarden.
knoop::knoop() {
  links = NULL;
  rechts = NULL;
  info = 0;
  niveau = (rand() % 9) + 1; // Een willekeurig niveau.
}
