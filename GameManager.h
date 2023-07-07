/// Auteur: Pierre MASSONIE

#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Entreprise.h"
#include "Fournisseur.h"
#include "Marchandise.h"
#include "bddProduit.h"


///
class GameManager
{
protected:
	// Lien vers la bdd produit
	bddProduit* m_bddProduits;
	// Liste des entreprises
	std::vector<Entreprise> m_entreprises;

	// List les actions possibles
	enum class action {
		listerMarchandises,
		listerEntreprises,
		jouerTour,
		quitter,
		invalide
	};

	// Lit la commande console et renvoie l'action à effectuer.
	action lireCommande();

public:
	GameManager();
	// Constucteur, charge dirrectement les données
	GameManager(std::string produits, std::string entreprises);
	~GameManager();

	// Charge les données depuis les fichiers.
	void chargerMarchandises(std::string chemin);
	void chargerEntreprises(std::string chemin);

	// Affiche les types de machandises dans la console.
	void listerTypeMarchandises();
	// Affiche les entreprises dans la console.
	void listerEntreprises();

	// Lance la partie
	void jouer();
};


