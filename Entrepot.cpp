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
	m_stock[marchandise->nom].push_back(marchandise);
}

void Entrepot::stocker(std::vector<Marchandise*> marchandises)
{
	if(marchandises.size() > 0) {
		m_stock[marchandises[0]->nom].insert(m_stock[marchandises[0]->nom].end(), marchandises.begin(), marchandises.end());
	}
}

void Entrepot::destocker(Marchandise* marchandise) {
	std::vector<Marchandise*>* listeMarchandise = &m_stock[marchandise->nom];

	for (int i = 0; i < listeMarchandise->size(); i++) {
		if (listeMarchandise->at(i)->id == marchandise->id) {
			listeMarchandise->erase(listeMarchandise->begin() + i);
			return;
		}
	}
}

void Entrepot::destocker(std::string type, int id) {
	std::vector<Marchandise*>* listeMarchandise = &m_stock[type];

	for (int i = 0; i < listeMarchandise->size(); i++) {
		if (listeMarchandise->at(i)->id == id) {
			listeMarchandise->erase(listeMarchandise->begin() + i);
			return;
		}
	}
}

int Entrepot::nombreProduit(std::string type) {
	return m_stock[type].size();
}

void Entrepot::afficherStock() {
	for (auto it = m_stock.begin(); it != m_stock.end(); it++) {
		for (int i = 0; i < it->second.size(); i++) {
			std::cout << it->second[i] << std::endl;
		}
	}
}

std::vector<Marchandise*>* Entrepot::getStock(std::string type) { 
	return &m_stock[type]; 
}
