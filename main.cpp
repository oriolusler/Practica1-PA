#include <iostream>
#include "./include/Elipse.h"
#include "./include/Rectangle.h"
#include "./include/Dibuix.h"

using namespace std;

int main() {


    FiguraGeometrica *quadrat;
    quadrat = new Rectangle(78, 78, 76, 78, 2, 0);

    FiguraGeometrica *rectangle;
    rectangle = new Rectangle(135, 54, 145, 175, 4, 3);

    FiguraGeometrica *elipse;
    elipse = new Elipse(67, 122, 210, 125, 5, 3);

    FiguraGeometrica *cercle;
    cercle = new Elipse(25, 25, 100, 55, 0, 1);

    Dibuix *e;
    e = new Dibuix(800, 200);

    e->addFigura(quadrat);
    e->addFigura(rectangle);
    e->addFigura(elipse);
    e->addFigura(cercle);


    e->toString();


    return 0;
}