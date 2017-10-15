#include "../include/Dibuix.h"
#include "../include/FiguraGeometrica.h"
#include "../include/Rectangle.h"
#include "../include/Elipse.h"
#include <iostream>
using namespace std;

Dibuix::Dibuix(int w, int h)
{
    this->quantsN = 0;
    this->quantsS = 0;
    this->w = w;
    this->h = h;
}

Dibuix::Dibuix(int w, int h, FiguraGeometrica *fg){
    this->w = w;    // NO SE SI HA DE CRIDAR A L'ALTRE CONSTRUCTOR O NO
    this->h = h;
    addFigura(fg);
}

Dibuix::~Dibuix()
{
    //dtor
}

void Dibuix::toString(){
    cout << "Figures Ubicades al nord:" << endl;
    for(auto & f: nord) f -> toString();

    cout << "Figures Ubicades al sud:" << endl;
    for(auto & f: sud) f -> toString();

}

bool Dibuix::addFigura(FiguraGeometrica *fg){    // NI IDEA DE SI FUNCIONA
    if(fg->Getx() > this->w || fg->Gety() > h) throw "Error, Figura fora del dibuix";
    if(comprobarCentre(fg)) throw "Error, Centre de la figura ja ocupat";
    if(DeterminarPos(fg) == 0){ //SUD
        sud[quantsS] = fg;
        quantsS += 1;
        return true;
    } else if(DeterminarPos(fg) == 1){ //NORD
        nord[quantsN] = fg;
        quantsN += 1;
        return true;
    }
    return false;
}

bool Dibuix::comprobarCentre(FiguraGeometrica *fg){
    for(auto & f: nord) if(fg->Gety() == f->Gety() && fg->Getx() == f->Getx()) return true;
    for(auto & f: sud) if(fg->Gety() == f->Gety() && fg->Getx() == f->Getx()) return true;
    return false;
}

int Dibuix::DeterminarPos(FiguraGeometrica *f){
    if(f->Gety() > h/2) return 0; //SUD
    else return 1; //NORD
}

double Dibuix::getArea(){
    double area = 0;
    for(auto & f: nord) area += f->area();
    for(auto & f: sud) area += f->area();
    return area;
}

bool Dibuix::operator<(Dibuix *d){
    return getArea() < d->getArea();
}

bool Dibuix::operator>(Dibuix *d){
    return getArea() > d->getArea();
}

bool Dibuix::operator==(Dibuix *d){
    return getArea() == d->getArea();
}

bool Dibuix::buscarFigura(FiguraGeometrica *f, int i){
    if(i == 0){
        for(auto &fg : sud) if(fg == f) return true;
    } else {
        for(auto &fg : nord) if(fg == f) return true;
    }
    return false;
}

bool Dibuix::remFigura(FiguraGeometrica *f){        // FALTA MILLORAR IMPLEMENTACIÓ
    int pos = DeterminarPos(f);
    if(!buscarFigura(f, pos)) throw  "Error, Figura no trobada";
    if(pos == 0){ //SUD
        for (int i = 0; i < quantsS; i++){
            if (sud[i] == f){
                for ( ; i < quantsS - 1; i++) {
                    sud[i] = sud[i + 1];
                }
                sud[quantsS - 1] = 0;
                quantsS = quantsS - 1;

                return true;
            }
        }
    }
    else if (pos == 1){ // NORD
        for (int i = 0; i < quantsN; i++){
            if (nord[i] == f){
                for ( ; i < quantsN - 1; i++) {
                    nord[i] = nord[i + 1];
                }
                nord[quantsN - 1] = 0;
                quantsN = quantsN - 1;

                return true;
            }
        }
    }
    return false;
}

int Dibuix::remFigura(int i){
    int total = 0;
    for(auto & f: nord) {
        if(f->GetcolorF() == i) {
            remFigura(f);
            total += 1;
        }
    }
    for(auto & f: sud) {
        if(f->GetcolorF() == i) {
            remFigura(f);
            total +=1;
        }
    }
    return total;
}
