char *ft_strjoin_free(char *rem, char *chunk)
{
    int len = ft_strlen(rem) + ft_strlen(chunk);
    char *str = malloc(len + 1);
    ft_strlcpy(str, rem);
    ft_strlcat(str, chunk);
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

char *get_next_line(int fd)
{
    static char *rem;

    if (rem == NULL)
        rem = ft_read_chunk(fd);
    else
        rem = ft_strjoin_free(rem, ft_read_chunk(fd));
    if (!rem)
        return NULL;
    char *found = ft_strchr(rem, '\n');
    if (found)
    {
        int len = found - rem + 1;
        char *line = malloc(len + 1);
        if (!line)
            return NULL;
        ft_strncpy(line, rem, len);
        line[len] = '\0';
        char *new_rem = ft_strdup(found + 1);
        free(rem);
        rem = new_rem;
        return line;
    }
    char *line = ft_strdup(rem);
    free(rem);
    rem = NULL;
    return line;
}
