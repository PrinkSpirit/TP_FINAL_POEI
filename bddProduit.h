#pragma once
#include "TypeProduit.h"

class bddProduit
{
	bddProduit();
	bddProduit(std::string chemin);
protected:
	static bddProduit *m_instance;
	std::map<std::string, TypeProduit> m_listeTypeProduit;
public:
	~bddProduit();

	void chargerListeTypeProduit(std::string chemin);
	static bddProduit* initBdd(std::string chemin);
	static bddProduit* getInstance();
	static void deleteInstance();


	TypeProduit produitParNom(std::string nom);
	void afficherListeProduit();
};

