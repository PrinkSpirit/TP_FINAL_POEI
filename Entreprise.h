/// Auteur: Pierre MASSONIE
/// Définition de la Factory pure Entreprise

#pragma once

#include <string>

class Entreprise
{
protected:
	std::string m_nom; // Nom de l'entreprise
	float tresorerie;  // Quantite d'argent disponible

	// TODO: Entrepos

public:
	Entreprise();
	Entreprise(std::string nom, float capitalDepart);
	virtual ~Entreprise();

	void acheter();				  // Achete des produits
	void vendre();				  // Vend des produits

	virtual void jouerTour() = 0; // Joue un tour de jeu
	virtual void fabriquer() = 0; // Fabrique le produit indiqué, en quantité indiquée
};

