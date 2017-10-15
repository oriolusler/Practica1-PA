#ifndef DIBUIX_H
#define DIBUIX_H
#include "./FiguraGeometrica.h"
#include "./Rectangle.h"
#include "./Elipse.h"
#include <iostream>

class Dibuix
{
    public:
        Dibuix(int, int);
        Dibuix(int, int, FiguraGeometrica *);
        virtual ~Dibuix();
        void toString();

        int Geth() { return h; }
        int Getw() { return w; }

        int GetquantsN() { return quantsN; }
        int GetquantsS() { return quantsS; }

        double getArea();

        bool addFigura(FiguraGeometrica *);
        int DeterminarPos(FiguraGeometrica *);

        bool operator < (Dibuix *);
        bool operator > (Dibuix *);
        bool operator == (Dibuix *);

        bool buscarFigura(FiguraGeometrica *, int);

        bool remFigura(FiguraGeometrica *);
        int remFigura(int);

        bool comprobarCentre(FiguraGeometrica *);
    protected:
    private:
        int h;
        int w;
        int quantsN;
        int quantsS;
        int areaTotal;

        FiguraGeometrica *nord[10];
        FiguraGeometrica *sud[10];
};

#endif // DIBUIX_H
