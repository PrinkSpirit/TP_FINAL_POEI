/// Auteurs: Alexandre Poirier, Pierre MASSONIE

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "TypeProduit.h"
#include "bddProduit.h"


/// Cette classe permet d'augmenter le seuil de qualité maximum d'un produit
/// Chaque entreprise peut fabriquer une marchandise de qualité égale à la somme de ses composants
/// Si le seuil de qualité est trop bas, la qualité ne peut pas dépasser ce seuil
/// Si le seuil est plus élevé que la somme des composants, la fabrication gagne un bonus de qualité
struct ModuleRecherche
{
	bddProduit* m_bddProduit = nullptr;
	std::map<std::string, int> m_seuilQualite;

	ModuleRecherche();
	~ModuleRecherche();

	/// Indique le coup pour augmenter le seuil qualité d'un produit
	/// Default qlt * type->coutRecherche 
	float coutRecherche(std::string);
	/// Augmente le seuil de qualité d'un produit
	/// Augmente de 5 pour le moment.
	void recherche(std::string);
};

