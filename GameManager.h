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

	enum class action {
		listerMarchandises,
		listerEntreprises,
		jouerTour,
		quitter,
		invalide
	};

	action attendreCommande();

public:
	GameManager();
	GameManager(std::string produits, std::string entreprises);
	~GameManager();

	void chargerMarchandises(std::string chemin);
	void chargerEntreprises(std::string chemin);

	void listerTypeMarchandises();
	void listerEntreprises();

	void jouer();
};


