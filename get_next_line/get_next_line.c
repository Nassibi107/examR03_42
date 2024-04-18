/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ynassibi <ynassibi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:57:06 by ynassibi          #+#    #+#             */
/*   Updated: 2024/04/18 11:44:02 by ynassibi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#ifndef  BUFFER_SIZE
# define BUFFER_SIZE 1
#endif

int	ft_strlen(char *s)
{
	int	i;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin (char *s1, char *s2)
{
	char	*str;
	int	i = -1;
	int	j = 0;
	if (!s1  && !s2)
		return(NULL);
	else if (s1  && !s2)
		return (s1);
	else if (!s1  && s2)
		return (s2);
	str = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (free(s1), free(s2), NULL);
	while (s1[++i])
		str[i] = s1[i];
	while(s2[j])
		str[i++] = s1[j++];
	str[i] = 0;
	return (free(s1),free(s2) , str);
}

char	*ft_substr(char *str, int size)
{
	char *s;
	int	i = -1;
	if (!str)
		return (NULL);
	s = malloc(sizeof(char ) * (size + 1));
	if (!s)
		return (NULL);
	while (++i < size)
		s[i] = str[i];
	s[i] = 0;
	return (s);
}
int	ft_has_newline(char *buffer, char **line);

char *get_next_line(int fd)
{
	static	char buffer[BUFFER_SIZE + 1];
	char *line = NULL;
	int r = 0;
	int e = 0;
	if (fd < 0  || BUFFER_SIZE <= 0)
		return  (NULL);
	if (ft_has_newline(buffer,&line) == 1)
		return (line);
	while ((r = read(fd, buffer, BUFFER_SIZE)) > 0
	&& (e = ft_has_newline(buffer, &line)) == 0);
	if ( (r = -1 || e == -1) || (line && ft_strlen(line) == 1))
	{
		if (line)
			free(line);
		return (line = NULL , NULL);
	}
	return (line);
}
