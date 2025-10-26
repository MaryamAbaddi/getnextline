char	*ft_strdup(const char *s)
{
	char	*str1;
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	str1 = malloc(i + 1);
	if (!str1)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		str1[i] = s[i];
		i++;
	}
	str1[i] = '\0';
	return (str1);
}
size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;

	srclen = 0;
	i = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (size == 0)
		return (srclen);
	while (i < size - 1 && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	j;
	size_t	i;

	dstlen = 0;
	while (dst[dstlen] != '\0' && dstlen < size)
		dstlen++;
	srclen = 0;
	while (src[srclen] != '\0')
		srclen++;
	if (size <= dstlen)
		return (size + srclen);
	i = dstlen;
	j = 0;
	while (i + 1 < size && src[j] != '\0')
	{
		dst[i++] = src[j++];
	}
	dst[i] = '\0';
	return (srclen + dstlen);
}
char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		i++;
	}
	if (s[i] == (char)c)
		return ((char*)(s + i));
	return (NULL);
}
size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}