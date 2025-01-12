#ifndef TIEDOT_H
#define TIEDOT_H

#include "Tieto.h"
#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>
#include <iterator>

/**
 * Luokka tietojen kokoelmalle.
 * Hallinnoi Tieto-olioiden lisäystä, poistoa, tiedostosta lukemista ja tallentamista.
 */
class Tiedot {
private:
    std::vector<Tieto> alkiot; ///< Tieto-olioiden säiliö
    std::string tiedostonPerusNimi = "tiedot"; ///< Tallennustiedoston nimi ilman päätettä
    bool muutettu = false; ///< Indikaattori, jos kokoelma on muuttunut

public:
    Tiedot() = default;

    void lisaa(const Tieto& tieto); ///< Lisää uuden tiedon kokoelmaan
    void tallenna() const; ///< Tallentaa tiedot tiedostoon
    void lueTiedostosta(const std::string& tiedostoNimi); ///< Lukee tiedot tiedostosta
    void setTiedostonPerusNimi(const std::string& nimi); ///< Asettaa tiedoston perusnimen
    std::string getTiedostonNimi() const; ///< Palauttaa tiedoston nimen tallennusta varten
    std::string getBakNimi() const; ///< Palauttaa varmuuskopiotiedoston nimen
    std::vector<Tieto> annaTiedot(int nimiNro) const; ///< Palauttaa tietyn nimen tiedot
    int getLkm() const; ///< Palauttaa tietojen lukumäärän
    void poista(const Tieto& tieto); ///< Poistaa tietyn tiedon kokoelmasta
    int poistaNimenTiedot(int nimiNro); ///< Poistaa tietyn nimen kaikki tiedot
    bool onMuutettu() const { return muutettu; } ///< Tarkistaa, onko kokoelmaa muutettu
};

#endif
