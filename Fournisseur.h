/// Auteur: Pierre MASSONIE

#pragma once

#include "Entreprise.h"

// Le fournisseur produit un certains nombre de mati�re premi�res par tours.
class Fournisseur : public Entreprise
{
public:
	Fournisseur();
	~Fournisseur();

	virtual void jouerTour() override;
	// G�n�re une certaine quantit� de mati�re premi�res donn�e.
	virtual void fabriquer(std::string type, int quantite) override;
};

