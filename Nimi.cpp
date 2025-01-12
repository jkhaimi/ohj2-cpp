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

bool Nimi::tasmaa(const std::string& hakuehto, int kentta) const {
    if (kentta == 0) return nimi.find(hakuehto) != std::string::npos;
    if (kentta == 1) return artisti.find(hakuehto) != std::string::npos;
    return false;
}

void Nimi::tallenna(std::ostream& out) const {
    out << tunnusNro << "|" << nimi << "|" << artisti << std::endl;
}

bool Nimi::lue(std::istream& in) {
    std::string rivi;
    if (!std::getline(in, rivi)) return false;
    auto erottaja = rivi.find('|');
    if (erottaja == std::string::npos) return false;

    tunnusNro = std::stoi(rivi.substr(0, erottaja));
    auto toinenErottaja = rivi.find('|', erottaja + 1);
    nimi = rivi.substr(erottaja + 1, toinenErottaja - erottaja - 1);
    artisti = rivi.substr(toinenErottaja + 1);
    return true;
}
