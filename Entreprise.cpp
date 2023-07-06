/// Auteur: Pierre MASSONIE

#include "Entreprise.h"

Entreprise::Entreprise() : m_nom("Sans nom"), m_tresorerie(0.0f)
{
}

Entreprise::Entreprise(std::string nom, float capitalDepart) : m_nom(nom), m_tresorerie(capitalDepart)
{
}

Entreprise::Entreprise(std::string nom, float capitalDepart, std::vector<std::string> listeProduit) : m_nom(nom), m_tresorerie(capitalDepart), m_produits(listeProduit)
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

std::vector<std::string>& Entreprise::getProduits() const
{
	return &m_produits;
}



float Entreprise::devisAchat(Entreprise* entreprise, std::string type, int quantite)
{
	return 0.0f;
}

bool Entreprise::acheter(Entreprise* entreprise, std::string type, int quantite)
{

}

float Entreprise::calculerDevis(std::string type, int quantite)
{
	return 0.0f;
}

bool Entreprise::vendre(std::string type, int quantite)
{
}

std::vector<Marchandise*>* Entreprise::voirStock(std::string type) const
{
	return nullptr;
}
