#ifndef ARTIKLI_H_INCLUDED
#define ARTIKLI_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Artikal{

    private:
    float cijena;
    string nazivArtikla;
    string proizvodjac;
    int brojArtikla;

    public:
    string vrstaArtikla;
    Artikal(){};
    Artikal(float cj, string nA, string pro, string vA, int bA): cijena(cj), nazivArtikla (nA), proizvodjac (pro), vrstaArtikla(vA), brojArtikla(bA) {};

    float getCijena(){
        return cijena;
    }
    string getNaziv(){
        return nazivArtikla;
    }
    string getProizvodjac(){
        return proizvodjac;
    }
    int getBroj(){
        return brojArtikla;
    }

    void setCijena(float iznos){
        cijena = iznos;
    }
    void setNaziv(string noviNaziv){
        nazivArtikla = noviNaziv;
    }
    void setProizvodjac(string noviProizvodjac){
        proizvodjac = noviProizvodjac;
    }
    void setBroj(int noviBroj){
        brojArtikla = noviBroj;
    }

    void unosArtikla(Artikal& a, istream& cin);
    void ispisArtikla(Artikal& a);
    void izmijeniArtikle(vector<Artikal>& a);
    void obrisiArtikle(vector<Artikal>& artikli);
    void Artikli(vector<Artikal>& artikli);
};

#endif // ARTIKLI_H_INCLUDED
