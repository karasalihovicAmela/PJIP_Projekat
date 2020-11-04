#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include <Windows.h>
#include "police.h"

using namespace std;

//Metoda za unos polica od strane korisnika
void Polica::unosPolice(Polica& polica, istream& cin){

    string nazivPol;
    unsigned int brojPol;

    cout << "Vrsta proizvoda koja je na polici: " << endl;
    cin >> nazivPol;
    int brojac = 0;

    do{
        cout << "Unesite broj police (2 broja): " << endl;
        cin >> brojPol;
        int temp = brojPol;

        while(brojPol != 0){
            int broj = brojPol % 10;
            brojPol /= 10;
            brojac ++;
        }

        if(brojac == 2){
            brojPol = temp;
            break;
        }
        brojac = 0;

    }while(true);

    polica.setNaziv(nazivPol);
    polica.setBroj(brojPol);
    cout << endl;
}

//metoda za ispis polica
void Polica::ispisPolice(Polica& polica){

    cout << "Polica: " << polica.getNaziv() << " | Broj police: " << polica.getBroj() << " | Kljuc police: " ;

    for(auto i = 0; i < polica.getNaziv().length(); i ++){
        cout << polica.getNaziv()[i];
        if (i == 2)
            break;
    }
    cout << polica.getBroj() << endl;

}

//metoda za uredjivanje polica
void Polica::izmijeniPolice(vector<Polica>& o){

    unsigned int edit, option;
    cout << "Unesite broj police kod koje zelite urediti podatke: " << endl;
    cin >> edit;

    for (decltype(o.size()) i = 0;i < o.size(); i++){
        Polica temp = o[i];
        if (temp.getBroj() == edit){

            int kojiPodatak = 0;

            cout << "\nOdaberite koju opciju zelite mijenjati za clana:\n\n";

            cout << "1 : Vrsta proizvoda:\n";
            cout << "2 : Broj police:\n";

            cin >> kojiPodatak;

            switch (kojiPodatak){
                case (1):
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option;
                    o.at(i).getNaziv() = option;
                    break;

                case (2):
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option;
                    o.at(i).setBroj(option);
                    break;

                default:
                    cout << "Pogresan unos!!" << endl;
            }
        }
    }
}

//metoda za brisanje polica
void Polica::obrisiPolicu(vector<Polica>& police){

    unsigned int remove;
    cout << "Unesite broj police za brisanje: " << endl;
    cin >> remove;

    for (int i = 0; i < police.size(); i++){

        if (police.at(i).getBroj() == remove){
            police.erase(police.begin() + i);
            return;
        }
        else
            cout << "Pogresan unos!" << endl;

    }
}
void Polica::Police(vector<Polica>& polica){

    int Meni = 0;
    Polica *x = new Polica();

    do{
        Polica prva ("Mlijecni proizvodi", 11);
        polica.push_back(prva);
        Polica druga ("Hijegenski poroizvodi", 12);
        polica.push_back(druga);
        Polica treca ("Skolski pribor", 13);
        polica.push_back(treca);
        Polica cetvrta ("Sokovi", 14);
        polica.push_back(cetvrta);
        Polica peta ("Slatki proizvodi", 15);
        polica.push_back(peta);

        cout << "\n\nOdaberite jednu od opcija: " << endl << endl;

        cout << "1 : Povratak \n2 : Unosenje podataka police \n3 : Sortiranje polica \n4 : Promjena podataka police \n5 : Obrisi policu" << endl;
        cin >> Meni;

        switch (Meni){
            case 1:
                break;

            case 2:
                int kolikoPolica;
                cout << "Koliko polica zelite unijeti?" << endl;
                cin >> kolikoPolica;

                //pozivanje metode za unošenje podataka police
                for(int i = 1; i <= kolikoPolica; i ++){
                    unosPolice(*x,cin);
                    polica.push_back(*x);
                }

                for(auto x: polica)
                    ispisPolice(x);
                break;

            case 3:
                sort(polica.begin(), polica.end(), [] (Polica& p1, Polica& p2) { return p1.getBroj() < p2.getBroj();});
                cout << endl << "Police sortirane po broju: " << endl;

                for(auto x : polica)
                    ispisPolice(x);

                cout << endl;
                break;

            case 4:
                //pozivanje metode uredjivanja podataka
                izmijeniPolice(polica);

                for(auto x : polica)
                    ispisPolice(x);
                break;

            case 5:
                //metoda za brisanje police
                obrisiPolicu(polica);

                for(auto x : polica)
                    ispisPolice(x);
                break;
            }

        }while (Meni != 1);
}
