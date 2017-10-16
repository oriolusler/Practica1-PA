#include <iostream>
#include "../include/Elipse.h"
#include "../include/FiguraGeometrica.h"
#include "../include/Rectangle.h"

using namespace std;

Rectangle::Rectangle(int w, int h, int x , int y, int colorF, int colorC) : FiguraGeometrica (x, y, colorC, colorF) {
    if(w < 0 || h < 0) throw invalid_argument("Te una medida negativa |Rectangle.cpp | 10");

    this->w = w;
    this->h = h;

    if(esQuadrat()) quantsQ++;

}

double Rectangle :: area(){
     return Getw() *Geth() ;

}

void Rectangle :: toString(){
    FiguraGeometrica::toString();
    cout << "Area: " << area() <<endl;
    cout << "Altura de " << Geth() << " i amplada de " << Getw() <<endl;

}

bool Rectangle :: esQuadrat(){
        return Getw() == Geth();
}

Rectangle::~Rectangle(){
//dtor
}
