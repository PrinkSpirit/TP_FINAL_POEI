/// Auteur: Pierre MASSONIE

#include "Marchandise.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Marchandise& m)
{
    os << "[" << m.m_id << "]" << m.m_nom << " - " << m.m_prix << "$ " << m.m_qualite << "%";
    return os;
}

Marchandise::Marchandise(std::string type) : m_nom(type) {
	m_type = bddProduit::getInstance()->produitParNom(type);
}

Marchandise::Marchandise(TypeProduit type) : m_nom(type.m_nom), m_type(type) {}
