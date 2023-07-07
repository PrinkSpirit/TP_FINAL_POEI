/// Auteur: Pierre MASSONIE

#include "TypeProduit.h"


std::ostream& operator<<(std::ostream& os, const TypeProduit& typeProduit) {
	os << typeProduit.m_nom;
	if (typeProduit.m_listeIngredients.size() != 0)
		os << " : ";
		for (auto& ingredient : typeProduit.m_listeIngredients) {
			os << ingredient.first << " (" << ingredient.second << ") ";
		}
	return os;
}