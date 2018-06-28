#include "wrog.h"

wrog::wrog(BITMAP *buff,volatile long * ziarno)
{

    seed=(int)ziarno;
    buf=buff;
    wrog_t.iniciacja("tekstury/wrog.bmp");
    wrog_t_dead.iniciacja("tekstury/obama.bmp");

    srand(seed=time(NULL));

    int poz_start=rand()%2;
    switch(poz_start)
    {
        case 0:
        wrog_t.pozycja(1152,64);
        break;

        case 1:
        wrog_t.pozycja(1152,512);
        break;

    }
    srand(seed);
    ruch();
}

wrog::~wrog()
{

    //dtor
}
void wrog::draw()
{


    //std::cout<<kierunek<<std::endl;
    wrog_t.wyswietl(buf);
}
bool wrog::zdechl()
{
    return umarl;
}
void wrog::losuj(int wylacz)
{
    switch(wylacz)
    {
    case 0:
        kierunek=rand()%3+1;
        //std::cout<<"lewo"<<std::endl;
        break;
    case 1:
        kierunek=rand()%1+rand()%3;
        //std::cout<<"prawo"<<std::endl;
        break;
    case 2:
        //std::cout<<"dol"<<std::endl;
        break;
    case 3:
        //std::cout<<"gora"<<std::endl;
        kierunek=rand()%1+rand()%3;
        break;
    }
    kierunek=rand()%4;
}
void wrog::ruch()
{

    switch(kierunek)
    {
    case 0:
        wrog_t.x+=-speed;
        break;
    case 1:
        wrog_t.x+=+speed;
        break;
    case 2:
        wrog_t.y+=+speed;
        break;
    case 3:
        wrog_t.y+=-speed;
        break;
    }


}
void wrog::kolizja_teren()
{

}
void wrog::update()
{
    ruch();
    //wrog_t.x=p_x;
    //wrog_t.y=p_y;
    p_x=wrog_t.x;
    p_y=wrog_t.y;
}
void wrog::zdechlak(BITMAP *buf)
{
    wrog_t_dead.pozycja(p_x,p_y);
    wrog_t_dead.wyswietl(buf);
}
