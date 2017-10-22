#include <iostream>
#include "../include/Elipse.h"
#include "../include/FiguraGeometrica.h"
#include "../include/Rectangle.h"

#define _USE_MATH_DEFINES // for C++

#include <cmath>

using namespace std;

Elipse::Elipse(int radi1, int radi2, int x, int y, int colorC, int colorF) : FiguraGeometrica(x, y, colorC, colorF) {
    this->radi1 = radi1;
    this->radi2 = radi2;
    if (esCercle()) quantsC++;


}

double Elipse::area() {
    return M_PI * Getradi1() * Getradi2();

}

bool Elipse::esCercle() {
    return Getradi1() == Getradi2();
}

void Elipse::toString() {
    FiguraGeometrica::toString();
    cout << "Area: " << area() << endl;
    cout << "Radi 1: " << Getradi1() << " i radi 2 " << Getradi2() << endl;
}
