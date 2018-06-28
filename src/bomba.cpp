#include "bomba.h"

bomba::bomba(BITMAP *buff,player & p,long volatile *czass,mapa &m)
{
    rozmiar=p.zasieg_bomb;
    czas=czass;
    licznik=(int)*czas+3;
    buf=buff;
    bomba_t.iniciacja_gracza("tekstury/bomb.bmp");
    x=(p.p_x/64);
    y=(p.p_y/64);

    if(y>11){y--;}
    if(y<1){y++;}
    if(x>20){x--;}
    if(x<1){x++;}

    x*=64;
    y*=64;

    bomba_t.pozycja(x,y);
    //bom.zmniejszenie("tekstury/wybuch.bmp",rozmiar);
    m.m[y/64][x/64]='B';
    //bom.pozycja(x,y);

}
bool bomba::wybuchlo()
{
    return wybuch;
}
void bomba::draw()
{
    bomba_t.wyswietl(buf);
}
void bomba::kill()
{
    bomba_t.kill();
    //delete this;
}
void bomba::update(mapa &m)
{
    if((int)*czas==licznik)
    {
        m.m[y/64][x/64]='V';
        wybuch=true;
        kill();
    }

}

bomba::~bomba()
{
   // bomba_t.kill();
    //dtor
    //delete this;
}
