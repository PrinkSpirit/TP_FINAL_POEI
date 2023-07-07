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
	// Utilise Raw string, s�lectionne tout les �l�ments entre les virgules
	std::regex march_rgx(R"(([^,\n]+))"); 
	std::smatch match;

	std::string nom = "";
	float capital = 0;
	std::vector<std::string> marchandises; // Liste des marchandises produites par une entreprise

	if (fichier)
	{
		std::string ligne;

		while (std::getline(fichier, ligne))
		{
			int count = 0;		  // Compteur pour savoir quel �l�ment on traite
			marchandises.clear(); // On s'assure que la liste est vide

			// S�lection les charact�res jusqu'a trouver une virugle
			std::string::const_iterator it(ligne.cbegin());
			while (std::regex_search(it, ligne.cend(), match, march_rgx)) {
				switch (count) {
					case 0: // Premier �l�ment est le nom de l'entreprise
						nom = match[0].str();
						break;
					case 1: // Deuxi�me �l�ment est le capital
						capital = std::stof(match[0].str());
						break;
					default: // Les autres �l�ments sont les marchandises produites
						marchandises.push_back(match[0].str());
						break;
				}
				it = match.suffix().first;
				count++;
			}
			m_entreprises.push_back(Entreprise(nom, capital, marchandises));
		}
	}
	else
	{
		std::cerr << "Impossible d'ouvrir le fichier: " << chemin << std::endl;
		terminate(); // Sans ce fichier le programme n'a pas de sens
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

GameManager::action GameManager::lireCommande() {

	std::string commande = "";

	std::cout << "Commande: ";
	std::cin >> commande;
	// Vide le buffer pour �viter de prendre le retour � la ligne
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	// Converti la chaines de caract�res en minuscule
	// parce que la classe string n'a pas de m�thode pour �a, �a serrais trop simple j'immagine
	std::transform(commande.begin(), commande.end(), commande.begin(), tolower);

	// Si j'avais plus de temps j'aurais fait des regex pour �a
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
	
	system("cls"); // Necessaire pour �viter des probl�mes d'affichage

	do {
		act = lireCommande();

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
