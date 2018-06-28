#ifndef BOMBA_H
#define BOMBA_H
#include <allegro.h>
#include <player.h>
#include <mapa.h>
#include <vector>
#include <iostream>

class bomba
{
    public:
        bomba(BITMAP *buff,player & p,long volatile *czass,mapa &m);
        ~bomba();
    void draw();
    long volatile *czas;
    int licznik;
    bool wybuch=false;
    bool wybuchlo();
    void update(mapa &m);
    //void bomba_destroy();

    int x;
    int y;
    protected:

    private:
        int rozmiar=75;
        void kill();
        //obrazki bom;
        obrazki bomba_t;
        BITMAP *bufalo;
        BITMAP *buf;
};

#endif // BOMBA_H
