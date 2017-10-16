#ifndef ELIPSE_H
#define ELIPSE_H

#include "FiguraGeometrica.h"

class Elipse: public FiguraGeometrica
{
    public:
        Elipse(int radi1, int radi2, int x , int y, int colorF, int colorC);
        int Getradi1() { return radi1; }
        // void Setradi1(int val) { radi1 = val; }
        int Getradi2() { return radi2; }
        // void Setradi2(int val) { radi2 = val; }
        int GetquantsC() {return quantsC;}
        void toString();
        bool esCercle();

        //virtual double area(); PREGUNTAR LINA

        double area();

    protected:
    private:
        int radi1;
        int radi2;
        int quantsC;
};

#endif // ELIPSE_H
