#ifndef CLASSIFICACIO_HPP
#define CLASSIFICACIO_HPP

#include <string>
#include "LlibreE.hpp"
#include "BinaryTree.hpp"

using namespace std;

class Classificacio {
public:
    // Constructors i assignació

    /* Pre: cert */
    /* Post: crea una classificació amb l'arbre temàtic buit */
    Classificacio();

    // Modificadors

    /* Pre: cert */
    /* Post: afegeix una àrea temàtica al conjunt d'àrees */
    void afegirArea(const string &area);

    /* Pre: cert */
    /* Post: classifica un llibre electrònic en una àrea temàtica donada */
    void classificarLlibre(LlibreE &llibre, const string &area) const;

    // Consultors

    /* Pre: cert */
    /* Post: retorna un booleà que indica si l'àrea està present en la classificació */
    bool conteArea(const string &area) const;

private:
    BinaryTree<string> arrelTematica;

    bool conteAreaRec(const BinaryTree<string> &arbre, const string &area) const;
};

#endif
