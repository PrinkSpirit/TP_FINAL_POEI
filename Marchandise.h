/// Auteur: Pierre MASSONIE

#pragma once

#include <string>
#include <map>

#include "TypeProduit.h"
#include "bddProduit.h"

struct Marchandise
{
	//static int quantite;	// Quantite de marchandise créée depuis le debut du programme
	//À ajouter à chaque classe fille

	int m_id = -1;					// Identifiant unique de la marchandise
	std::string m_nom = "Inconue";	// Nom de la marchandise

	float m_prix = -1.0f;				// Prix de vente de la marchandise
	float m_qualite = -1.0f;			// Qualité de la marchandise

	TypeProduit m_type;				// Identifi le type du produit ainsi que la liste de ses ingrédients

	Marchandise() = delete;
	Marchandise(std::string type) : m_nom(type) {
		m_type = bddProduit::getInstance()->produitParNom(type);
	};

	Marchandise(TypeProduit type) : m_nom(type.m_nom), m_type(type) {};
};

std::ostream& operator<<(std::ostream& os, const Marchandise& m);
