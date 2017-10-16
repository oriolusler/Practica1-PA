#include <iostream>
#include "./include/Elipse.h"
#include "./include/Rectangle.h"
#include "./include/Dibuix.h"

using namespace std;

int main() {


    FiguraGeometrica *s;
    s = new Rectangle(1, 1, 8, 6, 2, 3);

    FiguraGeometrica *h;
    h = new Elipse(1, 2, 3, 2, 3, 3);

    Dibuix *e;
    e = new Dibuix(9, 9, s);
    e->addFigura(h);



    e->toString();


    e->remFigura(2);

    e -> toString();





    return 0;
}