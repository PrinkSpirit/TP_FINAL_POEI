#include "Fournisseur.h"

Fournisseur::Fournisseur(std::vector<TypeProduit> listProduits)
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
		arrivage.push_back(new Marchandise(m_produits[type]));
	}

	this->m_entrepot.stocker(arrivage);
}
