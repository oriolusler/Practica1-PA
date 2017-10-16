#ifndef FIGURAGEOMETRICA_H
#define FIGURAGEOMETRICA_H


class FiguraGeometrica
{
    public:
        FiguraGeometrica(int x,int y, int colorF, int colorC);
        virtual ~FiguraGeometrica();
        int Getx() { return x; }
        void Setx(int val) { x = val; }
        int Gety() { return y; }
        void Sety(int val) { y = val; }
        int GetcolorC() { return colorC; }
        void SetcolorC(int val) { colorC = val; }
        int GetcolorF() { return colorF; }
        void SetcolorF(int val) { colorF = val; }
        static int Getvermell() { return vermell; }
        static int Getblau() { return blau; }
        static int Getnegre() { return negre; }
        static int Getblanc() { return blanc; }

        virtual double area() = 0;

        void toString();
        bool operator < (FiguraGeometrica *);
        bool operator > (FiguraGeometrica *);
        bool operator == (FiguraGeometrica *);

        static const int vermell = 0;
        static const int blau = 1;
        static const int negre=2;
        static const int blanc=3;

    protected:
    private:
        int x;
        int y;
        int colorC;
        int colorF;
};

#endif // FIGURAGEOMETRICA_H
