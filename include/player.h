#ifndef PLAYER_H
#define PLAYER_H
#include <allegro.h>
#include <obrazki.h>
#include <iostream>
class player
{
    public:
        player(BITMAP *buff);
        BITMAP *buf;
        int p_x;
        int p_y;
        ~player();
        int sterowanie();
        void draw(int frejm);
        int zycie=3;
        //int maks_bomb=3;
        int bomby=2;
        int zasieg_bomb=75;
        obrazki gracz_t;
        int speed=1;
    protected:

    private:
        friend class bomba;
        int kierunek=0;
        int frame=0;
        int liczmy;

        friend class kolizja_mapa;
        friend class kolizja_postaci;

};

#endif // PLAYER_H
