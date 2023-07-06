#include "Marchandise.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Marchandise& m)
{
    os << "[" << m.id << "]" << m.nom << " - " << m.prix << "& " << m.qualite << "%";
    return os;
}
