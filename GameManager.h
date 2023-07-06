/// Auteur: Pierre MASSONIE

#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Entreprise.h"
#include "Fournisseur.h"
#include "Marchandise.h"

class GameManager
{
protected:
	std::vector<Entreprise> m_entreprises;
	std::vector<TypeProduit> m_produits;

public:
	GameManager();
	GameManager(std::string produits, std::string entreprises);
	~GameManager();

	void chargerMarchandises(std::string chemin);
	void chargerEntreprises(std::string chemin);

	void listerMarchandises();
	void listerEntreprises();
};


