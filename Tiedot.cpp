#include "Tiedot.h"
#include <iostream>
#include <sstream>
#include <filesystem>
#include <stdexcept>

void Tiedot::lisaa(const Tieto& tieto) {
    alkiot.push_back(tieto);
    muutettu = true;
}

void Tiedot::tallenna() const {
    if (!muutettu) return;

    std::string tiedostoNimi = getTiedostonNimi();
    std::string bakNimi = getBakNimi();

    if (std::filesystem::exists(tiedostoNimi)) {
        std::filesystem::rename(tiedostoNimi, bakNimi);
    }

    std::ofstream tiedosto(tiedostoNimi);
    if (!tiedosto) throw std::runtime_error("Tiedoston avaus epäonnistui: " + tiedostoNimi);

    for (const auto& tieto : alkiot) {
        tiedosto << tieto.toString() << "\n";
    }
}

void Tiedot::lueTiedostosta(const std::string& tiedostoNimi) {
    setTiedostonPerusNimi(tiedostoNimi);

    std::ifstream tiedosto(getTiedostonNimi());
    if (!tiedosto) throw std::runtime_error("Tiedoston avaus epäonnistui: " + getTiedostonNimi());

    alkiot.clear();

    std::string rivi;
    while (std::getline(tiedosto, rivi)) {
        Tieto tieto;
        tieto.parse(rivi);
        lisaa(tieto);
    }
    muutettu = false;
}

void Tiedot::setTiedostonPerusNimi(const std::string& nimi) {
    tiedostonPerusNimi = nimi;
}

std::string Tiedot::getTiedostonNimi() const {
    return tiedostonPerusNimi + ".dat";
}

std::string Tiedot::getBakNimi() const {
    return tiedostonPerusNimi + ".bak";
}

std::vector<Tieto> Tiedot::annaTiedot(int nimiNro) const {
    std::vector<Tieto> loydetyt;
    for (const auto& tieto : alkiot) {
        if (tieto.getNimiNro() == nimiNro) {
            loydetyt.push_back(tieto);
        }
    }
    return loydetyt;
}

int Tiedot::getLkm() const {
    return alkiot.size();
}

void Tiedot::poista(const Tieto& tieto) {
    auto it = std::remove(alkiot.begin(), alkiot.end(), tieto);
    if (it != alkiot.end()) {
        alkiot.erase(it, alkiot.end());
        muutettu = true;
    }
}

int Tiedot::poistaNimenTiedot(int nimiNro) {
    int poistetut = 0;
    auto it = alkiot.begin();
    while (it != alkiot.end()) {
        if (it->getNimiNro() == nimiNro) {
            it = alkiot.erase(it);
            ++poistetut;
            muutettu = true;
        } else {
            ++it;
        }
    }
    return poistetut;
}
