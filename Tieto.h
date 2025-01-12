#define TIETO_H

#include <string>
#include <iostream>
#include <sstream>
#include <iomanip>


class Tieto {
private:
    int tunnusNro;
    int nimiNro;
    std::string genre;
    std::string laatu;

    static int seuraavaNro;

    void setTunnusNro(int nro);

public:
    Tieto();
    Tieto(int nimiNro);

    void taytaTrapTiedoilla(int nro);
    void setGenre(const std::string& genre);
    void setLaatu(const std::string& laatu);
    void setNimiNro(int tunnusNro);

    int rekisteroi();
    int getTunnusNro() const;
    int getNimiNro() const;

    void tulosta(std::ostream& os) const;

    std::string toString() const;
    void parse(const std::string& rivi);

    bool operator==(const Tieto& other) const;
    size_t hashCode() const;
};

