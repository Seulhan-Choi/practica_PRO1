#ifndef LLIBREE_HPP
#define LLIBREE_HPP
#include "Data.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define nat unsigned int

class LlibreE {
// Tipus de mòdul: dades
// Descripció del tipus: Representa un llibre electrònic
// que consta de títol, data de publicació, àrea temàtica
// i paraules clau que descriuen el seu contingut.

	public:

		//*********************************************************
		// Constructors i assignació
		//*********************************************************
		
		/* Pre: cert */ 
		/* Post: crea un llibre amb el títol, data de publicació i 
		   àrea buits, i sense paraules clau */
		LlibreE();
		
		/* Pre: cert */ 
		/* Post: crea un llibre amb el títol, data de publicació, 
		   àrea i paraules clau del llibre 'le' */
		LlibreE(const LlibreE &le);
		  
		/* Pre: cert */
		/* Post: el resultat és un llibre amb el títol, data de 
		   publicació, àrea i paraules clau del llibre 'le' */	 
		LlibreE& operator=(const LlibreE &le);
		  
		//*********************************************************
		// Destructor
		//*********************************************************
		
		/* Destructor per defecte */ 
		~LlibreE();
	  
	    //*********************************************************
		// Modificadors
		//*********************************************************
	 
	 
		/* Pre: cert */
        /* Post: modifica el dia de la data paràmetre implícit */
        void setDia(int dia);

        /* Pre: cert */
        /* Post: modifica el mes de la data paràmetre implícit */
        void setMes(int mes);

        /* Pre: cert */
        /* Post: modifica l'any de la data paràmetre implícit */
        void setAny(int any);

        /* Pre: cert */
        /* Post: modifica el títol del llibre paràmetre implícit */
        void setTitol(const string &titol);

        /* Pre: cert */
        /* Post: modifica l'àrea temàtica del llibre paràmetre implícit */
        void setArea(const string &area);

        /* Pre: cert */
        /* Post: afegeix una paraula clau al llibre paràmetre implícit */
        void afegirParaulaClau(const string &paraula);

	  

	    //*********************************************************
		// Consultors
		//*********************************************************
		
		/* Pre: cert */ 
		/* Post: el resultat és el títol del llibre p.i. */
		string consultar_titol() const;
	  
		/* Pre: cert */ 
		/* Post: el resultat és la data de publicació del llibre p.i. */
		Data consultar_dataPub() const;
	  
		/* Pre: cert */ 
		/* Post: el resultat és l'àrea temàtica del llibre p.i. */
		string consultar_area() const;
	  
	    /* Pre: cert */
	    /* Post: retorna un booleà que indica si la data de publicació del 
		   llibre p.i. és posterior a la del llibre 'le' (true) o no ho és (false) */
	    bool compare(const LlibreE &le) const;
		
		/* Pre: cert */
        /* Post: el resultat són les paraules clau del llibre p.i. */
        vector<string> consultar_paraulesClau() const;
		
		
		//*********************************************************
		// Lectura i escriptura
		//*********************************************************


		/* Pre: estan preparats al canal estàndard d'entrada tres enters */
        /* Post: la data 'd' passa a tenir els enters llegits del canal
           estàndard d'entrada com a dia, mes i any, respectivament */        
        friend istream& operator>>(istream &is, Data &d); 

        /* Pre: cert */
        /* Post: s'han escrit els atributs dia, mes i any de la data 'd'
           al canal estàndard de sortida */
        friend ostream& operator<<(ostream &os, const Data &d); 


	  
	private:

	    string titol;
        Data dataPublicacio;
        string areaTematica;
        vector<string> paraulesClau;
  
};
#endif