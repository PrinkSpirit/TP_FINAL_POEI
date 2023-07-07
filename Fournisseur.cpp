/// Auteur: Pierre MASSONIE

#include "Fournisseur.h"

Fournisseur::Fournisseur() : Entreprise("Fournisseur", 0.0f)
{
}

Fournisseur::~Fournisseur()
{
}

void Fournisseur::jouerTour()
{
}

void Fournisseur::fabriquer(std::string type, int quantite)
{
	std::vector<Marchandise*> arrivage;
	for (int i = 0; i < quantite; i++)
	{
		arrivage.push_back(new Marchandise(type));
	}

	this->m_entrepot.stocker(arrivage);
}
