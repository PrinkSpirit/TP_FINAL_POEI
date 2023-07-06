#pragma once

#include <map>
#include <vector>

#include "Marchandise.h"

class Entrepot
{
	std::map<std::string, std::vector<Marchandise*>> m_stock; // Liste des marchandises en stock

public:
	Entrepot();
	~Entrepot();

	void stocker(Marchandise* marchandise);
	void destocker(Marchandise* marchandise);
	void destocker(std::string type, int id);

	int nombreProduit(std::string type);

	void afficherStock();

	std::vector<Marchandise*>* getStock(std::string type);
};

