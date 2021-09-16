#include <iostream>
#include <ctime>
using namespace std;

int main ( ) {
    int jaar;
    int maand;
    int dag;
    tm s;
    time_t t;

    time (&t);
    s = * localtime (&t);
    int cdag = s.tm_mday;
    int cmaand = s.tm_mon + 1; // 0 voor januari
    int cjaar = s.tm_year + 1900; // vanaf 1900

    cout << "In welk jaar ben je geboren: ";
    cin >> jaar;

    if (jaar < cjaar - 10){
        cout << "Sorry je bent te jong.";
}
    else{
      if (jaar > cjaar + 100){
      cout << "Sorry je bent te oud.";
    }
      else{
        cout << "In welke maand ben je geboren: ";
        cin >> maand;
      }
    }
        if (jaar == cjaar - 10 && maand < cmaand){
        cout << "Sorry je bent net te jong.";
      }
        else{
          if (jaar == cjaar + 100 && maand > cmaand){
          cout << "Sorry je bent net te oud.";
        }
          else{
          cout << "Op welke dag ben je geboren: ";
        }
      }
          cin >> dag;

          if (jaar == cjaar - 10 && maand == cmaand && dag < cdag){
          cout << "Sorry je bent echt net te jong.";
        }
          else{
            if  (jaar == cjaar + 100 && maand == cmaand && dag > cdag - 1){
            cout << "Sorry je bent echt net te oud.";
          }
            else{
            cout << "Je bent zo oud:";

          }
        }
return 0;
}//main end
