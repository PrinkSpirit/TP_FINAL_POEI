#pragma once

#include <map>
#include <vector>

#include "Marchandise.h"

class Entrepot
{
	std::map<TypeMarchandise, std::vector<Marchandise*>> m_stock; // Liste des marchandises en stock

public:
	Entrepot();
	~Entrepot();

	void stocker(Marchandise* marchandise);
	void destocker(Marchandise* marchandise);
	void destocker(TypeMarchandise type, int id);

	int nombreProduit(TypeMarchandise type);

	void afficherStock();
};

