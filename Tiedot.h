#ifndef TIEDOT_H
#define TIEDOT_H

#include "Tieto.h"
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iterator>

class Tiedot {
private:
    std::vector<Tieto> alkiot;
    std::string tiedostonPerusNimi = "tiedot";
    bool muutettu = false; 

public:
    Tiedot() = default;

    void lisaa(const Tieto& tieto); 
    void tallenna() const; 
    void lueTiedostosta(const std::string& tiedostoNimi);
    void setTiedostonPerusNimi(const std::string& nimi); 
    std::string getTiedostonNimi() const; 
    std::string getBakNimi() const;
    std::vector<Tieto> annaTiedot(int nimiNro) const;
    int getLkm() const; 
    void poista(const Tieto& tieto);
    int poistaNimenTiedot(int nimiNro);
    bool onMuutettu() const { return muutettu; } 
};

#endif
