#include "game.h"

int main()
{
    Game game;

    if(!game.init())
        return -1;

    game.loop();

    return 0;
}