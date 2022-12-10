#include "config.h"
#define FILE_PATH "./config.txt"

int main(int argc, char const *argv[])
{
    int line = getValidLines(FILE_PATH);
    printf("line: %d\n", line);

    struct Config_Info* Config_Info = NULL;
    parseFile(FILE_PATH,line, &Config_Info);

    for (size_t i = 0; i < line; i++)
    {
        printf("key = %s, value = %s\n", Config_Info[i].key, getValue(Config_Info, line, Config_Info[i].key));
    }

    freeConfig(&Config_Info);
    return 0;
}
