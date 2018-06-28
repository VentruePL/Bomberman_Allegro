#include "mapa.h"

mapa::mapa()
{

}

mapa::~mapa()
{
    //dtor
}


void mapa::inciacja_tekstur()
{
    map_skrzynka.iniciacja("tekstury/boki.bmp");
    map_tlo.iniciacja("tekstury/tloza.bmp");
    map_black.iniciacja("tekstury/nic.bmp");
    map_size_bomb.iniciacja("tekstury/size_bomb.bmp");
    map_ilosc_bomb.iniciacja("tekstury/ilosc_bomb.bmp");
    map_life.iniciacja("tekstury/add_life.bmp");
    map_speed.iniciacja("tekstury/add_speed.bmp");
}
void mapa::wybierz_mape(int num)
{

    nr=num;
    odczyt_plik();
}
void mapa::odczyt_plik()
{
    int j=0,k=0;
    ifstream odczyt;
    char ja;
    string sciezka;
    stringstream ss;
    ss<<nr;

    sciezka="mapy/m"+ss.str()+".m";
    odczyt.open(sciezka.c_str());
    for(int i=1;i<241;i++)
    {
    odczyt>>ja;
    m[j][k]=ja;
    k++;

    if(i%20==0&&i>0)
        {
            j++;k=0;cout<<endl;
        }
    }
    odczyt.close();
}
void mapa::rysuj_mape(BITMAP *buff)
{
    int w, k;
    clear_to_color(buff, makecol(0,0,0));
    for(k = 0; k< max_k ; k++)
    {
        for(w =  0; w < max_w; w++)
            {
            if(m[w][k] == 'X')
            {
                map_skrzynka.pozycja(k*64,w*64);
                map_skrzynka.wyswietl(buff);
            }
            if(m[w][k] == 'V'||m[w][k] == 'B')
            {
                map_tlo.pozycja(k*64,w*64);
                map_tlo.wyswietl(buff);
            }
            if(m[w][k] == '0')
            {
                map_black.pozycja(k*64,w*64);
                map_black.wyswietl(buff);
            }
            if(m[w][k] == 'S')
            {
                map_size_bomb.pozycja(k*64,w*64);
                map_size_bomb.wyswietl(buff);
            }
            if(m[w][k] == 'I')
            {
                map_ilosc_bomb.pozycja(k*64,w*64);
                map_ilosc_bomb.wyswietl(buff);
            }
            if(m[w][k] == 'L')
            {
                map_life.pozycja(k*64,w*64);
                map_life.wyswietl(buff);
            }
            if(m[w][k] == 'P')
            {
                map_speed.pozycja(k*64,w*64);
                map_speed.wyswietl(buff);
            }
        }
    }

}
void mapa::kasuj()
{
    map_skrzynka.kill();
    map_tlo.kill();
    map_black.kill();
    map_size_bomb.kill();
    map_ilosc_bomb.kill();
    map_life.kill();
    map_speed.kill();
}
