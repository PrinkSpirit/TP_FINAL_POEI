#include <iostream>
#include <Windows.h>

#include "GameManager.h"

int main()
{
    GameManager gm("./produits.csv", "./entreprises.csv");

    gm.jouer();

    return 0;
}
