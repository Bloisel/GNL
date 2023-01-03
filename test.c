#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

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

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = c;
		i++;
	}
	return (b);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char *)s)[i] = '\0';
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*c;

	if (count == SIZE_MAX || size == SIZE_MAX)
		return (NULL);
	c = malloc(count * size);
	if (!c)
		return (NULL);
	ft_memset(c, 0, count * size);
	return (c);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = -1;
	while (c >= 256)
		c -= 256;
	while (s[++i])
		if (s[i] == c)
			return (&((char *)s)[i]);
	if (s[i] == c)
		return (&((char *)s)[i]);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*dup;

	if (!s1 || !s2)
		return (NULL);
	dup = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
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
	return (dup);
}

void ft_get_line(int fd,char *fichier)
{
	char *string;
	int i;

	i = -1;	
	//if (fd <= 0 || BUFFER_SIZE <= 0)
		//return ;

	//if (!fichier)
		//return ;	
	string = malloc(sizeof(char) * (ft_strlen(fichier) + 1));
	
	while (fichier[++i] != '\n') 
		string[i] = fichier[i];
	
	string[i] = '\0';
    printf("%s\n",string);
}

void get_one_line(int fd)
{
	char *str;
	static char *fichier;
	int i;
	int read_one;

	// fichier sera = a ma variable static 
	i = 0;
	read_one = 1;
	fichier = malloc(sizeof(char) * 10000);
	while ( read_one > 0 && !ft_strchr(fichier, '\n'))
	{
		//printf("%s\n", fichier);
		str=malloc(sizeof(char) * BUFFER_SIZE + 1);
		read_one = read(fd, str, BUFFER_SIZE);
		str[read_one] = '\0';
		fichier = ft_strjoin(fichier, str);
		free(str);
		if (read_one == -1)
			printf ("Error");
	}
	ft_get_line(fd, fichier);
	printf("%s\n",fichier);
}

int main(void)
{
	int fd;
	
	fd = open("abcd.txt", O_RDONLY);
	
	if (fd == -1)
			printf("error\n");

	get_one_line(fd);
	//get_line(fd);

	close (fd);
	return (0);
}
