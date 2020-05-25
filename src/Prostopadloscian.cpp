#include "../inc/Prostopadloscian.h"

void Prostopadloscian::Rysuj()
{
    this->aktualizujPolozenie();
    if(this->id>=0)
    {
        drawingApi->erase_shape(this->id);
    }

    this->id = drawingApi->draw_polyhedron(this->wierzcholki,this->kolor);
    drawingApi->redraw();
}



void Prostopadloscian::aktualizujPolozenie()
{
    this->wierzcholki[0][0]= (macierzObrotu*Wektor3D(-szerokosc/2,-dlugosc/2,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][1]= (macierzObrotu*Wektor3D(-szerokosc/2, dlugosc/2,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][2]= (macierzObrotu*Wektor3D( szerokosc/2, dlugosc/2,-wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[0][3]= (macierzObrotu*Wektor3D( szerokosc/2,-dlugosc/2,-wysokosc/2)+this->pozycjaSrodka);

    this->wierzcholki[1][0]= (macierzObrotu*Wektor3D(-szerokosc/2,-dlugosc/2,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][1]= (macierzObrotu*Wektor3D(-szerokosc/2, dlugosc/2,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][2]= (macierzObrotu*Wektor3D( szerokosc/2, dlugosc/2,wysokosc/2)+this->pozycjaSrodka);
    this->wierzcholki[1][3]= (macierzObrotu*Wektor3D( szerokosc/2,-dlugosc/2,wysokosc/2)+this->pozycjaSrodka);

    /*
    for(int i=0;i<2;i++)
    {
        for(int j=0;j<4;j++)
        {
            for(int k=0;k<3;k++)
                std::cout<<wierzcholki[i][j][k]<<" ";
            std::cout<<"\n";
        }
        std::cout<<"\n";
    }
    std::cout<<macierzObrotu;
    */

}


Prostopadloscian::Prostopadloscian()
{
    this->szerokosc=2;
    this->wysokosc=1;
    this->dlugosc=3;
}

Prostopadloscian::Prostopadloscian(double dlugoscX,double dlugoscY, double wysokosc)
{
    this->szerokosc = dlugoscX;
    this->dlugosc = dlugoscY;
    this->wysokosc = wysokosc;
}
