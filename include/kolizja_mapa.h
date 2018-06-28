#ifndef KOLIZJA_MAPA_H
#define KOLIZJA_MAPA_H
#include <allegro.h>
#include <player.h>
#include <mapa.h>
#include <engine.h>
#include <math.h>
#include <vector>
#include <wrog.h>
class kolizja_mapa
{
    public:
        kolizja_mapa();
        ~kolizja_mapa();
        void kolizja(player & p,mapa & m);
        void przeciwnicy(wrog &w,mapa & m);
        void update();
    protected:

    private:

};

#endif // KOLIZJA_MAPA_H
