#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
    int fd = open("text.txt", O_RDONLY);
    if (fd == -1)
    {
        perror("open");
        return 1;
    }
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s", line);
        free(line);
    }
    close(fd);
    return 0;
}
