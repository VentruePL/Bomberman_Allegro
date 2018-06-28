#ifndef ENGINE_H
#define ENGINE_H
#include <iostream>
#include <allegro.h>
#include <obrazki.h>
#include <player.h>
#include <bomba.h>
#include <vector>
#include <mapa.h>
#include <kolizja_mapa.h>
#include <wrog.h>
#include <kolizja_postaci.h>
//#include "alpng.h"
#define WIDTH 1280
#define HEIGHT 720
using namespace std;

class engine
{
    public:
        BITMAP *buforr;
        engine(BITMAP* bufor);
        FONT *font_big;
        FONT *font_small;
        BITMAP *logo;
        BITMAP *logo_bmp;
        BITMAP *sorry;
        SAMPLE * menu_s = NULL;
        SAMPLE * game_s = NULL;
        SAMPLE * bomb_s = NULL;
        ~engine();

    private:

        BITMAP *iskra_b;
        int frame;
        void iskra(BITMAP *iskra_b);
        void draw_logo();
        void draw_sorry();
        void menu(bool wygrane);
        void start();
        void koniec();
};

#endif // ENGINE_H
