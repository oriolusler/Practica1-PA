#ifndef DIBUIX_H
#define DIBUIX_H
#include "./FiguraGeometrica.h"
#include "./Rectangle.h"
#include "./Elipse.h"
#include <iostream>

class Dibuix
{
    public:
        Dibuix(int, int) throw(char*);
        Dibuix(int, int, FiguraGeometrica*);
        virtual ~Dibuix();
        void toString();

        int Geth() { return h; }
        int Getw() { return w; }

        double getArea();

        void addFigura(FiguraGeometrica *) throw(char*);

        bool operator < (Dibuix *);
        bool operator > (Dibuix *);
        bool operator == (Dibuix *);

        bool remFigura(FiguraGeometrica*)throw(char*);
        int remFigura(int);


    protected:
    private:
        int h;
        int w;
        int quantsN;
        int quantsS;
        int areaTotal;

        FiguraGeometrica* nord[10];
        FiguraGeometrica* sud[10];

        int DeterminarPos(FiguraGeometrica *);
        bool buscarFigura(FiguraGeometrica*, int);
        bool comprobarCentre(FiguraGeometrica*);

};

#endif // DIBUIX_H
