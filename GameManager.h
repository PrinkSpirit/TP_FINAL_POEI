/// Auteur: Pierre MASSONIE

#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "Entreprise.h"
#include "Marchandise.h"

class GameManager
{
protected:
	std::vector<Entreprise> m_entreprises;
	std::vector<Marchandise> m_marchandises;

public:
	GameManager();
	~GameManager();

	void chargerMarchandises(std::string chemin);
	void chargerEntreprises(std::string chemin);

	void listerMarchandises();
	void listerEntreprises();
};

