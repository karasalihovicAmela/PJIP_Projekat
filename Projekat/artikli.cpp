#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include <sstream>
#include <stdlib.h>
#include <algorithm>
#include <Windows.h>
#include "artikli.h"

using namespace std;


//Metoda za unos artikala od strane korisnika
void Artikal::unosArtikla(Artikal& a, istream& cin){

    float cijena1;
    int brojArtikla1;
    string proizvodjac1, nazivArtikla1, vrstaArtikla;

    cout << "Unesite podatke artikla:" << endl;
    cout << "Naziv artikla : ";
    cin >> nazivArtikla1;
    cout << "Cijena artikla: ";
    cin >> cijena1;
    cout << "Vrsta proizvoda: ";
    cin >> vrstaArtikla;
    cout << "Proizvodjac: ";
    cin >> proizvodjac1;
    int brojac = 0;

    do{
        cout << "Unesite broj artikla (4 broja): " << endl;
        cin >> brojArtikla1;
        int temp = brojArtikla1;

        while(brojArtikla1!= 0){
            int broj = brojArtikla1 % 10;
            brojArtikla1 /= 10;
            brojac ++;
        }

        if(brojac == 4){

            brojArtikla1 = temp;
            break;
        }
        brojac = 0;

    }while(true);

    a.setCijena(cijena1);
    a.setNaziv(nazivArtikla1);
    a.setProizvodjac(proizvodjac1);
    a.setBroj(brojArtikla1);
    cout << endl;
}

//metoda za ispis artikala

void Artikal::ispisArtikla(Artikal& a){

    cout << "Artikal: " << a.getNaziv() << "\t| Vrsta artikla: " << a.vrstaArtikla << "\t| Proizvodjac: " << a.getProizvodjac() << "\t| Cijena: " << a.getCijena() << "\t| Broj proizvoda:" << getBroj() << "\t| Kljuc proizvoda: ";
    for(auto i = 0; i < a.getNaziv().length(); i ++){
        cout << a.getNaziv()[i];
        if (i == 2)
            break;
    }

    for(auto i = 0; i < a.vrstaArtikla.length(); i ++){
        cout << a.vrstaArtikla[i];
        if (i == 2)
            break;
    }

    cout << a.getBroj();
    cout << endl;
}

//metoda za uredjivanje polica
void Artikal::izmijeniArtikle(vector<Artikal>& a){

    int edit;
    string option;
    float option1;
    int option2;
    cout << "Unesite broj artikla kod kojeg zelite urediti podatke: " << endl;
    cin >> edit;

    for (decltype(a.size()) i = 0;i < a.size(); i++){
        Artikal temp = a[i];
        if (temp.getBroj() == edit) {

            int kojiPodatak = 0;

            cout << "\nOdaberite koju opciju zelite mijenjati za clana:\n\n";

            cout << "1 : Vrsta artikla:\n";
            cout << "2 : Naziv artikla:\n";
            cout << "3 : Proizvodjac:\n";
            cout << "4 : Cijena:\n";
            cout << "5 : Broj artikla:\n";

            cin >> kojiPodatak;

            switch (kojiPodatak) {
                case (1):
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option;
                    a.at(i).vrstaArtikla = option;
                    break;

                case (2):
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option;
                    a.at(i).setNaziv(option);
                    break;

                case (3):
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option;
                    a.at(i).setProizvodjac(option);
                    break;

                case (4):
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option1;
                    a.at(i).setCijena(option1);
                    break;

                case (5):
                    cout << "Unesite novu izmjenu:\n" << endl;
                    cin >> option2;
                    a.at(i).setBroj(option2);
                    break;

                default:
                    cout << "Pogresan unos!!" << endl;
            }
        }
    }
}

//metoda za brisanje artikala
void Artikal::obrisiArtikle(vector<Artikal>& artikli) {

    int remove;
    cout << "Unesite broj artikla za brisanje: " << endl;
    cin >> remove;

    for (int i = 0; i < artikli.size(); i++) {
        if (artikli.at(i).getBroj() == remove) {
            artikli.erase(artikli.begin() + i);
            return;
        }
        else
            cout << "Pogresan unos!" << endl;
    }
}
void Artikal::Artikli(vector<Artikal>& artikli){

    int Meni = 0;

    Artikal *x = new Artikal();
    Artikal mlijeko(1.5, "Mlijeko", "Meggle", "Mlijecni proizvod", 1111);
    artikli.push_back(mlijeko);
    Artikal keks (2.5, "Jadro", "Jadro", "Keks", 1122);
    artikli.push_back(keks);
    Artikal sok (2.7, "Coca Cola", "Coca Cola", "Sok", 1234);
    artikli.push_back(sok);


    do{


        cout << "Odaberite jednu od opcija: " << endl << endl;
        cout << "1 : Povratak \n2 : Unos podataka artikla \n3 : Sortiranje artikla \n4 : Promjena podataka artikla \n5 : Obrisi artikla" << endl;
        cin >> Meni;

        switch (Meni){
            case 1:
                break;

            case 2:
                int kolikoArtikala;
                cout << "Koliko artikala zelite unijeti?" << endl;
                cin >> kolikoArtikala;

                //pozivanje metode za unošenje podataka artikala
                for(int i = 1; i <= kolikoArtikala; i ++){
                    unosArtikla(*x,cin);
                    artikli.push_back(*x);
                }

                for(auto x: artikli)
                    ispisArtikla(x);
                break;

            case 3:
                //pozivanje metode sortiranja i ispisa artikala
                int kakoSortirati;
                cout << "Kako zelite sortirati artikle?\n1: po nazivu artikla\n2: po cijeni artikla" << endl;
                cin >> kakoSortirati;

                switch(kakoSortirati){
                    case 1:
                        sort(artikli.begin(), artikli.end(), [] (Artikal& a1, Artikal& a2) { return a1.getNaziv() < a2.getNaziv();});
                        cout << endl << "Artikli sortirani po nazivu:" << endl;
                        for(auto x : artikli)
                            ispisArtikla(x);
                        break;
                    case 2:
                        sort(artikli.begin(), artikli.end(), [](Artikal& a1, Artikal& a2) { return a1.getCijena() < a2.getCijena();});
                        cout << endl << "Artikli sortirani po cijeni: " << endl;
                        for(auto x : artikli)
                            ispisArtikla(x);

                        break;
                }
                break;

            case 4:
                //pozivanje metode uredjivanja podataka
                izmijeniArtikle(artikli);

                for(auto x : artikli)
                    ispisArtikla(x);
                break;

            case 5:
                //metoda za brisanje police
                obrisiArtikle(artikli);

                for(auto x : artikli)
                    ispisArtikla(x);
                break;
            }

        }while (Meni != 1);
}

