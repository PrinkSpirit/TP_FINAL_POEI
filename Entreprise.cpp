/// Auteur: Pierre MASSONIE

#include "Entreprise.h"

Entreprise::Entreprise() : m_nom("Sans nom"), tresorerie(0.0f)
{
}

Entreprise::Entreprise(std::string nom, float capitalDepart) : m_nom(nom), tresorerie(capitalDepart)
{
}

Entreprise::~Entreprise()
{
}



float Entreprise::devisAchat(Entreprise* entreprise, TypeMarchandise type, int quantite)
{
	return 0.0f;
}

bool Entreprise::acheter(Entreprise* entreprise, TypeMarchandise type, int quantite)
{

}

float Entreprise::calculerDevis(TypeMarchandise type, int quantite)
{
	return 0.0f;
}

bool Entreprise::vendre(TypeMarchandise type, int quantite)
{
}

std::vector<Marchandise*>* Entreprise::voirStock(TypeMarchandise type) const
{
	return nullptr;
}
