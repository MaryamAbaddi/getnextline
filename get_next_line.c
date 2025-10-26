
#include "get_next_line.h"

char *ft_strjoin_free(char *rem, char *chunk)
{
    int len = ft_strlen(rem) + ft_strlen(chunk);
    char *str = malloc(len + 1);
    ft_strlcpy(str, rem,ft_strlen(rem));
    ft_strlcat(str, chunk,ft_strlen(chunck);
    str[len] = '\0';
    free(rem);
    return (str);
}

char *ft_read_chunk(int fd)
{
    char buffer[BUFFER_SIZE + 1];
    int bytestoread = read(fd, buffer, BUFFER_SIZE);
    if (bytestoread <= 0)
        return NULL;
    buffer[bytestoread] = '\0';
    return ft_strdup(buffer);
}
static char	*extract_line(char **rem)
{
	char	*found;
	char	*line;
	char	*new_rem;
	int		len;

	found = ft_strchr(*rem, '\n');
	if (!found)
		return (NULL);
	len = found - *rem + 1;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_strncpy(line, *rem, len);
	line[len] = '\0';
	new_rem = ft_strdup(found + 1);
	free(*rem);
	*rem = new_rem;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*rem;
	char		*chunk;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	chunk = ft_read_chunk(fd);
	if (!chunk && !rem)
		return (NULL);
	if (chunk)
		rem = rem ? ft_strjoin_free(rem, chunk) : chunk;
	line = extract_line(&rem);
	if (line)
		return (line);
	if (!rem)
		return (NULL);
	line = ft_strdup(rem);
	free(rem);
	rem = NULL;
	return (line);
}

