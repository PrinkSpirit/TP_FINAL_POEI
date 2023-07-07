#include "Marchandise.h"

#include <iostream>

std::ostream& operator<<(std::ostream& os, const Marchandise& m)
{
    os << "[" << m.m_id << "]" << m.m_nom << " - " << m.m_prix << "& " << m.m_qualite << "%";
    return os;
}
