// Classificacio.cpp
#include "Classificacio.hpp"

//*********************************************************
// Constructors i assignació
//*********************************************************

Classificacio::Classificacio() : arrelTematica() {}

//*********************************************************
// Modificadors
//*********************************************************

void Classificacio::afegirArea(const string &area) {
    if (arrelTematica.isEmpty()) {
        arrelTematica = BinaryTree<string>(area, BinaryTree<string>(), BinaryTree<string>());
    } else {
        // Implement a strategy to add a new area into the binary tree.
        // For simplicity, we will add it to the leftmost empty position.
        BinaryTree<string>* node = &arrelTematica;
        while (!node->getLeft().isEmpty() && !node->getRight().isEmpty()) {
            node = &node->getLeft();
        }
        if (node->getLeft().isEmpty()) {
            node->getLeft() = BinaryTree<string>(area, BinaryTree<string>(), BinaryTree<string>());
        } else {
            node->getRight() = BinaryTree<string>(area, BinaryTree<string>(), BinaryTree<string>());
        }
    }
}

void Classificacio::classificarLlibre(LlibreE &llibre, const string &area) const {
    if (conteArea(area)) {
        llibre.setArea(area);
    }
}

void Classificacio::afegirAreaAlArbre(BinaryTree<string> &arbre, const string &area) {
    if (arbre.isEmpty()) {
        arbre = BinaryTree<string>(area, BinaryTree<string>(), BinaryTree<string>());
    } else {
        if (area < arbre.getRoot()) {
            afegirAreaAlArbre(arbre.getLeft(), area);
        } else {
            afegirAreaAlArbre(arbre.getRight(), area);
        }
    }
}

//*********************************************************
// Consultors
//*********************************************************

bool Classificacio::conteArea(const string &area) const {
    return conteAreaRec(arrelTematica, area);
}

bool Classificacio::conteAreaRec(const BinaryTree<string> &arbre, const string &area) const {
    if (arbre.isEmpty()) return false;
    if (arbre.getRoot() == area) return true;
    return conteAreaRec(arbre.getLeft(), area) || conteAreaRec(arbre.getRight(), area);
}
