
Dit is de ReadMe-file (voor Linux) behorende bij de opgaven
voor het tweede werkcollege van Algoritmiek. Deze opgaven vallen uiteen in
twee onderdelen:
* onderdeel 1 (opgaven 1-6) gaat over binaire bomen
* onderdeel 2 (opgaven 7-12) gaat over binaire ZOEKbomen
In deze file beschrijven we de bedoeling en de werking van
de boomtester met bijbehorende klassen knoop en binaireboom.

===========================================================================

De Code

De functies die moeten worden ingevuld staan in de file 'boom.cc'.
Per opgave staat aangegeven welke functie moet worden ingevuld.
Als je een functie gemaakt hebt, kun je het programma compileren
met de Makefile (type in 'make').

===========================================================================

Het Programma

Na het compileren staat er in de directory met code een programma genaamd
bomenpracticum. Deze moet worden aangeroepen met het commando
'./bomenpracticum'.

Het programma biedt dan een menu, waarin je kunt kiezen hoe je
de ge-implementeerde binaire boom wilt testen:
1. met een aantal standaard bomen voor onderdeel 1
2. met een standaard binaire zoekboom voor onderdeel 2
3. met een eigen boom
Als je met een eigen boom wilt testen, zul je deze boom op de juiste
wijze moeten coderen. Hoe deze codering precies werkt, staat verderop
in deze ReadMe-file. Deze codering wordt al gebruikt bij de standaard
bomen van menu-opties 1 en 2.

Als je klaar bent met de opgaven, is het belangrijk dat je je (uitgebreide)
boom in ieder geval test met menu-opties 1 en 2. Als je wilt, kun je
ook zelf bomen bedenken, voor menu-optie 3.

===========================================================================

De Codering

Om een boom in te voeren aan het programma 'boom' moet de boom op
de juiste wijze gecodeerd zijn. Deze codering lijkt heel erg op de preorde
notatie, maar hieraan is toegevoegd waar de NULL-pointers zitten.
(Vraagje om even over na te denken: Waarom is alleen de preorde-notatie
niet voldoende?) In plaats van een NULL-pointer wordt een '0' geschreven.

De boom met 'a' in de wortel en verder geen kinderen, wordt dus geschreven
als 'a00'. De boom 'a0b00' heeft 'a' in de wortel en 'b' als rechterkind.
Let op dat de bomen niet hoger mogen zijn dan 6.

