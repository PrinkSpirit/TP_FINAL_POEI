#include <iostream>

#include "GameManager.h"

int main()
{
    GameManager gm;

    gm.chargerMarchandises("./produits.csv");
    gm.listerMarchandises();

    gm.chargerEntreprises("./entreprises.csv");
    gm.listerEntreprises();
}
