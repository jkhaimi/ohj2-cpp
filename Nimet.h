#pragma once
#include <string>
#include <vector>
#include "Nimi.h"

class Nimet {
private:
    bool muutettu = false;
    std::string tiedostonPerusNimi = "nimet";
    std::vector<Nimi*> alkiot;

public:
    Nimet() = default;
    ~Nimet() {
        for (auto nimi : alkiot) delete nimi;
    }

    void lisaa(Nimi* nimi);
    const Nimi& anna(size_t i) const;
    size_t getLkm() const;
    void setTiedostonPerusNimi(const std::string& nimi);
};
