#ifndef WROG_H
#define WROG_H
#include <allegro.h>
#include <iostream>
#include <obrazki.h>
#include <cstdlib>
class wrog
{
    public:
        wrog(BITMAP *buff,volatile long * ziarno);
        ~wrog();
    void draw();
    void update();
    bool zdechl();
    void kolizja_teren();
    int seed;
    int speed=1;
    int kierunek=0;
    int p_x;
    int p_y;
    bool umarl=false;
    void zdechlak(BITMAP *bufalo);
    protected:

    private:
        void losuj(int wylacz);


        BITMAP *buf;
        obrazki wrog_t;
        obrazki wrog_t_dead;
        void ruch();
        friend class kolizja_mapa;
        friend class kolizja_postaci;
};

#endif // WROG_H
