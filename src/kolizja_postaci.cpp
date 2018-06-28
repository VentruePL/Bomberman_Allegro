#include "kolizja_postaci.h"

kolizja_postaci::kolizja_postaci()
{
    //ctor
}

kolizja_postaci::~kolizja_postaci()
{
    //dtor
}
bool kolizja_postaci::kol_player_wrog(player &p,wrog &w)
{

    if((p.p_x+50>=w.p_x)&&(p.p_y+50>=w.p_y)&&(w.p_x+50>=p.p_x)&&(w.p_y+50>=p.p_y))
        {
            return true;
        }

return false;
}
bool kolizja_postaci::kol_bomba_wrog(player &p,wrog  &w, int x,int y)
{
    if((w.p_x+p.zasieg_bomb>=x)&&(w.p_y+p.zasieg_bomb>=y)&&(x+p.zasieg_bomb>=w.p_x)&&(y+p.zasieg_bomb>=w.p_y))
    {
        return true;
    }
return false;
}

bool kolizja_postaci::kol_bomba_gracz(player &p, int x, int y)
{
    if((p.p_x+p.zasieg_bomb>=x)&&(p.p_y+p.zasieg_bomb>=y)&&(x+p.zasieg_bomb>=p.p_x)&&(y+p.zasieg_bomb>=p.p_y))
    {
        return true;
    }
return false;
}

