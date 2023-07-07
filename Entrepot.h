/// Auteur: Pierre MASSONIE

#pragma once

#include <map>
#include <vector>

#include "Marchandise.h"

/// Contient les marchandises d'une entreprise
class Entrepot
{
	/// Liste des marchandises en stock triées par type
	std::map<std::string, std::vector<Marchandise*>> m_stock; 

public:
	Entrepot();
	~Entrepot();

	/// Ajoute une marchandise dans l'entrepot
	void stocker(Marchandise* marchandise);
	/// Ajoute plusieurs marchandises dans l'entrepot
	void stocker(std::vector<Marchandise*> marchandises);

	/// Retire une marchandise de l'entrepot
	void destocker(Marchandise* marchandise);
	/// Retire plusieurs marchandises de l'entrepot par id
	void destocker(std::string type, int id);

	/// Cherche si une marchandise est dans l'entrepot
	bool enInventaire(Marchandise* marchandise);

	/// Retourne le nombre de marchandises d'un certains type
	int nombreProduit(std::string type);
	/// Retourne le stock d'un certain type
	std::vector<Marchandise*>* getStock(std::string type);

	/// Affiche le stock de l'entrepot dans la console au format suivant:
	/// "- type: nombre"
	void afficherStock();
};

