#ifndef MAPA_H
#define MAPA_H
#define max_w 12
#define max_k 21
#include <allegro.h>
#include <iostream>
#include <obrazki.h>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

class mapa
{
    public:
        mapa();
        ~mapa();
        void inciacja_tekstur();
        void rysuj_mape(BITMAP *buff);
        void wybierz_mape(int num);
        void kasuj();
        char m[max_w][max_k];
    protected:

    private:
        int w=max_w;
        int k=max_k;
        int nr;
        friend class kolizja_mapa;
        obrazki map_tlo;
        obrazki map_skrzynka;
        obrazki map_black;
        obrazki map_size_bomb;
        obrazki map_ilosc_bomb;
        obrazki map_life;
        obrazki map_speed;
        void odczyt_plik();



};

#endif // MAPA_H
