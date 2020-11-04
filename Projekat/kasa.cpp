#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <Windows.h>
#include "kasa.h"

using namespace std;

//metoda za unos kase
void Kasa::unosKase(Kasa& kasa, istream& cin){

    int brojac = 0;

    do{

        cout << "Unesite broj kase (2 broja): " << endl;
        cin >> kasa.brojKase;
        int temp = kasa.brojKase;

        while(kasa.brojKase != 0){
            int broj = kasa.brojKase % 10;
            kasa.brojKase /= 10;
            brojac ++;
        }

        if(brojac == 2){
            kasa.brojKase = temp;
            break;
        }
        brojac = 0;
    }while(true);

}

//metoda za ispis kasa
void Kasa::ispisKase(Kasa& kasa){

    cout << "Kasa: K" << kasa.brojKase;
    cout << endl;
}

//metoda za uredjivanje podataka
void Kasa::urediPodatkeKase(vector<Kasa>& kasa) {

    unsigned int edit, option;
    cout << "Unesite broj kase kod koje želite promijeniti podatke: " << endl;
    cin >> edit;
    for (decltype(kasa.size()) i = 0;i < kasa.size(); i++){

        Kasa temp = kasa[i];
        if (temp.brojKase == edit) {

            cout << "Promijenite broj kase: ";
            cin >> option;
            kasa.at(i).brojKase = option;

        }
    }
}

//metoda za brisanje kase
void Kasa::obrisiKasu(vector<Kasa>& kasa) {

    unsigned int remove;
    cout << "Unesi broj kase za brisanje: " << endl;
    cin >> remove;

    for (int i = 0; i < kasa.size(); i++) {
        if (kasa.at(i).brojKase == remove) {
            kasa.erase(kasa.begin() + i);
            return;
        }
    }
}
void Kasa::Kase(vector<Kasa>& kasa){

    int Meni = 0;
    Kasa *x = new Kasa();
    do{
        Kasa prva (11);
        kasa.push_back(prva);
        Kasa druga (12);
        kasa.push_back(druga);
        Kasa treca (13);
        kasa.push_back(treca);
        Kasa cetvrta (14);
        kasa.push_back(cetvrta);

        cout << "\n\nOdaberite jednu od opcija: " << endl << endl;

        cout << "1 : Povratak \n2 : Unosenje podataka kase \n3 : Sortiraj kase \n4 : Promjena podataka kase \n5 : Obrisi kasu" << endl;
        cin >> Meni;

        switch (Meni){
            case 1:
                break;

            case 2:
                int kolikoKasa;
                cout << "Koliko kasa zelite unijeti?" << endl;
                cin >> kolikoKasa;

                //pozivanje metode za unošenje podataka kase
                for(int i = 1; i <= kolikoKasa; i ++){
                    unosKase(*x,cin);
                    kasa.push_back(*x);
                }

                for(auto x: kasa)
                    ispisKase(x);
                break;

            case 3:
                sort(kasa.begin(), kasa.end(), [] (Kasa& k1, Kasa& k2) { return k1.brojKase < k2.brojKase;});
                cout << endl << "Sortirane kase: " << endl;

                for(auto x : kasa)
                    ispisKase(x);
                cout << endl;
                break;

            case 4:
                //pozivanje metode uredjivanja podataka
                urediPodatkeKase(kasa);

                for(auto x : kasa)
                    ispisKase(x);
                break;

            case 5:
                //metoda za brisanje kase
                obrisiKasu(kasa);
                for(auto x : kasa)
                    ispisKase(x);
                break;
            }

        }while (Meni != 1);
}
