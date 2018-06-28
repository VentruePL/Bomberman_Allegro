#include "kolizja_mapa.h"

kolizja_mapa::kolizja_mapa()
{
    //ctor
}

kolizja_mapa::~kolizja_mapa()
{
    //dtor
}
void kolizja_mapa::update()
{

}
void kolizja_mapa::kolizja(player & p,mapa & m)
{
for (int i = (p.p_y)/64 ; i<((p.p_y)+114)/64; i++)//gora dol
        {
            for (int j = (p.p_x)/64; j<((p.p_x+114))/64; j++)//prawo lewo
            {
                if(m.m[i][j]=='X')
                {
                    if(p.p_x<(j*64)+65)//lewy bok nie wiem jakim cudem
                    {
                        p.gracz_t.x+=p.speed;
                    }
                }
                if(m.m[i][j+1]=='X')
                {
                    if(p.p_x>(j*64)+1)
                    {
                        p.gracz_t.x-=p.speed;
                    }

                }
                if(m.m[i][j]=='X')
                {
                    if(p.p_y<(i*64)+65)
                    {
                        p.gracz_t.y+=p.speed;
                    }
                }
                if(m.m[i+1][j]=='X')
                {
                    if(p.p_y>(i*64)+1)
                    {
                        p.gracz_t.y-=p.speed;
                    }
                }
                if(m.m[i][j]=='S')
                {
                    p.zasieg_bomb=126;
                    m.m[i][j]='V';
                }
                if(m.m[i][j]=='I')
                {
                    p.bomby++;
                    m.m[i][j]='V';
                }
                if(m.m[i][j]=='L')
                {
                    p.zycie++;
                    m.m[i][j]='V';
                }
                if(m.m[i][j]=='P')
                {
                    p.speed++;
                    m.m[i][j]='V';
                }

            }
        }

}
void kolizja_mapa::przeciwnicy(wrog &w,mapa & m)
{
        w.update();
        for (int i = (w.p_y)/64 ; i<((w.p_y)+64)/64; i++)//gora dol
        {
            for (int j = (w.p_x)/64; j<((w.p_x+64))/64; j++)//prawo lewo
            {

                if(m.m[i][j]=='X'||m.m[i][j]=='B')
                {
                    if(w.p_x<(j*64)+64)//lewy bok nie wiem jakim cudem
                    {

                        w.wrog_t.x++;
                        w.losuj(0);

                    }
                }
                if(m.m[i][j+1]=='X'||m.m[i][j+1]=='B')
                {
                    if(w.p_x>(j*64))
                    {

                        w.wrog_t.x--;
                        w.losuj(1);
                    }

                }
                if(m.m[i][j]=='X'||m.m[i][j]=='B')
                {
                    if(w.p_y<(i*64)+64)
                    {

                        w.wrog_t.y++;
                        w.losuj(2);
                    }
                }
                if(m.m[i+1][j]=='X'||m.m[i+1][j]=='B')
                {
                    if(w.p_y>(i*64))
                    {

                        w.wrog_t.y--;
                        w.losuj(3);
                    }

                }

            }
        }

}
