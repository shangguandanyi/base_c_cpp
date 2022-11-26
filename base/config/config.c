#include "config.h"
#include <string.h>

int getValidLines(const char *path)
{
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        return -1;
    }
    int line = 0;
    char buff[1024] = {0};
    while (!feof(file))
    {
        fgets(buff, 1024, file);
        if (isValidLine(buff))
        {
            line++;
        }
        memset(buff, 0, 1024);
    }
    
    fclose(file);
    return line;
}

int isValidLine(const char *line_str)
{
    if (line_str[0] == ' ' || line_str[0] == '\n' || strchr(line_str, '=') == NULL)
    {
        return False;
    }
    return True;
}

void parseFile(const char *path, int line, struct Config_Info **Config_Info)
{
    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        return;
    }
    struct Config_Info *config_Info = malloc(sizeof(struct Config_Info) * line);
    *Config_Info = config_Info;
    char buff[1024] = {0};
    int index = 0;
    while (!feof(file))
    {
        fgets(buff, 1024, file);
        if (isValidLine(buff))
        {
            memset(config_Info[index].key, 0, 64);
            memset(config_Info[index].value, 0, 64);

            char *pos = strchr(buff, '=');

            strncpy(config_Info[index].key, buff, pos - buff);
            strncpy(config_Info[index].value, pos + 1, strlen(pos + 1) - 1);
            index++;
        }
    }
    memset(buff, 0, 1024);
    fclose(file);
}

const char *getValue(struct Config_Info *Config_Info, int line, const char *key)
{
    for (size_t i = 0; i < line; i++)
    {
        if (strcmp(key, Config_Info[i].key) == 0)
        {
            return Config_Info[i].value;
        }
        
    }
    return NULL;
}

void freeConfig(struct Config_Info **Config_Info)
{
    if (*Config_Info != NULL)
    {
        free(*Config_Info);
        *Config_Info = NULL;
    }
    
}