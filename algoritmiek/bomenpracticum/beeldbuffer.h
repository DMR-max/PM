//============================================================================
// Name        : beeldbuffer.h
//
// Dit file bevat de interface van de klasse beeldbuffer
// Deze klasse wordt gebruikt om een beeldschermweergave op te bouwen alvorens deze weer te geven.
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

#ifndef beeldbuffer_H_
#define beeldbuffer_H_


class beeldbuffer {
public:
	static const int MAXWIDTH = 300;
	static const int MAXHEIGHT = 100;
	beeldbuffer( int width, int height );
	~beeldbuffer();
	int getWidth();
	void reset();
	void drukaf();
	void set( int x, int y, char value );
	void horline(int xb, int xe, int y);
private:
	int width; 					          // Het aantal kolommen van de buffer.
	int height;					          // Het aantal rijen van de buffer.
    char buffer [ MAXWIDTH ][ MAXHEIGHT ];		  // Array voor het bufferen van het beeldscherm.
};

#endif /* beeldbuffer_H_ */
