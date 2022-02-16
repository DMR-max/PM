//============================================================================
// Name        : boomtester.cc
//
// Testprogramma voor een binaire (zoek-)boom.
//
// Behorend bij het bomenpracticum van het college Algoritmiek binnen de studie
// Informatica (en Economie). De student wordt geacht een aantal
// member functies van de klasse `binaireboom' uit te werken.
// Er staan al skeletten van deze functies in de klasse Bboom.
//
// Auteur: Jeroen Laros
// Aangepast door: Tijn Witsenburg
// Verder aangepast door: Rudy van Vliet, 15 februari 2011 / 6 februari 2012
// Verder aangepast door: Erik Massop en Rudy van Vliet, 14/15/19 februari 2013
// Aangepast door : Nelleke Louwe Kooijmans, 21 januari 2015
//============================================================================


#include <iostream> // Gebruikt voor cout.
#include <cstring>  // Gebruikt voor strcpy.
#include <cmath>    // Gebruikt voor pow().
#include <cstdlib>  // Gebruikt voor rand().
#include "boom.h"

using namespace std;


// Vraag de gebruiker waarmee (met welke boom/bomen) hij zijn/haar
// implementatie wil testen.
// 1. standaard bomen voor onderdeel 1 (binaire boom)
// 2. standaard binaire zoekboom voor onderdeel 2 (binaire zoekboom)
// 3. eigen boom
// 4. niets (stoppen)
// Retourneer:
// - als de gebruiker nog wil testen: het aantal boomcoderingen
//   waarmee de binaire boom getest moet worden (hoogstens 10).
//   Deze boomcoderingen staan dan in `boomcoderingen'.
// - als de gebruiker wil stoppen   : 0
int VraagTest (char boomcoderingen[10][160])
{ int keuze,
      nrcoderingen;

  do
  {   // toon een menu en vraag de gebruiker om een keuze te maken
//  for (int i = 0; i < XRES; i++)
    for (int i = 0; i < 80; i++)
      cout << '_';
    cout << endl << endl;
    cout << "1. Test met standaard bomen voor onderdeel 1 (binaire boom)\n";
    cout << "2. Test met standaard binaire zoekboom voor onderdeel 2 (binaire zoekboom)\n";
    cout << "3. Test met eigen boom\n";
    cout << "4. Stoppen\n";
    cout << endl;
    cout << "Maak een keuze: ";
    cin >> keuze;
    cout << endl;

  } while ((keuze<1) || (keuze>4));

  // verwerk de keuze
  switch (keuze)
  { case 1: strcpy (boomcoderingen[0], "12400500360f00700");
            strcpy (boomcoderingen[1], "1205c00do00036e00f007g000");
            strcpy (boomcoderingen[2], "120300456007008000");
            strcpy (boomcoderingen[3], "12340056070080090a0b00cd0e0f00gh00ij000");
            strcpy (boomcoderingen[4], "123456007008900a00bcd00e00fg00h00ijkl00m00no00p00qrs00t00uv00w00xyzAB00C00DE00F00GHI00J00KL00M00NOPQ00R00ST00U00VWX00Y00Z@00%00");
            strcpy (boomcoderingen[5], "123004560070800900a0bc00de0000");
            strcpy (boomcoderingen[6], "ek0Mb00oO000JE00tRv003000");
            nrcoderingen = 7;
            break;
    case 2: strcpy (boomcoderingen[0], "42100300860700900");
            nrcoderingen = 1;
            break;
    case 3: cout << "Geef een geldige boomcodering van maximaal 159 karakters:\n";
            cout << "  ";
            cin >> boomcoderingen[0],
            cout << endl;
            nrcoderingen = 1;
            break;
    case 4: nrcoderingen = 0;
            break;
  }  // switch

  return nrcoderingen;

}// VraagTest


// Voer een aantal testen uit met de boom gecodeerd in `boomcodering'.
void DoeTest (char *boomcodering)
{
	binaireboom boom = binaireboom();

/*
  for (int i = 0; i < buffer.getWidth(); i++)
    cout << '_';
  cout << endl << endl;
*/

  boom.maak(boomcodering);
  boom.drukaf();
  cout << "Aantal bladeren: " << boom.aantalbladeren() << endl;
  cout << "Hoogte: " << boom.hoogte() << endl;
  boom.initniveau();
  boom.vulniveau();
  cout << "Maximale info waarde: " << boom.maxinfowaarde() << endl;
  boom.doepostorde();
  if (boom.isbzboom()) {
    cout << "Dit is een binaire zoekboom." << endl;
    cout << "'5' toevoegen:" << endl;
    boom.bzvoegtoe('5');
    boom.drukaf();
    cout << "'7' verwijderen:" << endl;
    boom.bzverwijder('7');
    boom.drukaf();
    cout << "'6' verwijderen:" << endl;
    boom.bzverwijder('6');
    boom.drukaf();
    cout << "'6' toevoegen:" << endl;
    boom.bzvoegtoe('6');
    boom.drukaf();
    cout << "'4' verwijderen:" << endl;
    boom.bzverwijder('4');
    boom.drukaf();
    cout << "'5' verwijderen:" << endl;
    boom.bzverwijder('5');
    boom.drukaf();
    cout << "'8' verwijderen:" << endl;
    boom.bzverwijder('8');
    boom.drukaf();
    cout << "'4' verwijderen:" << endl;
    boom.bzverwijder('4');
    boom.drukaf();
    cout << "'6' verwijderen:" << endl;
    boom.bzverwijder('6');
    boom.drukaf();
    cout << "'9' verwijderen:" << endl;
    boom.bzverwijder('9');
    boom.drukaf();
    cout << "'2' verwijderen:" << endl;
    boom.bzverwijder('2');
    boom.drukaf();
    cout << "'3' verwijderen:" << endl;
    boom.bzverwijder('3');
    boom.drukaf();
    cout << "'1' verwijderen:" << endl;
    boom.bzverwijder('1');
    boom.drukaf();
    cout << "'4' toevoegen:" << endl;
    boom.bzvoegtoe('4');
    boom.drukaf();
  }//if
  else
    cout << "Dit is geen binaire zoekboom." << endl;
  cout << endl;

}// DoeTest

int main(int argc, char **argv) {
  char boomcoderingen[10][160];
  int nrcoderingen;

  do
  { nrcoderingen = VraagTest (boomcoderingen);

    if (nrcoderingen>0)
    { for (int inst=0;inst<nrcoderingen;inst++)
        DoeTest (boomcoderingen[inst]);
    }

  } while (nrcoderingen>0);

  return 0;

}//main
