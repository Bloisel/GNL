#include"get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}


size_t	ft_strlen_n(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	if (!s)
		return(NULL);
	while (c >= 256)
		c -= 256;
	while (s[++i])
		if (s[i] == c)
			return (&((char *)s)[i]);
	if (s[i] == c)
		return (&((char *)s)[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	i;
	size_t	j;
	char	*dup;

	if (s1 == NULL)
	{
		s1 = malloc(1);
		s1[0] = '\0';
	} 
	if (!s1 || !s2)
		return NULL;
	dup = malloc(sizeof(char )  * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dup)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		dup[i] = s1[i];
	i--;
	while (s2[++j])
		dup[++i] = s2[j];
	dup[i + 1] = '\0';
	free (s1);
	return (dup);
}
