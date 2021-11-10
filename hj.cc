//laat deel van de wereld zien; eerste poging
//te doen: de verschuifbare "view" afbeelden
void life::drukaf ( );
int i, j;
for ( i = 0; i < hoogte; i++ ) {
for ( j = 0; j < breedte; j++ ) {
if ( dewereld[i][j] )
cout << " X";
else
cout << " O";
}//for j
cout << endl;
}//for i
}//life::drukaf
