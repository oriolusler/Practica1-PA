#include "../include/Dibuix.h"
#include <iostream>

using namespace std;

Dibuix::Dibuix(int w, int h) throw(char*) {
    if (w < 0 || h < 0) throw "Error Amplada o Alçada del dibuix negatives";
    this->quantsN = 0;
    this->quantsS = 0;
    this->w = w;
    this->h = h;
    this->figures[0] = nullptr;
    this->figures[1] = nullptr;
    /*for (auto &i : this->nord) {
        i = nullptr;
    }
    for (auto &i : this->sud) {
        i = nullptr;
    }*/
}

Dibuix::Dibuix(int w, int h, FiguraGeometrica *fg) : Dibuix(w, h) {
    addFigura(fg);
}

Dibuix::~Dibuix() {
    //dtor
}


void Dibuix::toString() {
    cout << "Figures Ubicades al nord:\n-------------------------" << endl;

    if (figures[0] != nullptr) {
        cout << figures[0]->inf << "\n";
        node *aux = figures[0];
        while (aux->seg != nullptr) {
            cout << aux->seg->inf << "\n";
            aux = aux->seg;

        }
    }
    cout << "Figures Ubicades al sud:\n------------------------" << endl;


    if (figures[1] != nullptr) {
        cout << figures[1]->inf << "\n";
        node *aux = figures[1];
        while (aux->seg != nullptr) {
            cout << aux->seg->inf << "\n";
            aux = aux->seg;

        }
    }

}

void Dibuix::addFigura(FiguraGeometrica *fg) throw(char*) {
    if (fg->Getx() > this->w || fg->Gety() > h) throw "Error, Figura fora del dibuix";
    if (comprobarCentre(fg)) throw "Error, Centre de la figura ja ocupat";
    if (DeterminarPos(fg) == 0) { //SUD

        if (figures[0] == nullptr) {
            figures[0] = new node(fg, nullptr);
        } else {

            node *aux = figures[0];
            while (aux->seg != nullptr) {
                aux = aux->seg;
            }

            aux->seg = new node(fg, nullptr);


        }
    } else if (DeterminarPos(fg) == 1) {

        if (figures[1] == nullptr) {
            figures[1] = new node(fg, nullptr);
        } else {
            node *aux = figures[1];
            while (aux->seg != nullptr) {
                aux = aux->seg;
            }
            aux->seg = new node(fg, nullptr);
        }

    }
}

bool Dibuix::comprobarCentre(FiguraGeometrica *fg) {

    if (figures[0] == nullptr)return false;
    node *aux = figures[0];
    while (aux->seg != nullptr) {
        if (aux->seg->inf->Getx() == fg->Getx() && aux->seg->inf->Gety() == fg->Gety())return true;
        aux = aux->seg;
    }

    if (figures[1] == nullptr)return false;
    aux = figures[0];
    while (aux->seg != nullptr) {
        if (aux->seg->inf->Getx() == fg->Getx() && aux->seg->inf->Gety() == fg->Gety())return true;
        aux = aux->seg;
    }

    return false;
}


int Dibuix::DeterminarPos(FiguraGeometrica *f) {
    if (f->Gety() > h / 2) return 0; //SUD
    else return 1; //NORD
}

double Dibuix::getArea() {
    double area = 0;

    if (figures[0] != nullptr)area += figures[0]->inf->area();
    node *aux = figures[0];
    while (aux->seg != nullptr) {
        area += aux->seg->inf->area();
        aux = aux->seg;
    }

    if (figures[1] != nullptr)area += figures[1]->inf->area();
    aux = figures[1];
    while (aux->seg != nullptr) {
        area += aux->seg->inf->area();
        aux = aux->seg;
    }

}

bool Dibuix::operator<(Dibuix *d) {
    return getArea() < d->getArea();
}

bool Dibuix::operator>(Dibuix *d) {
    return getArea() > d->getArea();
}

bool Dibuix::operator==(Dibuix *d) {
    return getArea() == d->getArea();
}


bool Dibuix::buscarFigura(FiguraGeometrica *f, int i) {
    if (i == 0) {
        if (figures[0] == nullptr)return false;
        if (figures[0]->inf == f)return true;
        node *aux = figures[0];

        while (aux->seg != nullptr) {
            if (aux->seg->inf == f)return true;
            aux = aux->seg;
        }
    } else if (i == 1) {
        if (figures[1] == nullptr)return false;
        if (figures[1]->inf == f)return true;
        node *aux = figures[1];

        while (aux->seg != nullptr) {
            if (aux->seg->inf == f)return true;
            aux = aux->seg;
        }
    }
    return false;
}
/*
bool Dibuix::remFigura(FiguraGeometrica *f) throw(char*) {        // FALTA MILLORAR IMPLEMENTACIÓ (FUNCIONA)
    int pos = DeterminarPos(f);
    if (!buscarFigura(f, pos)) throw "Error, Figura no trobada";
    if (pos == 0) { //SUD
        for (int i = 0; i < quantsS; i++) {
            if (sud[i] == f) {
                for (; i < quantsS - 1; i++) {
                    sud[i] = sud[i + 1];
                }
                sud[quantsS - 1] = 0;
                quantsS = quantsS - 1;

                return true;
            }
        }
    } else if (pos == 1) { // NORD
        for (int i = 0; i < quantsN; i++) {
            if (nord[i] == f) {
                for (; i < quantsN - 1; i++) {
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

int Dibuix::remFigura(int i) { // FALTA MILLORAR IMPLEMENTACIO (FUNCIONA)
    int total = 0;
    for (auto &f: nord) {
        if (f != nullptr && f->GetcolorF() == i) {
            remFigura(f);
            total += 1;
        }
    }
    for (auto &f: sud) {
        if (f != nullptr && f->GetcolorF() == i) {
            remFigura(f);
            total += 1;
        }
    }
    return total;
}

*/
