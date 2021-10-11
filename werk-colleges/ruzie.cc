#include <iostream>
#include <fstream>
using namespace std;

ifstream invoer ("invoer.txt", ios::in | ios::binary);
ofstream uitvoer("uitvoer.txt", ios::out | ios::binary);
int main(){
    int getal = 0;
    char kar = invoer.get();
    while(!invoer.eof()){
        if('0' <= kar && kar <= '9'){
            getal = 10 * getal + (kar - '0');
        }

    }
    invoer.close();
    uitvoer.close();
}
