/// Auteur: Pierre MASSONIE

#pragma once

#include <string>
#include <map>

#include "TypeProduit.h"
#include "bddProduit.h"

struct Marchandise
{
	//static int quantite;	// Quantite de marchandise cr��e depuis le debut du programme
	//� ajouter � chaque classe fille

	int m_id = -1;					// Identifiant unique de la marchandise
	std::string m_nom = "Inconue";	// Nom de la marchandise

	float m_prix = -1.0f;				// Prix de vente de la marchandise
	float m_qualite = -1.0f;			// Qualit� de la marchandise

	TypeProduit m_type;				// Identifi le type du produit ainsi que la liste de ses ingr�dients

	Marchandise() = delete;
	Marchandise(std::string type);;

	Marchandise(TypeProduit type);;
};

// D�crit la machandise dans le format suivant:
// [id]nom - prix$ quanlit�%
std::ostream& operator<<(std::ostream& os, const Marchandise& m);
