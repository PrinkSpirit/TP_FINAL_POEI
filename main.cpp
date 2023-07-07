#include <iostream>
#include <Windows.h>

#include "GameManager.h"

int main()
{
    GameManager gm;

    system("cls"); // Necessaire pour éviter des problèmes d'affichage

    gm.chargerMarchandises("./produits.csv");
    gm.listerTypeMarchandises();

    gm.chargerEntreprises("./entreprises.csv");
    gm.listerEntreprises();

    
}
