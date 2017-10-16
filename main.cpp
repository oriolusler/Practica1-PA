#include <iostream>
#include "./include/Elipse.h"
#include "./include/FiguraGeometrica.h"
#include "./include/Rectangle.h"
#include "./include/Dibuix.h"

using namespace std;
int main() {
    Rectangle rect (1,1,8,4,2,3);
    rect.toString();


    FiguraGeometrica *s;
    s = new Rectangle(1,1,8,4,2,3);

    Dibuix *e;

    e = new Dibuix(9,9,s);
    e->toString();
    cout << "HELLLLLLLO";

    return 0;
}