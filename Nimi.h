#define NIMI_H

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>

class Nimi {
private:
    int tunnusNro;
    std::string nimi;
    std::string artisti;

    static int seuraavaNro;

    void setTunnusNro(int nr);

public:
    Nimi();

    std::string getNimi() const;
    void tulosta(std::ostream& os) const;

    int rekisteroi();
    int getTunnusNro() const;

    void taytaMazzaTiedoilla();
    void setNimi(const std::string& n);
    void setArtisti(const std::string& n);

    std::string toString() const;
    void parse(const std::string& rivi);

    bool operator==(const Nimi& other) const;
    size_t hashCode() const;

    bool tasmaa(const std::string& hakuehto, int kentta) const;
    void tallenna(std::ostream& out) const;
    bool lue(std::istream& in);



};
