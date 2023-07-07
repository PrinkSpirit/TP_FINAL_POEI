/// Auteur: Pierre MASSONIE

#include "Entreprise.h"

Entreprise::Entreprise() : m_nom("Sans nom"), m_tresorerie(0.0f), m_bddProduit(bddProduit::getInstance())
{
}

Entreprise::Entreprise(std::string nom, float capitalDepart) : m_nom(nom), m_tresorerie(capitalDepart), m_bddProduit(bddProduit::getInstance())
{
}

Entreprise::Entreprise(std::string nom, float capitalDepart, std::vector<std::string> listeProduit) : m_nom(nom), m_tresorerie(capitalDepart), m_produits(listeProduit), m_bddProduit(bddProduit::getInstance())
{

}

Entreprise::~Entreprise()
{
}

std::string Entreprise::getNom() const
{
	return m_nom;
}

float Entreprise::getTresorerie() const
{
	return m_tresorerie;
}

std::vector<std::string> Entreprise::getProduits() const
{
	return m_produits;
}

// Calcul du devis d'achat d'une marchandise, de façon naive pour le moment
float Entreprise::devisAchat(Entreprise* entreprise, std::string type, int quantite)
{
	
	return entreprise->calculerDevis(type, quantite);
}

bool Entreprise::acheter(Entreprise* entreprise, std::string type, int quantite)
{
	float devis = devisAchat(entreprise, type, quantite);
	if(devis < m_tresorerie) {
		m_tresorerie -= devis;
		m_entrepot.stocker(entreprise->vendre(type, quantite));
		return true;
	}

	return false;
}

bool Entreprise::acheter(Entreprise* entreprise, std::vector<Marchandise*> marchandises)
{
	std::vector<Marchandise*> panier;
	panier = entreprise->vendre(marchandises);
	if (panier == marchandises) {
		m_entrepot.stocker(panier);
		return true;
	}

	return false;
}

float Entreprise::calculerDevis(std::string type, int quantite)
{
	std::vector<Marchandise*>* stock = m_entrepot.getStock(type);
	float devis = 0.0f;
	if (stock->size() >= quantite) {
		for (int i = 0; i < quantite; i++) {
			devis += stock->at(i)->m_prix;
		}
	}
	return devis;
}

std::vector<Marchandise*> Entreprise::vendre(std::string type, int quantite)
{
	std::vector<Marchandise*> marchandises;
	if (m_entrepot.nombreProduit(type) >= quantite) {
		std::vector<Marchandise*>* stock = m_entrepot.getStock(type);
		for (int i = 0; i < quantite; i++) {
			marchandises.push_back(stock->at(i));
		}
		for (int i = 0; i < quantite; i++) {
			m_entrepot.destocker(marchandises[i]);
		}
	}

	return marchandises;
}

std::vector<Marchandise*> Entreprise::vendre(std::vector<Marchandise*> marchandises)
{
	std::vector<Marchandise*> panier;
	for(auto &marchandise : marchandises) {
		if (m_entrepot.enInventaire(marchandise)) {
			panier.push_back(marchandise);
		}
	}

	return panier;
}

std::vector<Marchandise*>* Entreprise::voirStock(std::string type)
{
	return m_entrepot.getStock(type);
}
