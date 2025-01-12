// Nimi.cpp
#include "Nimi.h"

int Nimi::seuraavaNro = 1;

Nimi::Nimi() : tunnusNro(0), nimi(""), artisti("") {}

std::string Nimi::getNimi() const {
    return nimi + " | " + artisti;
}

void Nimi::tulosta(std::ostream& os) const {
    os << std::setw(3) << std::setfill('0') << tunnusNro << " " << nimi << " | " << artisti << std::endl;
}

int Nimi::rekisteroi() {
    tunnusNro = seuraavaNro++;
    return tunnusNro;
}

int Nimi::getTunnusNro() const {
    return tunnusNro;
}

void Nimi::setTunnusNro(int nr) {
    tunnusNro = nr;
    if (tunnusNro >= seuraavaNro) {
        seuraavaNro = tunnusNro + 1;
    }
}

void Nimi::taytaMazzaTiedoilla() {
    nimi = "Mazza";
    artisti = "slowthai & A$AP Rocky";
}

void Nimi::setNimi(const std::string& n) {
    nimi = n;
}

void Nimi::setArtisti(const std::string& n) {
    artisti = n;
}

std::string Nimi::toString() const {
    std::ostringstream oss;
    oss << tunnusNro << "|" << nimi << "|" << artisti << "|";
    return oss.str();
}

void Nimi::parse(const std::string& rivi) {
    std::istringstream iss(rivi);
    std::string temp;

    if (std::getline(iss, temp, '|')) setTunnusNro(std::stoi(temp));
    if (std::getline(iss, temp, '|')) nimi = temp;
    if (std::getline(iss, temp, '|')) artisti = temp;
}

bool Nimi::operator==(const Nimi& other) const {
    return toString() == other.toString();
}

size_t Nimi::hashCode() const {
    return static_cast<size_t>(tunnusNro);
}

// Nimet.h
#ifndef NIMET_H
#define NIMET_H

#include "Nimi.h"
#include <vector>
#include <string>
#include <stdexcept>

class Nimet {
private:
    std::vector<Nimi> alkiot;
    std::string tiedostonPerusNimi = "nimet";
    bool muutettu = false;

public:
    Nimet() = default;
    void lisaa(const Nimi& nimi);
    const Nimi& anna(int i) const;
    int getLkm() const;
    void tallenna() const;
    void lueTiedostosta();
    void setTiedostonPerusNimi(const std::string& nimi);
    std::string getTiedostonNimi() const;
    std::string getBakNimi() const;
};

#endif