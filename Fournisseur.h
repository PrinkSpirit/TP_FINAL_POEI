#pragma once

#include "Entreprise.h"

// Le fournisseur produit un certains nombre de matière premières par tours.
class Fournisseur : public Entreprise
{
public:
	Fournisseur();
	~Fournisseur();

	virtual void jouerTour() override;
	virtual void fabriquer(std::string type, int quantite) override;
};

