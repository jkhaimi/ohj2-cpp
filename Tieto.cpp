#include "Tieto.h"

int Tieto::seuraavaNro = 1;

Tieto::Tieto() : tunnusNro(0), nimiNro(0), genre(""), laatu("") {}

Tieto::Tieto(int nimiNro) : tunnusNro(0), nimiNro(nimiNro), genre(""), laatu("") {}

void Tieto::taytaTrapTiedoilla(int nro) {
    nimiNro = nro;
    genre = "trap";
    laatu = "Great";
}

void Tieto::setGenre(const std::string& genre) {
    this->genre = genre;
}

void Tieto::setLaatu(const std::string& laatu) {
    this->laatu = laatu;
}

void Tieto::setNimiNro(int nimiNro) {
    this->nimiNro = nimiNro;
}

int Tieto::rekisteroi() {
    tunnusNro = seuraavaNro++;
    return tunnusNro;
}

int Tieto::getTunnusNro() const {
    return tunnusNro;
}

int Tieto::getNimiNro() const {
    return nimiNro;
}

void Tieto::tulosta(std::ostream& os) const {
    os << nimiNro << "  " << genre << " | " << laatu << std::endl;
}

std::string Tieto::toString() const {
    std::ostringstream oss;
    oss << tunnusNro << "|" << nimiNro << "|" << genre << "|" << laatu;
    return oss.str();
}

void Tieto::parse(const std::string& rivi) {
    std::istringstream iss(rivi);
    std::string temp;

    if (std::getline(iss, temp, '|')) setTunnusNro(std::stoi(temp));
    if (std::getline(iss, temp, '|')) nimiNro = std::stoi(temp);
    if (std::getline(iss, temp, '|')) genre = temp;
    if (std::getline(iss, temp, '|')) laatu = temp;
}

void Tieto::setTunnusNro(int nro) {
    tunnusNro = nro;
    if (tunnusNro >= seuraavaNro) {
        seuraavaNro = tunnusNro + 1;
    }
}

bool Tieto::operator==(const Tieto& other) const {
    return toString() == other.toString();
}

size_t Tieto::hashCode() const {
    return static_cast<size_t>(tunnusNro);
}
