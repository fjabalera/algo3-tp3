#ifndef HEURISTICA_H
#define HEURISTICA_H

#include <vector>
#include <set>

typedef std::vector<std::vector<int>> Grafo;

class Heuristica
{
    public:
        Heuristica(Grafo & grafo, int k);
        virtual ~Heuristica();
        
        std::vector<std::set<int>> resolver();
    
    private:
        int pesoEnGrafo(int vertice);
        int pesoEnSubconjunto(int vertice, std::set<int> & conjuntoVertices);
        std::vector<int> ordenarPorPesoEnGrafo();
    
        Grafo grafo_;
        int k_;
};

#endif /* HEURISTICA_H */ 