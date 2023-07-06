/// Auteur: Pierre MASSONIE

#pragma once

#include <string>
#include <map>

enum class TypeMarchandise
{

};

struct Marchandise
{
	//static int quantite;	// Quantite de marchandise créée depuis le debut du programme
	//À ajouter à chaque classe fille

	int id = -1;					// Identifiant unique de la marchandise
	std::string nom = "Inconue";	// Nom de la marchandise
	TypeMarchandise type;			// Type de marchandise

	float prix = -1.0f;				// Prix de vente de la marchandise
	float qualite = -1.0f;			// Qualité de la marchandise

	std::map<std::string, int> listeIngredients; // Liste des ingredients necessaires pour fabriquer la marchandise

	Marchandise() {};
};

std::ostream& operator<<(std::ostream& os, const Marchandise& m);
