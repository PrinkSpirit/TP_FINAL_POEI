/// Auteur: Pierre MASSONIE
/// Définition de la Factory pure Entreprise

#pragma once


#include "Marchandise.h"
#include "TypeProduit.h"
#include "bddProduit.h"
#include "Entrepot.h"

#include <string>
#include <vector>

class Entreprise
{
protected:
	std::string m_nom;				/// Nom de l'entreprise
	float m_tresorerie;				/// Quantite d'argent disponible
	bddProduit* m_bddProduit;		/// Base de données des produits

	Entrepot m_entrepot;			/// Entrepot de l'entreprise
	std::vector<std::string> m_produits;	/// Liste des produits fabriqués par l'entreprise

public:
	Entreprise();
	Entreprise(std::string nom, float capitalDepart);
	Entreprise(std::string nom, float capitalDepart, std::vector<std::string> listeProduit);
	virtual ~Entreprise();

	/// Retourne le nom de l'entreprise
	std::string getNom() const;
	/// Retourne la tresorerie de l'entreprise
	float getTresorerie() const;
	/// Retourne la list des types de produits vendus
	std::vector<std::string> getProduits() const;

	// Donne le prix d'achat d'une quantite de produit à une entreprise donnée
	float devisAchat(Entreprise* entreprise, std::string type, int quantite);
	// Achete des produits
	bool acheter(Entreprise* entreprise, std::string type, int quantite);
	/// Permet de cibler des produits spécifiques
	bool acheter(Entreprise* entreprise, std::vector<Marchandise*> marchandises);
	// Calcule le prix de vente d'une quantite de produit donnée
	float calculerDevis(std::string type, int quantite);
	/// Vend des produits
	std::vector<Marchandise*> vendre(std::string type, int quantite);
	/// Permet de cibler des produits spécifiques
	std::vector<Marchandise*> vendre(std::vector<Marchandise*> marchandises);

	/// Renvoie la liste des marchandises d'un certain type
	std::vector<Marchandise*>* voirStock(std::string type);

	virtual void jouerTour();	// Joue un tour de jeu
	/// Fabrique le produit indiqué, en quantité indiquée, 
	/// sélectionne les ingredients nécessaires automatiquement
	virtual void fabriquer(std::string type, int quantite);
	/// Fabrique le produit indiqué avec les ingredients fournis
	virtual void fabriquer(std::string type, std::vector<Marchandise*> ingredients);
};

