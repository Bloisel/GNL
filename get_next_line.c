/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bloisel <bloisel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 10:03:39 by bloisel           #+#    #+#             */
/*   Updated: 2023/01/07 10:41:01 by bloisel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*next_line(char *sligne)
{
	int		i;
	char	*ret;

	if (sligne[ft_strlen_n(sligne)] != '\0')
	{
		i = ft_strlen_n(sligne) + 1;
		ret = NULL;
		ret = ft_strjoin(ret, &sligne[i]);
		free(sligne);
		return (ret);
	}
	free(sligne);
	return (NULL);
}

char	*get_one_line(char *sligne)
{
	char	*string;
	int		i;

	i = -1;
	if (!sligne[0])
		return (NULL);
	string = malloc(sizeof(char) * (ft_strlen_n(sligne) + 2));
	while (sligne[++i] != '\n' && sligne[i])
		string[i] = sligne[i];
	if (sligne[i] == '\n')
	{
		string[i] = '\n';
		i++;
	}
	string[i] = '\0';
	return (string);
}

char	*read_line(int fd, char *sligne)
{
	char	*str;
	int		read_one;

	read_one = 1;
	str = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (read_one != 0 && !ft_strchr(sligne, '\n'))
	{
		read_one = read(fd, str, BUFFER_SIZE);
		if (read_one == -1)
			return (free(str), NULL);
		str[read_one] = '\0';
		sligne = ft_strjoin(sligne, str);
	}
	free(str);
	return (sligne);
}

char	*get_next_line(int fd)
{
	static char	*sligne = NULL;
	char		*ret;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	sligne = read_line(fd, sligne);
	if (!sligne)
		return (NULL);
	ret = get_one_line(sligne);
	sligne = next_line(sligne);
	return (ret);
}
