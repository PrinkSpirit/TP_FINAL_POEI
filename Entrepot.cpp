/// Auteur: Pierre MASSONIE
#include "Entrepot.h"

#include <iostream>

Entrepot::Entrepot() {
}

Entrepot::~Entrepot() {
	for (auto it = m_stock.begin(); it != m_stock.end(); it++) {
		for (int i = 0; i < it->second.size(); i++) {
			delete it->second[i];
		}
	}
}

void Entrepot::stocker(Marchandise* marchandise) {
	m_stock[marchandise->type].push_back(marchandise);
}

void Entrepot::destocker(Marchandise* marchandise) {
	std::vector<Marchandise*>* listeMarchandise = &m_stock[marchandise->type];

	for (int i = 0; i < listeMarchandise->size(); i++) {
		if (listeMarchandise->at(i)->id == marchandise->id) {
			listeMarchandise->erase(listeMarchandise->begin() + i);
			return;
		}
	}
}

void Entrepot::destocker(TypeMarchandise type, int id) {
	std::vector<Marchandise*>* listeMarchandise = &m_stock[type];

	for (int i = 0; i < listeMarchandise->size(); i++) {
		if (listeMarchandise->at(i)->id == id) {
			listeMarchandise->erase(listeMarchandise->begin() + i);
			return;
		}
	}
}

int Entrepot::nombreProduit(TypeMarchandise type) {
	return m_stock[type].size();
}

void Entrepot::afficherStock() {
	for (auto it = m_stock.begin(); it != m_stock.end(); it++) {
		std::cout << "Type: " << (int)it->first << std::endl;

		for (int i = 0; i < it->second.size(); i++) {
			std::cout << it->second[i]->id << ":" << it->second[i]->nom << std::endl;
		}
	}
}

inline std::vector<Marchandise*>* Entrepot::getStock(TypeMarchandise type) { return &m_stock[type]; }
