// LlibreE.cpp
#include "LlibreE.hpp"

//*********************************************************
// Constructors i assignació
//*********************************************************

LlibreE::LlibreE() : titol(""), dataPublicacio(), areaTematica(""), paraulesClau() {}

LlibreE::LlibreE(const LlibreE &le) : titol(le.titol), dataPublicacio(le.dataPublicacio), areaTematica(le.areaTematica), paraulesClau(le.paraulesClau) {}

LlibreE& LlibreE::operator=(const LlibreE &le) {
    if (this != &le) {
        titol = le.titol;
        dataPublicacio = le.dataPublicacio;
        areaTematica = le.areaTematica;
        paraulesClau = le.paraulesClau;
    }
    return *this;
}

//*********************************************************
// Destructor
//*********************************************************

LlibreE::~LlibreE() {}


//*********************************************************
// Modificadors
//*********************************************************

void LlibreE::setDia(int dia) {
    int mes = dataPublicacio.getMes();
    int any = dataPublicacio.getAny();
    dataPublicacio = Data(dia, mes, any);
}

void LlibreE::setMes(int mes) {
    int dia = dataPublicacio.getDia();
    int any = dataPublicacio.getAny();
    dataPublicacio = Data(dia, mes, any);
}

void LlibreE::setAny(int any) {
    int dia = dataPublicacio.getDia();
    int mes = dataPublicacio.getMes();
    dataPublicacio = Data(dia, mes, any);
}

void LlibreE::setTitol(const string &titol) {
    this->titol = titol;
}

void LlibreE::setArea(const string &area) {
    this->areaTematica = area;
}

void LlibreE::afegirParaulaClau(const string &paraula) {
    paraulesClau.push_back(paraula);
}

//*********************************************************
// Consultors
//*********************************************************

string LlibreE::consultar_titol() const {
    return titol;
}

Data LlibreE::consultar_dataPub() const {
    return dataPublicacio;
}

string LlibreE::consultar_area() const {
    return areaTematica;
}

vector<string> LlibreE::consultar_paraulesClau() const {
    return paraulesClau;
}

bool LlibreE::compare(const LlibreE &le) const {
    return dataPublicacio > le.dataPublicacio;
}

//*********************************************************
// Lectura i escriptura
//*********************************************************

istream& operator>>(istream &is, Data &d) {
    int dia, mes, any;
    is >> dia >> mes >> any;
    d = Data(dia, mes, any);
    return is;
}

ostream& operator<<(ostream &os, const Data &d) {
    os << d.getDia() << "/" << d.getMes() << "/" << d.getAny();
    return os;
}
