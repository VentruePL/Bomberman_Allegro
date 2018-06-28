#ifndef KOLIZJA_POSTACI_H
#define KOLIZJA_POSTACI_H
#include <allegro.h>
#include <vector>
#include <player.h>
#include <wrog.h>
#include <iostream>

class kolizja_postaci
{
    public:
        kolizja_postaci();
        ~kolizja_postaci();
        bool kol_player_wrog(player & p,wrog  &w);
        bool kol_bomba_wrog(player & p,wrog  &w, int x, int y);
        bool kol_bomba_gracz(player & p, int x, int y);
    protected:

    private:
        int czas;
};

#endif // KOLIZJA_POSTACI_H
