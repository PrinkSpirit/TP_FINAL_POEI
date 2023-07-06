/// Auteur: Pierre MASSONIE

#pragma once

#include <string>
#include <map>

#include "TypeProduit.h"

struct Marchandise
{
	//static int quantite;	// Quantite de marchandise cr��e depuis le debut du programme
	//� ajouter � chaque classe fille

	int id = -1;					// Identifiant unique de la marchandise
	std::string nom = "Inconue";	// Nom de la marchandise

	float prix = -1.0f;				// Prix de vente de la marchandise
	float qualite = -1.0f;			// Qualit� de la marchandise

	TypeProduit type;				// Identifi le type du produit ainsi que la liste de ses ingr�dients

	Marchandise() = delete;
	Marchandise(TypeProduit type) : type(type) {};
};

std::ostream& operator<<(std::ostream& os, const Marchandise& m);
