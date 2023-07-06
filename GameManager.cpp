#include "GameManager.h"

#include <fstream>
#include <regex>

GameManager::GameManager()
{
}

GameManager::GameManager(std::string produits, std::string entreprises)
{
	chargerMarchandises(produits);
	m_entreprises.push_back(Fournisseur(m_produits));
	chargerEntreprises(entreprises);
}

GameManager::~GameManager()
{
}

void GameManager::chargerMarchandises(std::string chemin)
{
	std::ifstream fichier(chemin);
	std::regex march_rgx(R"(([^,\n]+))"); // Utilise Raw string, s�lectionne tout les �l�ments entre les virgules
	std::smatch match;

	if (fichier)
	{
		std::string ligne;

		while (std::getline(fichier, ligne))
		{
			TypeProduit march;
			int count = 0;
			std::string::const_iterator it(ligne.cbegin());
			while (std::regex_search(it, ligne.cend(), match, march_rgx)) {
				if (count == 0) {
					march.m_nom = match[0].str();
				} else {
					if(march.m_listeIngredients.find(match[0].str()) == march.m_listeIngredients.end())
						march.m_listeIngredients[match[0].str()] = 1;
					else
						march.m_listeIngredients[match[0].str()] +=1;
				}
				it = match.suffix().first;
				count++;
			}
			m_produits.push_back(march);
		}
	}
	else
	{
		std::cerr << "Impossible d'ouvrir le fichier: " << chemin << std::endl;
	}
}

void GameManager::chargerEntreprises(std::string chemin)
{
	std::ifstream fichier(chemin);
	std::regex march_rgx(R"(([^,\n]+))"); // Utilise Raw string, s�lectionne tout les �l�ments entre les virgules
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

void GameManager::listerMarchandises()
{
	for (auto &march : m_produits) {
		std::cout << march << std::endl;
	}
}

void GameManager::listerEntreprises()
{
	for (auto &ent : m_entreprises) {
		std::cout << ent.getNom() << " " << ent.getTresorerie() << std::endl;
		for(auto &march : ent.getProduits()) {
			std::cout << " -" << march << std::endl;
		}
	}
}
