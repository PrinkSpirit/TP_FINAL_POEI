#include <iostream>
#include <Windows.h>

#include "GameManager.h"

int main()
{
    // Charge les donn�es pour la partie
    GameManager gm("./produits.csv", "./entreprises.csv");

    // Lance la partie
    gm.jouer();

    // Game over
    return 0;
}
