#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "FiguraGeometrica.h"

class Rectangle : public FiguraGeometrica
{
    public:
        Rectangle(int w, int h, int, int, int colorF, int colorC);
        virtual ~Rectangle();
        int Getw() { return w; }
        // void Setw( int val) { w = val; }
        int Geth() { return h; }
        // void Seth( int val) { h = val; }
        int GetquantsQ() { return quantsQ; }
        void toString();
        bool esQuadrat();

        //virtual double area(); PREGUNTAR LINA
        double area();

    protected:
    private:
         int w;
         int h;
         int quantsQ;
};

#endif // RECTANGLE_H
