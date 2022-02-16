//============================================================================
// Name        : boom.h
//
// Dit file bevat de interface voor de klasse binaireboom.
//
// Behorend bij het bomenpracticum van het college Algoritmiek binnen de studie
// Informatica (en Economie). De student wordt geacht een aantal
// member functies van de klasse `binaireboom' uit te werken.
// Er staan al skeletten van deze functies in dit file.
//
// Auteur: Jeroen Laros
// Aangepast door: Tijn Witsenburg
// Verder aangepast door: Rudy van Vliet, 15 februari 2011 / 6 februari 2012
// Verder aangepast door: Erik Massop en Rudy van Vliet, 14/15/19 februari 2013
// Aangepast door : Nelleke Louwe Kooijmans, 21 januari 2015
//============================================================================


#ifndef BOOM_H_
#define BOOM_H_

#include "knoop.h"
#include "beeldbuffer.h"

using namespace std;

class binaireboom {
  public:
    binaireboom();                 // Constructor.
    ~binaireboom();                // Destructor.

    void maak(char *);             // Maak een boom van een string.
    void drukaf(void);
    void initniveau(void);
    void vulniveau(void);
    void doepostorde(void);
    void bzvoegtoe(char);
    void bzverwijder(char);
    int aantalbladeren(void);
    int hoogte(void);
    bool isbzboom(void);
    char maxinfowaarde(void);

  private:
    knoop *wortel;

    char maxinfowaarde_p(knoop *);
    knoop * bzoek(char);
    knoop * bzoek_p(char, knoop *&);
    knoop * grootstekleinere(knoop *, knoop *&);
    knoop * kleinstegrotere(knoop *, knoop *&);
    void verwijder(knoop * &);
    void bouw(knoop *, char *, int &); // Bouw de boom van een string.
    void teken(knoop *ingang, beeldbuffer & buffer, int x, int y);
    void checkniveaus(knoop* ingang, int& fouten);
    void checkniveaus(knoop* ingang, int controleniveau, int& fouten);
    void initniveau_p(knoop *);
    void vulniveau_p(knoop *, int);
    void doepostorde_p(knoop *);
    void bzvoegtoe_p(char);
    void bzverwijder_p(char);
    int aantalbladeren_p(knoop *);
    int hoogte_p(knoop *);
    bool isbzboom_p(knoop *);
};

#endif /* BOOM_H_ */
