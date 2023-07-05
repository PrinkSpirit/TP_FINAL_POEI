/// Auteur: Pierre MASSONIE
/// D�finition de la Factory pure Entreprise

#pragma once

#include "Marchandise.h"
#include "Entrepot.h"

#include <string>
#include <vector>

class Entreprise
{
protected:
	std::string m_nom;				// Nom de l'entreprise
	float tresorerie;				// Quantite d'argent disponible

	Entrepot m_entrepot;			// Entrepot de l'entreprise

public:
	Entreprise();
	Entreprise(std::string nom, float capitalDepart);
	virtual ~Entreprise();

	// Donne le prix d'achat d'une quantite de produit � une entreprise donn�e
	float devisAchat(Entreprise* entreprise, TypeMarchandise type, int quantite);
	// Achete des produits
	bool acheter(Entreprise* entreprise, TypeMarchandise type, int quantite);
	// Calcule le prix de vente d'une quantite de produit donn�e
	float calculerDevis(TypeMarchandise type, int quantite);
	/// Vend des produits
	bool vendre(TypeMarchandise type, int quantite);

	std::vector<Marchandise*>* voirStock(TypeMarchandise type) const;

	virtual void jouerTour() = 0;	// Joue un tour de jeu
	/// Fabrique le produit indiqu�, en quantit� indiqu�e, 
	/// s�lectionne les ingredients n�cessaires automatiquement
	virtual void fabriquer(TypeMarchandise type, int quantite) = 0;	
	/// Fabrique le produit indiqu� avec les ingredients fournis
	virtual void fabriquer(TypeMarchandise type, std::vector<Marchandise*> ingredients) = 0;	
};

