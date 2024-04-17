#include "so_long.h"
int main()
{
    int fd;
    char *line;

    fd = open("maps/map.ber", O_RDONLY);
    line = get_next_line(fd);
    while (line != NULL)
    {
        printf("%s", line);
        free(line);
        line = get_next_line(fd);
        
    }
}