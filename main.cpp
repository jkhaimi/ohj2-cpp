#include "Biisit.h"
#include <iostream>

int main() {
    Biisit biisit;

    // Nimet nimet;
    // nimet.setTiedostonPerusNimi("tiedosto");  // Aseta tiedoston nimi
    // nimet.tallenna();  // Kutsu tallenna-funktiota


    try {
        Nimi nimi1, nimi2;
        nimi1.rekisteroi();
        nimi1.taytaMazzaTiedoilla();
        nimi2.rekisteroi();
        nimi2.setNimi("Mökkitie");
        nimi2.setArtisti("Arttu Wiskari");

        biisit.lisaa(nimi1);
        biisit.lisaa(nimi2);

        Tieto tieto1, tieto2;
        tieto1.rekisteroi();
        tieto1.taytaTrapTiedoilla(nimi1.getTunnusNro());
        tieto2.rekisteroi();
        // tieto2.setGenre("Rock");
        // tieto2.setLaatu("Bängeri");
        tieto2.taytaTrapTiedoilla(nimi2.getTunnusNro());


        biisit.lisaa(tieto1);
        biisit.lisaa(tieto2);

        biisit.tallenna();
        biisit.tulosta();

    } catch (const std::exception& e) {
        std::cerr << "Virhe: " << e.what() << std::endl;
    }

    return 0;
}
