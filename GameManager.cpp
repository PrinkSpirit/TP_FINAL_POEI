#include "GameManager.h"

#include <fstream>
#include <regex>

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}

void GameManager::chargerMarchandises(std::string chemin)
{
	std::ifstream fichier(chemin);
	std::regex march_rgx(R"(([^,\n]+))"); // Utilise Raw string, sélectionne tout les éléments entre les virgules
	std::smatch match;

	if (fichier)
	{
		std::string ligne;
		Marchandise march;

		while (std::getline(fichier, ligne))
		{
			int count = 0;
			std::string::const_iterator it(ligne.cbegin());
			while (std::regex_search(it, ligne.cend(), match, march_rgx)) {
				if (count == 0) {
					march.nom = match[0].str();
				} else {
					if(march.listeIngredients.find(match[0].str()) == march.listeIngredients.end())
						march.listeIngredients[match[0].str()] = 1;
					else
						march.listeIngredients[match[0].str()] +=1;
				}
				count++;
			}

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
	std::regex march_rgx(R"(([^,\n]+))"); // Utilise Raw string, sélectionne tout les éléments entre les virgules
	std::smatch match;

	std::string nom;
	float capital;
	std::vector<std::string> marchandises;

	if (fichier)
	{
		std::string ligne;
		Marchandise march;

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
			}
			m_entreprises.push_back(Entreprise(nom, capital, marchandises));
			count++;
		}
	}
	else
	{
		std::cerr << "Impossible d'ouvrir le fichier: " << chemin << std::endl;
	}
}
