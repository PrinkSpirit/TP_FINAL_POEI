#include <iostream>
#include <Windows.h>

#include "GameManager.h"

int main()
{
    // Charge les données pour la partie
    GameManager gm("./produits.csv", "./entreprises.csv");

    // Lance la partie
    gm.jouer();

    // Game over
    return 0;
}
