#include <iostream>
#include <time.h>
using namespace std;
// bovenaan:
#include <ctime>

// vijf variabelen voor minuut, uur, dag, maand en jaar
int minuut, uur, dag, maand, jaar;

// en dan twee hulp-variabelen
tm s;
time_t t;
int jaar_invoer;
int leeftijd_noday;

// iedere keer als je de tijd wilt weten:


int main ()
{
  cout << "voer aub uw jaar van geboorte in" << endl;
  cin >> jaar_invoer;
  time (&t);
  s = * localtime (&t);
  minuut = s.tm_min;
  uur = s.tm_hour;
  dag = s.tm_mday;
  maand = s.tm_mon; // 0 voor januari
  jaar = s.tm_year + 1900; // vanaf 1900

  cout << uur << ":" << minuut << "-"
       << dag << ":" << maand + 1 << ":" << jaar << endl;
  leeftijd_noday = jaar - jaar_invoer;
  cout << leeftijd_noday << endl;


}
