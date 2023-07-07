/// Auteurs: Alexandre Poirier, Pierre MASSONIE

#include "ModuleRecherche.h"

#include <iostream>


ModuleRecherche::ModuleRecherche(){}

ModuleRecherche::~ModuleRecherche(){}

float ModuleRecherche::coutRecherche(std::string type)
{
	return m_seuilQualite[type] * m_bddProduit->produitParNom(type).m_coutRecherche;
}

void ModuleRecherche::recherche(std::string type)
{
	m_seuilQualite[type] += 5.0f;
}
