#include "obrazki.h"

obrazki::obrazki()
{

}
void obrazki::iniciacja(char *sciezka)
{
    bmp = load_bitmap(sciezka, NULL);
    if(bmp == NULL){
        allegro_message("Cant load image");
        allegro_exit();
    }
    wysokosc = bmp->w;
    szerokosc = bmp->h;
}
void obrazki::iniciacja_gracza(char *sciezka)
{
    anim=create_bitmap( 64, 64 );
    bmp = load_bitmap(sciezka, NULL);
    if(bmp == NULL){
        allegro_message("Cant load image");
        allegro_exit();
    }
    wysokosc = bmp->w;
    szerokosc = bmp->h;
}
void obrazki::pozycja(int x_,int y_)
{
    x=x_;
    y=y_;
}
void obrazki::wyswietl(BITMAP * buff)
{
    draw_sprite(buff, bmp, x, y);
}
void obrazki::animacja_gracza(BITMAP * buff,int frame,int kierunek)
{
    switch (frame)
    {
    case 0:
        x_przesuniecie=0;
        break;
    case 5:
        x_przesuniecie=64;
        break;
    case 10:
        x_przesuniecie=128;
        break;
    case 15:
        x_przesuniecie=192;
        break;
    case 20:
        x_przesuniecie=256;
        break;
    case 25:
        x_przesuniecie=320;
        break;
    case 30:
        x_przesuniecie=384;
        break;
    case 35:
        x_przesuniecie=448;
        break;
    }
    if(kierunek==0||kierunek==4)
    {
        blit(bmp,anim,x_przesuniecie,0,0,0,64,64);
    }
    else if(kierunek==3)
    {
        blit(bmp,anim,x_przesuniecie,196,0,0,64,64);
    }
    else if(kierunek==1)
    {
        blit(bmp,anim,x_przesuniecie,128,0,0,64,64);
    }
    else if(kierunek==2)
    {
        blit(bmp,anim,x_przesuniecie,64,0,0,64,64);
    }

    draw_sprite(buff, anim, x, y);
}
void obrazki::zmniejszenie(char *sciezka,int rozmiar)
{
    tro=create_bitmap( rozmiar, rozmiar);
    bmp = load_bitmap(sciezka, NULL);
    if(bmp == NULL){
        allegro_message("Cant load image");
        allegro_exit();
    }

    stretch_blit(bmp,tro,0,0,bmp->w,bmp->h,0,0,rozmiar,rozmiar);
    clear_bitmap(bmp);
    bmp=create_bitmap(rozmiar,rozmiar);
    bmp=tro;
    wysokosc = bmp->w;
    szerokosc = bmp->h;
}
obrazki::~obrazki()
{

}
void obrazki::kill()
{
    delete this;
}
