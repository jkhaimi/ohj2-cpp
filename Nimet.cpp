#include "Nimet.h"
#include <fstream>
#include <stdexcept>
#include <algorithm>

void Nimet::lisaa(Nimi* nimi) {
    alkiot.push_back(nimi);
    muutettu = true;
}

const Nimi& Nimet::anna(size_t i) const {
    if (i >= alkiot.size()) throw std::out_of_range("Invalid index");
    return *alkiot[i];
}

size_t Nimet::getLkm() const {
    return alkiot.size();
}

void Nimet::setTiedostonPerusNimi(const std::string& nimi) {
    tiedostonPerusNimi = nimi;
}

int Nimet::poista(int tunnus) {
    auto it = std::remove_if(alkiot.begin(), alkiot.end(), 
        [tunnus](Nimi* nimi) { return nimi->getTunnusNro() == tunnus; });
    if (it == alkiot.end()) return 0;
    int poistettu = std::distance(it, alkiot.end());
    for (auto del = it; del != alkiot.end(); ++del) {
        delete *del;
    }
    alkiot.erase(it, alkiot.end());
    muutettu = true;
    return poistettu;
}

std::vector<Nimi*> Nimet::etsi(const std::string& hakuehto, int kentta) const {
    std::vector<Nimi*> loydetyt;
    for (const auto& nimi : alkiot) {
        if (nimi->tasmaa(hakuehto, kentta)) {
            loydetyt.push_back(nimi);
        }
    }
    return loydetyt;
}

void Nimet::tallenna() {
    if (!muutettu) return;
    // if (tiedostonPerusNimi.empty()) throw std::runtime_error("Tiedoston nimi ei ole asetettu");

    std::ofstream tiedosto(tiedostonPerusNimi + ".dat");
    if (!tiedosto) throw std::runtime_error("Tiedoston avaaminen epäonnistui");

    for (const auto& nimi : alkiot) {
        nimi->tallenna(tiedosto);
    }
    tiedosto.close();
    muutettu = false;
}

void Nimet::lueTiedostosta(const std::string& tiedostonimi) {
    std::ifstream tiedosto(tiedostonimi + ".dat");
    if (!tiedosto) throw std::runtime_error("Tiedoston avaaminen epäonnistui");

    while (!tiedosto.eof()) {
        Nimi* uusi = new Nimi();
        if (uusi->lue(tiedosto)) {
            lisaa(uusi);
        } else {
            delete uusi;
        }
    }
    tiedosto.close();
}
