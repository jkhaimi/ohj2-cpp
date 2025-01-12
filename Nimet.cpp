#include "Nimet.h"
#include <stdexcept>

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
