#define NIMET_H

#include "Nimi.h"
#include <vector>
#include <string>

class Nimet {
private:
    std::vector<Nimi*> alkiot;
    std::string tiedostonPerusNimi;
    bool muutettu = false;

public:
    ~Nimet() { for (auto nimi : alkiot) delete nimi; }
    void lisaa(Nimi* nimi);
    const Nimi& anna(size_t i) const;
    size_t getLkm() const;
    void setTiedostonPerusNimi(const std::string& nimi);
    int poista(int tunnus);
    std::vector<Nimi*> etsi(const std::string& hakuehto, int kentta) const;
    void tallenna();
    void lueTiedostosta(const std::string& tiedostonimi);
};
