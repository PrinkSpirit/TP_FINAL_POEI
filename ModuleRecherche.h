/// Auteurs: Alexandre Poirier, Pierre MASSONIE

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "TypeProduit.h"
#include "bddProduit.h"


/// Cette classe permet d'augmenter le seuil de qualit� maximum d'un produit
/// Chaque entreprise peut fabriquer une marchandise de qualit� �gale � la somme de ses composants
/// Si le seuil de qualit� est trop bas, la qualit� ne peut pas d�passer ce seuil
/// Si le seuil est plus �lev� que la somme des composants, la fabrication gagne un bonus de qualit�
struct ModuleRecherche
{
	bddProduit* m_bddProduit = nullptr;
	std::map<std::string, int> m_seuilQualite;

	ModuleRecherche();
	~ModuleRecherche();

	/// Indique le coup pour augmenter le seuil qualit� d'un produit
	/// Default qlt * type->coutRecherche 
	float coutRecherche(std::string);
	/// Augmente le seuil de qualit� d'un produit
	/// Augmente de 5 pour le moment.
	void recherche(std::string);
};

