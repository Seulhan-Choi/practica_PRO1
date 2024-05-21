#include "Data.hpp"

// Constructors
Data::Data() : dia(0), mes(0), any(0) {}

Data::Data(int dia, int mes, int any) : dia(dia), mes(mes), any(any) {}

// Destructor
Data::~Data() {}

// Consultors
int Data::getDia() const {
    return dia;
}

int Data::getMes() const {
    return mes;
}

int Data::getAny() const {
    return any;
}

bool Data::operator>(const Data &d) const {
    if (any != d.any) return any > d.any;
    if (mes != d.mes) return mes > d.mes;
    return dia > d.dia;
}
