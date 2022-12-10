#include "interface.h"
#include <time.h>

struct Player
{
    char name[64];
    int level;
    int exp;
};

void initHero(void **gameHandle, const char *name)
{
    struct Player *player = malloc(sizeof(struct Player));
    memcpy(player->name, name, strlen(name));
    player->level = 0;
    player->exp = 0;
    *gameHandle = player;
}

void heroGame(void *gameHandle)
{
    struct Player *player = gameHandle;
    srand(time(NULL));
    while (1)
    {
        int val = rand() % 101;
        switch (val)
        {
        case 1:
            if (val <= 90)
            {
                player->level++;
                player->exp += 10;
            } else 
            
            break;
        case 2:

            break;
        case 3:

            break;

        default:
            break;
        }
    }
}

void heroMsg(void *gameHandle)
{
    struct Player *player = gameHandle;
    printf("%s,%d,%d\n", player->name, player->level, player->exp);
}

void closeGame(void *gameHandle)
{
    struct Player *player = gameHandle;
    free(player);
    player = NULL;
}