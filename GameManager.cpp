/// Auteur: Pierre MASSONIE

#include "GameManager.h"

#include <cstring>
#include <fstream>
#include <regex>

GameManager::GameManager() {
}

GameManager::GameManager(std::string produits, std::string entreprises) {
	chargerMarchandises(produits);
	m_entreprises.push_back(Fournisseur());
	chargerEntreprises(entreprises);
}

GameManager::~GameManager() {
}

void GameManager::chargerMarchandises(std::string chemin) {
	m_bddProduits = bddProduit::initBdd(chemin);
}

void GameManager::chargerEntreprises(std::string chemin) {
	std::ifstream fichier(chemin);
	std::regex march_rgx(R"(([^,\n]+))"); // Utilise Raw string, sélectionne tout les éléments entre les virgules
	std::smatch match;

	std::string nom = "";
	float capital = 0;
	std::vector<std::string> marchandises;

	if (fichier)
	{
		std::string ligne;

		while (std::getline(fichier, ligne))
		{
			int count = 0;
			std::string::const_iterator it(ligne.cbegin());
			while (std::regex_search(it, ligne.cend(), match, march_rgx)) {
				switch (count) {
					case 0:
						nom = match[0].str();
						break;
					case 1:
						capital = std::stof(match[0].str());
						break;
					default:
						marchandises.push_back(match[0].str());
						break;
				}
				it = match.suffix().first;
				count++;
			}
			m_entreprises.push_back(Entreprise(nom, capital, marchandises));
			marchandises.clear();
		}
	}
	else
	{
		std::cerr << "Impossible d'ouvrir le fichier: " << chemin << std::endl;
	}
}

void GameManager::listerTypeMarchandises() {
	m_bddProduits->afficherListeProduit();
}

void GameManager::listerEntreprises() {
	for (auto &ent : m_entreprises) {
		std::cout << ent.getNom() << " " << ent.getTresorerie() << std::endl;
		for(auto &march : ent.getProduits()) {
			std::cout << " -" << march << std::endl;
		}
	}
}

GameManager::action GameManager::attendreCommande() {

	std::string commande = "";

	std::cout << "Commande: ";
	std::cin >> commande;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Converti la chaines de caractères en minuscule
	// parce que la classe string n'a pas de méthode pour ça, ça serrais trop simple j'immagine
	std::transform(commande.begin(), commande.end(), commande.begin(), tolower);

	// Si j'avais plus de temps j'aurais fait des regex pour ça
	if (commande == "lister_marchandises" || commande == "lister_produits") {
		return action::listerMarchandises;
	}
	else if (commande == "lister_entreprises") {
		return action::listerEntreprises;
	}
	else if (commande == "jouer") {
		return action::jouerTour;
	}
	else if (commande == "quitter") {
		return action::quitter;
	}
	else {
		return action::invalide;
	}
		

	
}

void GameManager::jouer() {
	bool jouer = true;
	action act = action::invalide;
	
	system("cls"); // Necessaire pour éviter des problèmes d'affichage

	do {
		act = attendreCommande();

		switch (act) {
			case action::listerMarchandises:
				listerTypeMarchandises();
				break;
			case action::listerEntreprises:
				listerEntreprises();
				break;
			case action::jouerTour:
				for (auto &ent : m_entreprises) {
					ent.jouerTour();
				}
				break;
			case action::quitter:
				jouer = false;
				break;
			case action::invalide:
				std::cout << "Commande invalide" << std::endl;
				break;
		}
	} while (jouer);
}
