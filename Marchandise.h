/// Auteur: Pierre MASSONIE

#pragma once

#include <string>
#include <map>

#include "TypeProduit.h"

struct Marchandise
{
	//static int quantite;	// Quantite de marchandise créée depuis le debut du programme
	//À ajouter à chaque classe fille

	int id = -1;					// Identifiant unique de la marchandise
	std::string nom = "Inconue";	// Nom de la marchandise

	float prix = -1.0f;				// Prix de vente de la marchandise
	float qualite = -1.0f;			// Qualité de la marchandise

	TypeProduit type;				// Identifi le type du produit ainsi que la liste de ses ingrédients

	Marchandise() = delete;
	Marchandise(TypeProduit type) : type(type) {};
};

std::ostream& operator<<(std::ostream& os, const Marchandise& m);
