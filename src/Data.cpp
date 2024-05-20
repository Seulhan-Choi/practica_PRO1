// Data.cpp
#include "Data.hpp"

// Constructors

Data::Data() : dia(0), mes(0), any(0) {
    // Creates an empty date
}

Data::Data(int dia, int mes, int any) : dia(dia), mes(mes), any(any) {
    // Creates a date with the given day, month, and year
}

// Destructor

Data::~Data() {
    // Default destructor
}

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
    if (any > d.any) return true;
    if (any == d.any && mes > d.mes) return true;
    if (any == d.any && mes == d.mes && dia > d.dia) return true;
    return false;
}

// Lectura i escriptura

istream& operator>>(istream &is, Data &d) {
    is >> d.dia >> d.mes >> d.any;
    return is;
}

ostream& operator<<(ostream &os, const Data &d) {
    os << d.dia << "/" << d.mes << "/" << d.any;
    return os;
}
