#include <stdlib.h>
#include <stdio.h>

#define True 1
#define False 0

struct Config_Info
{
    char key[64];
    char value[64];
};

int getValidLines(const char *path);

int isValidLine(const char *line_str);

void parseFile(const char *path, int line, struct Config_Info **Config_Info);

const char *getValue(struct Config_Info *Config_Info, int line, const char *key);

void freeConfig(struct Config_Info **Config_Info);
