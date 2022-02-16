//============================================================================
// Name        : beeldbuffer.cc
//
// Dit file bevat de implementatie van de klasse beeldbuffer
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
#include <iostream> // Gebruikt voor cout.
#include "beeldbuffer.h"

using namespace std;

beeldbuffer::beeldbuffer( int width, int height ) {
	if (width > 0 && width < this->MAXWIDTH )
		this->width = width;
	else
		this->width = 80;
	if ( height > 0 && height < this->MAXHEIGHT )
		this->height = height;
	else
    	this->width = 80;
	reset();
}

beeldbuffer::~beeldbuffer() {
	// TODO Auto-generated destructor stub
}

int beeldbuffer::getWidth() {
	return width;
}

void beeldbuffer::set( int x, int y, char value ) {
	if ( ( x >= 0 ) && ( x < width ) && ( y >= 0 ) && ( y < height ) )
		buffer[ x ][ y ] = value;
}



// Teken een horizontaal streepje in de buffer array.
// Argumenten: int xb ; x-coordinaat van het begin van het streepje.
//             int xe ; x-coordinaat van het eind van het streepje.
//             int y  ; y-coordinaat van het streepje.
//
// Globale veranderingen: De array buffer[][] wordt veranderd.
//
// Notitie: Werkt alleen voor xb <= xe.
//
void beeldbuffer::horline(int xb, int xe, int y) {
  int x;

  buffer[xb][y] = '+';
  for (x = xb + 1; x < xe; x++)
    buffer[x][y] = '-';
  buffer[xe][y] = '+';
}

void beeldbuffer::reset() {
  for (int y = 0; y < height; y++)
	for (int x = 0; x < width; x++)
	  buffer[x][y] = ' ';
}

void beeldbuffer::drukaf() {
  for (int y = 0; y < height; y++) {
	for (int x = 0; x < width; x++)
      cout << buffer[x][y];
    cout << endl;
  }
}

