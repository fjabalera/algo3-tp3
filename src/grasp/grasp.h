#ifndef GRASP_H
#define GRASP_H

#include "heuristica.h"

using namespace std;

class Grasp
{
    public:
        Grasp(Heuristica h);
        virtual ~Grasp();
        void setParadaMaximoIteraciones(int paradaMaximoIteraciones);
        void setParadaIteracionesSinMejora(int paradaIteracionesSinMejora);
        void setProfundidadEleccionVertice(int profundidadEleccionVertice);
        void setProfundidadEleccionConjunto(int profundidadEleccionConjunto);
        void ejecutar(int criterioParada);
        
        static const int pararPorMaximoIteraciones{0};
        static const int pararPorIteracionesSinMejora{1};
        static const int pararPorMaximoYPorSinMejora{2};
    private:
        bool parar(int criterio);
        float pesoParticion(const vector<set<int>> & particion);
        void busquedaLocalUnNodo();
    
        Heuristica h_;
        vector<set<int>> particionActual_;
        vector<set<int>> mejorParticion_;
        unsigned int paradaMaximoIteraciones_{10000};
        unsigned int paradaIteracionesSinMejora_{1000};
        unsigned int iteracionActual_{0};
        unsigned int ultimaIteracionConMejora_{0};
        float pesoParticionActual_{0.f};
        float pesoMejorParticion_{0.f};
};

#endif /* GRASP_H */ 