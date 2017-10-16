#include <iostream>
#include "../include/Elipse.h"
#include "../include/FiguraGeometrica.h"
#include "../include/Rectangle.h"
#include <stdexcept>

using namespace std;

FiguraGeometrica::FiguraGeometrica(int x, int y, int colorC, int colorF)
{
    this->colorF = colorF;
    this->colorC = colorC;
    this->x = x;
    this->y = y;
    /*SetcolorC(colorCc);
    SetcolorF(colorFc);
    Setx(xc);
    Sety(yc);*/

    //cout << "Creant FiguraGeometrica "<< endl;

    if(x<0||y<0) throw invalid_argument( "S'ha produit un error en variables X i y | FiguraGeometrica.cpp | 11");
    if(colorC != blanc && colorC != vermell && colorC != negre && colorC != blau) throw invalid_argument("No te un colorC assiganat |FiguraGeometrica.cpp | 14");
    if(colorF != blanc && colorF != vermell && colorF != negre && colorF != blau) throw invalid_argument("No te un colorF assiganat |FiguraGeometrica.cpp | 15");

}

void FiguraGeometrica::toString(){
/*
UAmb contorn [VERMELL/BLAU/VERD/NEGRE/BLANC] i  farcit [VERMELL/BLAU/VERD/NEGRE/BLANC] Amb una �rea de [valorArea]
*/
cout << "Ubicacio x: " << x << " Ubicacio y: " << y << endl;
cout << "Amb contorn " << colorC <<" i  farcit " << colorF << endl;

}

bool FiguraGeometrica::operator < (FiguraGeometrica *f){
  return area() < f->area();
}

bool FiguraGeometrica::operator > (FiguraGeometrica *f){
  return area() > f->area();
}

bool FiguraGeometrica::operator == (FiguraGeometrica *f){
  return area() == f->area();
}

FiguraGeometrica::~FiguraGeometrica(){//dtor
}
