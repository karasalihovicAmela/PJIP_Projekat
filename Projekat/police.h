#ifndef POLICE_H_INCLUDED
#define POLICE_H_INCLUDED

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Polica {

    private:
    string nazivPolice;
    unsigned int brojPolice;

    public:
    Polica(){};
    Polica(string NazivPolice, unsigned int BrojPolice): nazivPolice(NazivPolice), brojPolice(BrojPolice){};

    string getNaziv(){
        return nazivPolice;
    }
    unsigned int getBroj(){
        return brojPolice;
    }

    void setNaziv(string naziv){
        nazivPolice = naziv;
    }
    void setBroj(unsigned int broj){
        brojPolice = broj;
    }

    void unosPolice(Polica& polica, istream& cin);
    void ispisPolice(Polica& polica);
    void izmijeniPolice(vector<Polica>& o);
    void obrisiPolicu(vector<Polica>& police);
    void Police(vector<Polica>& polica);

};

#endif // POLICE_H_INCLUDED
