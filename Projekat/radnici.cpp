#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <Windows.h>
#include "radnici.h"

using namespace std;

//metoda za unos radnika
void Radnik::unosOsobeCin(Radnik& o, istream& cin){

    string jmbg;
    cout << "Unosite podatke radnika:" << endl;
    cout << "Ime: ";
    cin >> o.ime;
    cout << "Prezime: ";
    cin >> o.prezime;
    cout << "JMBG: ";
    cin >> jmbg;
    o.setJmbg(jmbg);
    cout << endl;
}

//metoda za ispis radnika
void Radnik::ispisOsobeV2(Radnik& o){

    cout << "Ime:" << o.ime << " | ";
    cout << "Prezime:" << o.prezime << " | ";
    cout << "JMBG:" << o.getJmbg() << " | ";
    cout << endl;
}

//metoda za uredjivanje podataka
void Radnik::urediPodatkeRadnika(vector<Radnik>& o) {

    string edit, option;
    cout << "Unesite JMBG radnika kod kojeg zelite urediti podatke: " << endl;
    cin >> edit;
    for (decltype(o.size()) i = 0;i < o.size(); i++) {
        Radnik temp = o[i];
        if (temp.getJmbg() == edit) {

            int kojiPodatak = 0;

            cout << "\nOdaberite koju opciju zelite mijenjati za clana:\n\n";

            cout << "1 : Ime:\n";
            cout << "2 : Prezime:\n";
            cout << "3 : JMBG:\n";

            cin >> kojiPodatak;

            switch (kojiPodatak) {
                case (1):
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option;
                    o.at(i).ime = option;
                    break;

                case (2):
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option;
                    o.at(i).prezime = option;
                    break;

                case (3):
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option;
                    o.at(i).getJmbg() = option;
                    break;

                default:
                    cout << "Pogresan unos!!" << endl;
            }
        }
    }
}

//metoda za brisanje radnika
void Radnik::obrisiRadnika(vector<Radnik>& radnici) {

    string remove;
    cout << "Unesi JMBG radnika za brisanje: " << endl;
    cin >> remove;

    for (int i = 0; i < radnici.size(); i++) {
        if (radnici.at(i).getJmbg() == remove) {
            radnici.erase(radnici.begin() + i);
            return;
        }
    }
}
void Radnik::Radnici(vector<Radnik>& radnici){

    int Meni = 0;
    Radnik *x = new Radnik();

    do{
        Radnik prvi ("Amela", "Karasalihovic", "1234");
        radnici.push_back(prvi);
        Radnik drugi ("Ajla", "Gobeljic", "4321");
        radnici.push_back(drugi);
        Radnik treci ("Irma", "Tufekcic", "2345");
        radnici.push_back(treci);
        Radnik cetvrti ("Edina", "Sisic", "3456");
        radnici.push_back(cetvrti);
        Radnik peti ("Bekir", "Okic", "4567");
        radnici.push_back(peti);
        cout << "\n\nOdaberite jednu od opcija: " << endl << endl;

        cout << "1 : Povratak \n2 : Unosenje podataka radnika \n3 : Sortiranje radnika \n4 : Promjena podataka radnika \n5 : Obrisi radnika" << endl;
        cin >> Meni;

        switch (Meni){

            case 1:
                break;

            case 2:
                int kolikoRadnika;
                cout << "Koliko radnika zelite unijeti?" << endl;
                cin >> kolikoRadnika;

                //pozivanje metode za unošenje podataka radnika
                for(int i = 1; i <= kolikoRadnika; i ++){
                    unosOsobeCin(*x,cin);
                    radnici.push_back(*x);
                }

                for(auto x: radnici)
                    ispisOsobeV2(x);
                break;

            case 3:
                int kakoSortirati;
                cout << "Kako zelite sortirati radnike?\n1: po imenu\n2: po prezimenu" << endl;
                cin >> kakoSortirati;
                //pozivanje metode sortiranja i ispisa radnika
                switch(kakoSortirati){

                    case 1:
                        sort(radnici.begin(), radnici.end(), [] (Radnik& r1, Radnik& r2) { return r1.ime < r2.ime;});
                        cout << endl << "Radnici sortirani po imenu:" << endl;

                        for(auto x : radnici)
                            ispisOsobeV2(x);
                        break;

                    case 2:
                        sort(radnici.begin(), radnici.end(), [] (Radnik& r1, Radnik& r2) { return r1.prezime < r2.prezime;});
                        cout << endl << "Radnici sortirani po prezimenu: " << endl;

                        for(auto x : radnici)
                            ispisOsobeV2(x);
                            break;
                }

                cout << endl;
                break;

            case 4:
                //pozivanje metode uredjivanja podataka
                urediPodatkeRadnika(radnici);

                for(auto x : radnici)
                    ispisOsobeV2(x);
                break;

            case 5:
                //metoda za brisanje radnika
                obrisiRadnika(radnici);

                for(auto x : radnici)
                    ispisOsobeV2(x);
                break;

            }

        }while (Meni != 1);
}
