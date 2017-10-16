#include <iostream>
#include "./include/Elipse.h"
#include "./include/FiguraGeometrica.h"
#include "./include/Rectangle.h"
#include "./include/Dibuix.h"

using namespace std;
int main() {

    FiguraGeometrica *s;
    s = new Rectangle(1,1,8,5,2,3);

    FiguraGeometrica *o;
    o = new Rectangle(1,1,5,4,2,3);

    Dibuix *e;
    e = new Dibuix(9,9,s);
    e->toString();

    cout << "----------- " << "\n";

    e->addFigura(o);
    e->toString();

    cout << "----------- " << "\n";

    e->remFigura(o);
    e->toString();




    return 0;
}