#include <iostream>
#include "./include/Elipse.h"
#include "./include/FiguraGeometrica.h"
#include "./include/Rectangle.h"
#include "./include/Dibuix.h"

using namespace std;
int main() {

    FiguraGeometrica *s;
    s = new Rectangle(1,1,8,4,2,3);

    Dibuix *e;
    e = new Dibuix(9,9,s);
    e->toString();

    cout << "-------------------------------------";
    try {
        e->remFigura(s);
    } catch (char*){
        cout << "errrrror";
    }


    e->toString();


    return 0;
}