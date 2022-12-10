#include"interface.h"


typedef void(*INIT_HERO)(void **gameHandle, const char *name);
typedef void(*HERO_GAME)(void *gameHandle);
typedef void(*HERO_MSG)(void *gameHandle);
typedef void(*CLOSE_GAME)(void *gameHandle);

void playGame(INIT_HERO initHero, HERO_GAME heroGame, HERO_MSG heroMsg, CLOSE_GAME closeGame)
{
    void *gameHandle = NULL;
    initHero(&gameHandle, "Boll");
    heroGame(gameHandle);
    heroMsg(gameHandle);
    closeGame(gameHandle);
}

int main(int argc, char const *argv[])
{
    playGame(initHero, heroGame, heroMsg, closeGame);
    return 0;
}