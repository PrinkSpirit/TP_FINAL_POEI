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
	float m_tresorerie;				// Quantite d'argent disponible

	Entrepot m_entrepot;			// Entrepot de l'entreprise

	std::vector<std::string> m_produits;	// Liste des produits fabriqu�s par l'entreprise

public:
	Entreprise();
	Entreprise(std::string nom, float capitalDepart);
	Entreprise(std::string nom, float capitalDepart, std::vector<std::string> listeProduit);
	virtual ~Entreprise();

	std::string getNom() const;
	float getTresorerie() const;
	std::vector<std::string> getProduits() const;

	// Donne le prix d'achat d'une quantite de produit � une entreprise donn�e
	float devisAchat(Entreprise* entreprise, std::string type, int quantite);
	// Achete des produits
	bool acheter(Entreprise* entreprise, std::string type, int quantite);
	// Calcule le prix de vente d'une quantite de produit donn�e
	float calculerDevis(std::string type, int quantite);
	/// Vend des produits
	std::vector<Marchandise*> vendre(std::string type, int quantite);

	std::vector<Marchandise*>* voirStock(std::string type);

	virtual void jouerTour() {};	// Joue un tour de jeu
	/// Fabrique le produit indiqu�, en quantit� indiqu�e, 
	/// s�lectionne les ingredients n�cessaires automatiquement
	virtual void fabriquer(std::string type, int quantite) {};
	/// Fabrique le produit indiqu� avec les ingredients fournis
	virtual void fabriquer(std::string type, std::vector<Marchandise*> ingredients) {};
};

