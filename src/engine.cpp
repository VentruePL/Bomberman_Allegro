#include "engine.h"

volatile long speed = 0,fps=0,licznikfps=0,czas=0,ziarnoo=0;
void increment_speed()
{
    speed++;
}END_OF_FUNCTION( increment_speed );
void increment_fps()
{
    licznikfps=fps;
    fps=0;
}
END_OF_FUNCTION( increment_fps );
void increment_czas()
{
    czas++;
}
END_OF_FUNCTION( increment_fps );
void increment_ziarno()
{
    ziarnoo++;
}
END_OF_FUNCTION( increment_ziarno );

engine::engine(BITMAP *bufor)
{

    buforr=bufor;
    font_big = load_font("czcionki/f1.pcx", NULL, NULL);
    font_small = load_font("czcionki/f2.pcx", NULL, NULL);
    logo = create_bitmap(1280,720);
    logo_bmp = load_bitmap("tekstury/logo.bmp", NULL);
    sorry = load_bitmap("tekstury/sorry.bmp", NULL);
    iskra_b = load_bitmap("tekstury/iskra.bmp", NULL);
    menu(0);
    //ctor
}

engine::~engine()
{
    //dtor
}

void engine::draw_logo()
{
    draw_sprite(buforr, logo_bmp, 0, 0);

}
void engine::draw_sorry()
{
    draw_sprite(buforr, sorry, 0, 0);

}

void engine::iskra(BITMAP *iskra_b)
{
    draw_sprite(buforr,iskra_b,782,50);
    draw_sprite(buforr,iskra_b,750,50);
    draw_sprite(buforr,iskra_b,500,50);
}

void engine::menu(bool wygrane)
{
    install_mouse();
    BITMAP * kursor;
    kursor = load_bitmap( "tekstury/kursor.bmp", NULL );
    set_mouse_sprite( kursor );

    int pozycja=1;
    bool klik=false;
    menu_s = load_sample( "sounds/menu.wav" );
    int kolor = makecol(255, 192, 64);
    int kolor_z = makecol(255, 64, 48);

    play_sample( menu_s, 255, 127, 1000, 1 );

    unscare_mouse();
    while(!klik)
    {
    clear_bitmap(buforr);
    clear_to_color(buforr, makecol(0,0,0));
    //clear_bitmap(screen);

        if(!wygrane)
        {
            draw_logo();
        }
        else
        {
            draw_sorry();
        }
        show_mouse( buforr );
        //iskra(iskra_b);
        //textprintf_ex( buforr, font, 20, 20, makecol( 200, 200, 200 ), - 1, "Myszka x = %d, y = %d, klawisz = %d !", mouse_x, mouse_y, mouse_b);
        //textprintf_ex( buforr, font, 20, 40, makecol( 200, 200, 200 ), - 1, "Czas = %d", speed);

        if(pozycja == 1)
        {
            textprintf_centre_ex(buforr, font_big, WIDTH/2, HEIGHT/2+180, kolor_z, -1, "Zagraj");
            textprintf_centre_ex(buforr, font_big, WIDTH/2, HEIGHT/2+250, kolor, -1, "Koniec");
        }
        else if(pozycja ==  2)
        {
            textprintf_centre_ex(buforr, font_big, WIDTH/2, HEIGHT/2+180, kolor, -1, "Zagraj");
            textprintf_centre_ex(buforr, font_big, WIDTH/2, HEIGHT/2+250, kolor_z, -1, "Koniec");
        }

        blit( buforr, screen, 0, 0, 0, 0, 1280, 720 );

        if(key[KEY_UP]){
            pozycja = 1;
        }

        if(key[KEY_DOWN]){
            pozycja = 2;
        }

        if((key[KEY_ENTER] && pozycja == 1)||((mouse_x>=590&&mouse_x<=685)&&(mouse_y>=545&&mouse_y<=565)&&(mouse_b==1)))
        {
            klik = true;
            start();
        }
        else if((key[KEY_ENTER] && pozycja == 2)||((mouse_x>=590&&mouse_x<=685)&&(mouse_y>=615&&mouse_y<=640)&&(mouse_b==1)))
        {
            klik = true;
            koniec();

        }

    }

}

void engine::koniec()
{
    remove_mouse();
    remove_int( increment_speed );
    remove_int( increment_fps );
    remove_int( increment_czas );
    remove_int( increment_ziarno );
    destroy_bitmap(logo);
    //destroy_bitmap(kursor);
    //stop_sample( game_s );
    //stop_sample( bomb_s );
    destroy_sample( menu_s );
    destroy_sample( game_s );
    destroy_sample( bomb_s );
    destroy_font(font_big);
    destroy_font(font_small);

    remove_keyboard();
    allegro_exit();
}


void engine::start()
{
    remove_mouse();
    czas=0;
 //   destroy_bitmap(kursor);
    stop_sample( menu_s );
    LOCK_VARIABLE( licznikfps );
    LOCK_FUNCTION( increment_fps );
    LOCK_VARIABLE(fps);
    LOCK_VARIABLE( speed );
    LOCK_FUNCTION( increment_speed );
    LOCK_VARIABLE( czas );
    LOCK_FUNCTION( increment_czas );
    LOCK_VARIABLE( ziarnoo );
    LOCK_FUNCTION( increment_ziarno );
    install_timer();
    install_int_ex( increment_speed, BPS_TO_TIMER( 100 ) );
    install_int_ex( increment_fps, BPS_TO_TIMER( 1 ) );
    install_int_ex( increment_czas, BPS_TO_TIMER( 1 ) );
    install_int_ex( increment_ziarno, BPS_TO_TIMER( 1000 ) );
    game_s = load_sample( "sounds/game.wav" );
    bomb_s = load_sample( "sounds/bomb.wav" );
    allocate_voice(game_s);
    allocate_voice(bomb_s);
    voice_start(0);
    voice_set_playmode(0,PLAYMODE_LOOP);
    clear_bitmap(buforr);
    scare_mouse();
    clear_to_color(screen, makecol(0,0,0));
    clear_to_color(buforr, makecol(0,0,0));
    mapa mapp;
    mapp.inciacja_tekstur();
    player kapitan_bomba(buforr);
    vector<bomba>bomby;
    vector<wrog>wrogowie;
    vector<kolizja_mapa>k_w;
    vector<kolizja_postaci>kol_p_w;
    vector<kolizja_postaci>kol_b_w;
    kolizja_postaci kol_b_p;
    frame=0;
    bool klik=false;
    kolizja_mapa k_m;
    kolizja_mapa mapa_wrogowie;
    int level=1;
    mapp.wybierz_mape(level);
    bool done=false;
    int klick_tock=0;
    int kierunek=0;
    int czas_sprawdzajacy=0;
    bool ochrona=false;

    obrazki eksplozja;
    eksplozja.zmniejszenie("tekstury/wybuch.bmp",kapitan_bomba.zasieg_bomb);
    for (int z=0;z<7;z++)
    {
        wrogowie.push_back(wrog(buforr,&ziarnoo));
        k_w.push_back(kolizja_mapa());
        kol_p_w.push_back(kolizja_postaci());
        kol_b_w.push_back(kolizja_postaci());
    }
    while( !done&&!key[KEY_ESC] )
    {
            while(speed>0)
            {
                if(kapitan_bomba.zycie<0)done=true;
                int old_ticks = speed;
                kierunek=kapitan_bomba.sterowanie();
                if(key[KEY_SPACE]&&!klik&&kapitan_bomba.bomby>0)
                    {
                        bomby.push_back(bomba(buforr,kapitan_bomba,&czas,mapp));
                        klik=true;
                        klick_tock=(int)czas+1;
                        kapitan_bomba.bomby--;
                    }

                k_m.kolizja(kapitan_bomba,mapp);


                speed--;
                frame++;
                if( frame > 35 ) frame = 0;

                if(eksplozja.juz==true&&eksplozja.czass<=(int)czas)
                {
                    eksplozja.juz=false;
                }

                for(int u = 0; u < bomby.size(); u++)
                {
                    if(!bomby[u].wybuchlo())
                    {
                        bomby[u].update(mapp);
                    }
                    else
                    {
                        voice_start(1);
                        eksplozja.zmniejszenie("tekstury/wybuch.bmp",kapitan_bomba.zasieg_bomb);
                        kapitan_bomba.bomby++;
                        eksplozja.czass=(int)czas+1;
                        eksplozja.juz=true;
                        if(kapitan_bomba.zasieg_bomb==75)
                        {
                            eksplozja.pozycja(bomby[u].x-5,bomby[u].y-5);
                        }
                        else
                        {
                            eksplozja.pozycja(bomby[u].x-26,bomby[u].y-26);
                        }
                        if((kol_b_p.kol_bomba_gracz(kapitan_bomba,bomby[u].x,bomby[u].y))==true)
                        {
                            kapitan_bomba.zycie--;
                        }
                        if(!wrogowie.empty())
                        {
                            for(int x = 0; x < wrogowie.size(); x++)
                            {
                                if(!wrogowie[x].zdechl())
                                {
                                    wrogowie[x].umarl=kol_b_w[x].kol_bomba_wrog(kapitan_bomba,wrogowie[x], bomby[u].x,bomby[u].y);
                                }
                            }
                        }
                        bomby.erase(bomby.begin() + u);
                    }

                }
                if(!wrogowie.empty())
                {
                    for(int u = 0; u < wrogowie.size(); u++)
                    {
                        if(!wrogowie[u].zdechl())
                        {
                            k_w[u].przeciwnicy(wrogowie[u],mapp);
                            if((kol_p_w[u].kol_player_wrog(kapitan_bomba,wrogowie[u])==true)&&(!ochrona))
                            {
                                ochrona=true;
                                kapitan_bomba.zycie--;
                                kapitan_bomba.gracz_t.x=65;
                                kapitan_bomba.gracz_t.y=65;
                                czas_sprawdzajacy=czas+5;
                            }
                        }
                        else
                        {
                            wrogowie.erase(wrogowie.begin() + u);
                        }

                    }
                }
                if(czas_sprawdzajacy<=czas&&ochrona)
                {
                    ochrona=false;
                    czas_sprawdzajacy=0;
                }
                if(klick_tock==czas)
                {
                    klik=false;
                }
                if(old_ticks <= speed) break;
                if(wrogowie.empty())
                {

                        done=true;
                        clear_bitmap(buforr);
                        clear_bitmap(screen);
                        voice_stop(0);
                        mapp.kasuj();
                        menu(0);
                }
            }
            fps++;

            mapp.rysuj_mape(buforr);
            textprintf_ex( buforr, font, 1200, 650, makecol( 200, 200, 200 ), - 1, "FPS = %d", licznikfps);

            for(int u = 0; u < bomby.size(); u++)
                {
                    if(!bomby[u].wybuchlo())
                    {
                        bomby[u].draw();

                    }
                }

            if(eksplozja.juz==true)
            {
                eksplozja.wyswietl(buforr);
            }

            for(int u = 0; u < wrogowie.size(); u++)
                {
                    if(!wrogowie[u].zdechl())
                    {
                        wrogowie[u].draw();
                    }

                }
            kapitan_bomba.draw(frame);
            textprintf_ex( buforr, font, 1200, 670, makecol( 200, 200, 200 ), - 1, "X = %d", kapitan_bomba.p_x);
            textprintf_ex( buforr, font, 1200, 690, makecol( 200, 200, 200 ), - 1, "Y = %d", kapitan_bomba.p_y);
            textprintf_ex( buforr, font, 1200, 710, makecol( 200, 200, 200 ), - 1, "Frame = %d", frame);
            textprintf_ex( buforr, font, 1050, 650, makecol( 200, 200, 200 ), - 1, "Ziarno = %d", ziarnoo);
            textprintf_ex( buforr, font, 1050, 670, makecol( 200, 200, 200 ), - 1, "Kierunek = %d", kierunek);
            textprintf_ex( buforr, font_small, 10, 645, makecol( 255, 192, 64 ), - 1, "Zycia = %d", kapitan_bomba.zycie);
            textprintf_ex( buforr, font_small, 10, 665, makecol( 255, 192, 64 ), - 1, "Bomby = %d", kapitan_bomba.bomby);
            textprintf_ex( buforr, font_small, 10, 685, makecol( 255, 192, 64 ), - 1, "Predkosc = %d",kapitan_bomba.speed);
            textprintf_ex( buforr, font_small, 250, 645, makecol( 255, 192, 64 ), - 1, "Rozmiar bomb = %d", kapitan_bomba.zasieg_bomb);
            textprintf_ex( buforr, font_small, 250, 665, makecol( 255, 192, 64 ), - 1, "Poziom = %d", level);
            textprintf_ex( buforr, font_small, 250, 685, makecol( 255, 192, 64 ), - 1, "Pozostaly czas = %d", 150-czas);
            textprintf_ex( buforr, font_small, 490, 645, makecol( 255, 192, 64 ), - 1, "Ochrona = %d", (czas-czas_sprawdzajacy)*(-1)<0?0:(czas-czas_sprawdzajacy)*(-1));
            blit( buforr, screen, 0, 0, 0, 0, 1280, 720 );

            if (czas>=150)
            {
                done=true;
            }
            if (ziarnoo>=10000)
            {
                ziarnoo=0;
            }

    }
    clear_bitmap(buforr);
    clear_bitmap(screen);
    voice_stop(0);
    mapp.kasuj();
    menu(1);
}
