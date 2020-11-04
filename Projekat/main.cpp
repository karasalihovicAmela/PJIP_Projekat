#include <iostream>
#include <string>
#include <vector>
#include "radnici.h"
#include "radnici.cpp"
#include "kasa.h"
#include "kasa.cpp"
#include "police.h"
#include "police.cpp"
#include "artikli.h"
#include "artikli.cpp"

using namespace std;

void test(){
  int Meni = 0;
  do{
    cout << endl;
    cout << " " << string(50, '/') << endl;
    cout << " //                                              //" << endl;
    cout << " //              Dobro dosli u Maxi              //" << endl;
    cout << " //                                              //" << endl;
    cout << " " << string(50, '/') << endl;
    cout << endl;
    cout << "Odaberite jednu od opcija:\n" << endl;
    cout << "1 : Radnici\n"
            "2 : Kase\n"
            "3 : Police\n"
            "4 : Artikli\n"
            "5 : Izlaz" << endl;

    cout << " ";
    cin >> Meni;
    Radnik radnik;
    vector<Radnik> radnici;

    Kasa kase;
    vector<Kasa> kasa;

    Polica police;
    vector<Polica> polica;

    Artikal artikal;
    vector<Artikal> artikli;

        switch(Meni){
        case 1:
            radnik.Radnici(radnici);
            break;
        case 2:
            kase.Kase(kasa);
            break;
        case 3:
            police.Police(polica);
            break;
        case 4:
            artikal.Artikli(artikli);
            break;
        }
    }while(Meni != 5);
}

int main()
{
    test();
    return 0;
}

