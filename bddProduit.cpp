/// Auteur: Pierre MASSONIE

#include "bddProduit.h"

#include <regex>
#include <fstream>
#include <iostream>


bddProduit* bddProduit::m_instance = nullptr;


bddProduit::bddProduit() {
}

bddProduit::bddProduit(std::string chemin) {
	chargerListeTypeProduit(chemin);
}


bddProduit::~bddProduit() { }

void bddProduit::chargerListeTypeProduit(std::string chemin) {
	std::ifstream fichier(chemin);
	// Utilise Raw string, sélectionne tout les éléments entre les virgules
	std::regex march_rgx(R"(([^,\n]+))");
	std::smatch match;

	if (fichier) {
		std::string ligne;

		while (std::getline(fichier, ligne)) {
			TypeProduit produit;
			std::string nomProduit;
			int count = 0;		  // Compteur pour savoir quel élément on traite

			// Sélection les charactères jusqu'a trouver une virugle
			std::string::const_iterator it(ligne.cbegin());
			while (std::regex_search(it, ligne.cend(), match, march_rgx)) {
				if (count == 0) { // Premier élément est le nom du produit
					produit.m_nom = match[0].str();
				}
				else { // Les autres sont les ingrédients
					produit.ajouterIngredient(match[0].str());
				}
				it = match.suffix().first;
				count++;
			}
			// On insère le produit à son nom
			m_listeTypeProduit.insert({ produit.m_nom, produit });
		}
	}
	else {
		std::cerr << "Impossible d'ouvrir le fichier: " << chemin << std::endl;
		terminate(); // Sans ce fichier le programme n'a pas de sens
	}
	return;
}

bddProduit* bddProduit::initBdd(std::string chemin) {
	if (m_instance == nullptr) {
		m_instance = new bddProduit();
		m_instance->chargerListeTypeProduit(chemin);
		std::atexit(deleteInstance);
	}
	return m_instance;
}

bddProduit* bddProduit::getInstance() {
	if (m_instance == nullptr) {
		m_instance = new bddProduit();
		std::atexit(deleteInstance);
	}
	return m_instance;
}

void bddProduit::deleteInstance() {
	delete m_instance;
}

TypeProduit bddProduit::produitParNom(std::string nom) {
	return m_listeTypeProduit[nom];
}

void bddProduit::afficherListeProduit() {
	for (auto& type : m_listeTypeProduit) {
		std::cout << type.second.m_nom << std::endl;
		for (auto& ingredient : type.second.m_listeIngredients) {
			std::cout << " -" << ingredient.first << "(" << ingredient.second << ")" << std::endl;
		}
	}
}
