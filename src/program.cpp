#include <iostream>
#include "Plataforma.hpp"

using namespace std;

/** Programa principal
 *
 * main() crea la plataforma, fa la lectura d'instruccions i
 * l'escriptura de resultats. Les operacions estan definides i
 * implementades en les classes Plataforma, Classificacio, LlibreE i Data.
 */

int main() {
	
	// Crear la plataforma
    Plataforma plataforma;
    string inst;
	
	// Processar instruccions
	
    string inst;
	
    while ((cin >> inst) && (inst != "fi")) {
		
        // Tractar instrucció
        if (inst == "alta llibre") {
            string titol;
            Data data;
            int numParaules;
            vector<string> paraulesClau;
            cin >> titol >> data >> numParaules;
            for (int i = 0; i < numParaules; ++i) {
                string paraula;
                cin >> paraula;
                paraulesClau.push_back(paraula);
            }
            plataforma.altaLlibre(titol, data, paraulesClau);
        } else if (inst == "baixa llibre") {
            string titol;
            cin >> titol;
            plataforma.baixaLlibre(titol);
        } else if (inst == "classifica llibre") {
            plataforma.classificaLlibre();
        } else if (inst == "classifica") {
            plataforma.classifica();
        } else if (inst == "mostra llibres") {
            plataforma.mostraLlibres();
        } else if (inst == "mostra llibres area") {
            string area;
            cin >> area;
            plataforma.mostraLlibresArea(area);
        } else if (inst == "llista pendents") {
            plataforma.llistaPendents();
        }
    }
    return 0;
}