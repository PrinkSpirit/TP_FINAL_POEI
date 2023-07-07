/// Auteur: Pierre MASSONIE

#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Entreprise.h"
#include "Fournisseur.h"
#include "Marchandise.h"
#include "bddProduit.h"

class GameManager
{
protected:
	bddProduit* m_bddProduits;
	std::vector<Entreprise> m_entreprises;
	

public:
	GameManager();
	GameManager(std::string produits, std::string entreprises);
	~GameManager();

	void chargerMarchandises(std::string chemin);
	void chargerEntreprises(std::string chemin);

	void listerTypeMarchandises();
	void listerEntreprises();
};


