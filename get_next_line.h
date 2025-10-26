# ifndef GET_NEXT_LINE
# define GET_NEXT_LINE

#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char *ft_strjoin_free(char *rem, char *chunk);
char	*ft_strdup(const char *s);
char *ft_read_chunk(int fd);
char *get_next_line(int fd);

#endif
