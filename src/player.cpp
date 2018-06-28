#include "player.h"

player::player(BITMAP *buff)
{
    buf=buff;
    gracz_t.iniciacja_gracza("tekstury/hero.bmp");
    gracz_t.pozycja(64,64);
    //ctor
}
int player::sterowanie()
{

    if( key[ KEY_LEFT ] ){ gracz_t.x+=-speed;  kierunek =1;}

    else if( key[ KEY_RIGHT ] ){ gracz_t.x+=speed; kierunek = 2;}

    else if( key[ KEY_UP ] ) {gracz_t.y+=-speed; kierunek = 3;}

    else if( key[ KEY_DOWN ] ){ gracz_t.y+=speed; kierunek = 4;}
    else {kierunek=0;}
    p_x=gracz_t.x;
    p_y=gracz_t.y;
    return kierunek;
}
void player::draw(int frejm)
{

    frame=frejm;
    gracz_t.animacja_gracza(buf,frame,kierunek);
}

player::~player()
{
    //dtor
}


