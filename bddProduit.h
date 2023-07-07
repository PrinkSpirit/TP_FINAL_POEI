/// Auteur: Pierre MASSONIE

#pragma once
#include "TypeProduit.h"

class bddProduit
{
	// Les constructeurs restent priv� pour emp�cher l'instanciation de la classe ext�rieurement
	bddProduit();
	bddProduit(std::string chemin);
protected:
	// Instance unique de la classe
	static bddProduit *m_instance;
	// Liste des types de produits par nom
	std::map<std::string, TypeProduit> m_listeTypeProduit;
public:
	~bddProduit();

	// Charge la liste des types de produits � partir du fichier csv fourni
	void chargerListeTypeProduit(std::string chemin);

	// Initialise le singleton avec le fichier csv fourni
	static bddProduit* initBdd(std::string chemin);
	
	// Renvoie le singleton de la classe
	static bddProduit* getInstance();
	
	// D�truit l'instance unique de la classe, appel� automatiquement � la fin du programme
	static void deleteInstance();

	// Renvoie le type de produit correspondant au nom fourni
	TypeProduit produitParNom(std::string nom);

	// Affiche la liste des types de produits dans la console
	void afficherListeProduit();
};

