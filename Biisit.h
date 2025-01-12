#define BIISIT_H

#include "Nimet.h"
#include "Tiedot.h"
#include <string>
#include <vector>

class Biisit {
private:
    Nimet nimet;
    Tiedot tiedot;

public:
    Biisit() = default;

    void lisaa(const Nimi& nimi) {
        nimet.lisaa(new Nimi(nimi));
    }

    void lisaa(const Tieto& tieto) {
        tiedot.lisaa(tieto);
    }

    int poista(const Nimi& nimi) {
        int tunnus = nimi.getTunnusNro();
        int poistettu = nimet.poista(tunnus);
        tiedot.poistaNimenTiedot(tunnus);
        return poistettu;
    }

    void poistaTieto(const Tieto& tieto) {
        tiedot.poista(tieto);
    }

    std::vector<Nimi*> etsi(const std::string& hakuehto, int k) {
        return nimet.etsi(hakuehto, k);
    }

    std::vector<Tieto> annaTiedot(const Nimi& nimi) {
        return tiedot.annaTiedot(nimi.getTunnusNro());
    }

    void lueTiedostosta(const std::string& nimi) {
        nimet.lueTiedostosta(nimi);
        tiedot.lueTiedostosta(nimi);
    }

    void tallenna() {
        nimet.tallenna();
        tiedot.tallenna();
    }

    void tulosta() const {
        for (int i = 0; i < nimet.getLkm(); ++i) {
            const Nimi& nimi = nimet.anna(i);
            nimi.tulosta(std::cout);

            auto tiedotList = tiedot.annaTiedot(nimi.getTunnusNro());
            for (const auto& tieto : tiedotList) {
                tieto.tulosta(std::cout);
            }
        }
    }
};
