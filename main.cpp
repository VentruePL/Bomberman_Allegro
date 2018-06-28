#include <iostream>
#include <allegro.h>



//void(*wskaznik_is )();
//typedef void( * t_is )();
#define MODE GFX_AUTODETECT_WINDOWED
#define WIDTH 1280
#define HEIGHT 720

#include "include/engine.h"

using namespace std;

//int *wsk;
BITMAP* init()
{

    BITMAP *bufor;
    allegro_init();
    install_keyboard();


//    wsk=&speed;
    //t_is wskaznik_is=increment_speed;
    //alpng_init();
    set_color_depth(32);
    install_sound( DIGI_AUTODETECT, MIDI_AUTODETECT, "" );
    set_volume( 255, 255 );
    set_window_title("Bomberman");
    bufor= create_bitmap(WIDTH, HEIGHT);
    int ret = set_gfx_mode(MODE, WIDTH, HEIGHT, 0, 0);




    if(ret != 0){
        allegro_message("Could not set graphics mode");
        allegro_exit();
    }
    clear_to_color(screen, makecol(0,0,0));
return bufor;
}

int main(){

    //init();
    engine engine(init());
    //int klawisz = 0;

    //while( !key[ KEY_ESC ] )
    //{
     //   klawisz = readkey();

    //    textprintf( screen, font, 10, 10, makecol( 255, 255, 128 ), "Klawisz to : %d", klawisz );
    //}


    return 0;
}
END_OF_MAIN()
