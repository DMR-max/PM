//============================================================================
// Name        : knoop.h
//
// Dit file bevat de interface van de klasse knoop
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

#ifndef KNOOP_H_
#define KNOOP_H_

class knoop {
public:
  knoop *links;
  knoop *rechts;
  char info;
  int niveau;

  knoop(char, int);     // Constructor: Maak een nieuwe knoop met echte waarden.
  knoop();          // Constructor: Maak een nieuwe knoop.
};




#endif /* KNOOP_H_ */
