#include <iostream>
#include "./include/Elipse.h"
#include "./include/FiguraGeometrica.h"
#include "./include/Rectangle.h"
#include "./include/Dibuix.h"

using namespace std;

int main() {

    FiguraGeometrica *s;
    s = new Rectangle(1, 1, 8, 4, 2, 3);

    FiguraGeometrica *h;
    h = new Elipse(1, 2, 3, 2, 3, 3);

    Dibuix *e;
    e = new Dibuix(9, 9, s);
    e->addFigura(h);

    cout << "-----------\n";
    e->toString();
    cout << "-----------\n";

    e->remFigura(2);

    e -> toString();





    return 0;
}