#include "Plataforma.hpp"
#include <iostream>
#include <algorithm> // Include this header for the sort function

Plataforma::Plataforma() : classificacio() {}

void Plataforma::altaLlibre(const string &titol, const Data &data, const vector<string> &paraulesClau) {
    if (llibres.find(titol) != llibres.end()) {
        cerr << "Error: Llibre ja existeix" << endl;
        return;
    }
    LlibreE llibre;
    llibre.setTitol(titol);
    llibre.setDia(data.getDia());
    llibre.setMes(data.getMes());
    llibre.setAny(data.getAny());
    for (const auto &paraula : paraulesClau) {
        llibre.afegirParaulaClau(paraula);
    }
    llibres[titol] = llibre;
    pendents.push(llibre);
}

void Plataforma::baixaLlibre(const string &titol) {
    auto it = llibres.find(titol);
    if (it == llibres.end()) {
        cerr << "Error: Llibre no existeix" << endl;
        return;
    }
    pendents.remove(it->second);
    llibres.erase(it);
}

void Plataforma::classificaLlibre() {
    if (pendents.empty()) {
        cerr << "Error: No hi ha llibres pendents de classificació" << endl;
        return;
    }
    LlibreE llibre = pendents.front();
    pendents.pop();
    // Here you would determine the most specific area for the book
    // For simplicity, we'll classify it under a generic area
    string area = "General"; // Replace this with the actual classification logic
    classificacio.classificarLlibre(llibre, area);
    llibres[llibre.consultar_titol()] = llibre;
}

void Plataforma::classifica() {
    while (!pendents.empty()) {
        classificaLlibre();
    }
}

void Plataforma::mostraLlibres() const {
    for (const auto &pair : llibres) {
        const LlibreE &llibre = pair.second;
        cout << llibre.consultar_titol() << " " << llibre.consultar_dataPub() << " ";
        vector<string> paraulesClau = llibre.consultar_paraulesClau();
        sort(paraulesClau.begin(), paraulesClau.end());
        for (const auto &paraula : paraulesClau) {
            cout << paraula << " ";
        }
        cout << llibre.consultar_area() << endl;
    }
}

void Plataforma::mostraLlibresArea(const string &area) const {
    if (!classificacio.conteArea(area)) {
        cerr << "Error: Àrea temàtica no existeix" << endl;
        return;
    }
    for (const auto &pair : llibres) {
        const LlibreE &llibre = pair.second;
        if (llibre.consultar_area() == area) {
            cout << llibre.consultar_titol() << " " << llibre.consultar_dataPub() << " ";
            vector<string> paraulesClau = llibre.consultar_paraulesClau();
            sort(paraulesClau.begin(), paraulesClau.end());
            for (const auto &paraula : paraulesClau) {
                cout << paraula << " ";
            }
            cout << llibre.consultar_area() << endl;
        }
    }
}

void Plataforma::llistaPendents() const {
    /*for (int i = 0; i < pendents.size(); ++i) {
        const LlibreE &llibre = pendents[i];
        cout << llibre.consultar_titol() << " " << llibre.consultar_dataPub() << " ";
        vector<string> paraulesClau = llibre.consultar_paraulesClau();
        sort(paraulesClau.begin(), paraulesClau.end());
        for (const auto &paraula : paraulesClau) {
            cout << paraula << " ";
        }
        cout << llibre.consultar_area() << endl;
    }*/
}
