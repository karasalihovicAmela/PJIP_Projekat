#ifndef KASA_H_INCLUDED
#define KASA_H_INCLUDED

#include <string>
#include <vector>
#include <stdlib.h>
#include "radnici.h"

using namespace std;

class Kasa{

    public:
    unsigned int brojKase;

    Kasa(){};
    Kasa (int broj){
        brojKase = broj;
    };

    void unosKase(Kasa& kasa, istream& cin);
    void ispisKase(Kasa& kasa);
    void urediPodatkeKase(vector<Kasa>& kasa);
    void obrisiKasu(vector<Kasa>& kasa);
    void Kase(vector<Kasa>& kasa);
};

#endif // KASA_H_INCLUDED
