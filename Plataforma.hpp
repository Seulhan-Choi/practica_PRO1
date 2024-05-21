#ifndef PLATAFORMA_HPP
#define PLATAFORMA_HPP

#include <string>
#include <vector>
#include <map>
#include "LlibreE.hpp"
#include "Classificacio.hpp"
#include "PriorityQueue.hpp"

using namespace std;

class Plataforma {
public:
    // Constructors i assignació

    /* Pre: cert */
    /* Post: crea una plataforma buida amb el sistema de classificació inicialitzat */
    Plataforma();

    // Modificadors

    /* Pre: el llibre amb títol 'titol' no existeix a la plataforma */
    /* Post: afegeix el llibre amb el títol, data de publicació i paraules clau donades a la plataforma */
    void altaLlibre(const string &titol, const Data &data, const vector<string> &paraulesClau);

    /* Pre: el llibre amb títol 'titol' existeix a la plataforma */
    /* Post: elimina el llibre amb títol 'titol' de la plataforma */
    void baixaLlibre(const string &titol);

    /* Pre: cert */
    /* Post: classifica el primer llibre de la llista de pendents */
    void classificaLlibre();

    /* Pre: cert */
    /* Post: classifica tots els llibres de la llista de pendents */
    void classifica();

    // Consultors

    /* Pre: cert */
    /* Post: mostra tots els llibres de la plataforma ordenats per data de publicació de més recent a més antiga */
    void mostraLlibres() const;

    /* Pre: l'àrea temàtica 'area' existeix */
    /* Post: mostra tots els llibres de la plataforma que pertanyen a l'àrea temàtica 'area' */
    void mostraLlibresArea(const string &area) const;

    /* Pre: cert */
    /* Post: mostra tots els llibres de la llista de pendents ordenats per data de publicació de més recent a més antiga */
    void llistaPendents() const;

private:
    Queue<LlibreE> pendents; // Priority queue of pending books to classify
    Classificacio classificacio; // Classification system

    /* Pre: cert */
    /* Post: retorna l'àrea temàtica més precisa que cobreix totes les paraules clau donades */
    string determinarAreaTematica(const vector<string> &paraulesClau) const;
};

#endif
