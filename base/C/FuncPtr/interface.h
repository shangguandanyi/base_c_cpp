#include<stdio.h>
#include<stdlib.h>
#include<string.h>


void initHero(void **gameHandle, const char *name);
void heroGame(void *gameHandle);
void heroMsg(void *gameHandle);
void closeGame(void *gameHandle);