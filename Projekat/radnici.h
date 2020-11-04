#ifndef RADNICI_H_INCLUDED
#define RADNICI_H_INCLUDED

#include <string>
#include <vector>
using namespace std;

class Radnik{

    private:
    string jmbg;

    public:
    string ime;
    string prezime;
    Radnik(){};
    Radnik(string Jmbg) : jmbg(Jmbg){};
    Radnik(string Ime, string Prezime, string Jmbg): ime(Ime), prezime(Prezime), jmbg(Jmbg){};

    string getJmbg(){
        return jmbg;
    }

    void setJmbg(string maticni){
        jmbg = maticni;
    }

    void unosOsobeCin(Radnik& o, istream&);
    void ispisOsobeV2(Radnik& o);
    void urediPodatkeRadnika(vector<Radnik> &o);
    void obrisiRadnika(vector<Radnik>& radnici);
    void Radnici(vector<Radnik>& radnici);
};

#endif // RADNICI_H_INCLUDED
