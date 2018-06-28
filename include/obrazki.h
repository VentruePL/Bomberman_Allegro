#ifndef OBRAZKI_H
#define OBRAZKI_H
#include <allegro.h>
#include <iostream>
//#include <mapa.h>
class obrazki
{
    public:
        obrazki();
        void iniciacja(char * sciezka);
        void iniciacja_gracza(char * sciezka);
        void pozycja(int x_,int y_);
        void wyswietl(BITMAP * buff);
        void animacja_gracza(BITMAP * buff,int frame,int kierunek);
        int x;
        int y;
        void kill();
        void zmniejszenie(char *sciezka,int rozmiar);
        BITMAP *bmp;
        BITMAP *tro;
        int czass;
        bool juz=false;;
        ~obrazki();

    protected:

    private:
        int x_przesuniecie;

        BITMAP *anim;
        int wysokosc;
        int szerokosc;
};

#endif // OBRAZKI_H
