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

void Entreprise::acheter()
{
}

void Entreprise::vendre()
{
}
