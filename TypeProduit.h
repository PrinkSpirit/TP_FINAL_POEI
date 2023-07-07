/// Auteur: Pierre MASSONIE

#pragma once

#include <string>
#include <sstream>
#include <vector>
#include <map>

struct TypeProduit
{
	std::string m_nom;
	std::map<std::string, int> m_listeIngredients;
	bool m_matierePremiere = true;	// Indique si le produit est une matière première. Automatiquemet mis à false lors de l'ajout d'ingrédients.
	float m_coutRecherche = 2.0f;	// Coût de base de recherche par niveau du produit

	void ajouterIngredient(std::string ingredient) {
		if (this->m_listeIngredients.find(ingredient) != this->m_listeIngredients.end()) {
			this->m_listeIngredients[ingredient]++;
		}
		else {
			this->m_listeIngredients[ingredient] = 1;
		}
		m_matierePremiere = false;
	}

	TypeProduit() : m_nom("Inconu") {}

	TypeProduit(std::string nom, std::vector<std::string> listeIngredients) : m_nom(nom) {
		this->m_matierePremiere = this->m_listeIngredients.size() == 0;
		for (auto& ingredient : listeIngredients) {
			ajouterIngredient(ingredient);
		}
	}

	TypeProduit(std::string nom, std::map<std::string, int> listeIngredients) : m_nom(nom), m_listeIngredients(listeIngredients) {
		this->m_matierePremiere = this->m_listeIngredients.size() == 0;
	}

	bool operator=(const TypeProduit& typeProduit) const {
		return this->m_nom == typeProduit.m_nom;
	}
};

std::ostream& operator<<(std::ostream& os, const TypeProduit& typeProduit);

