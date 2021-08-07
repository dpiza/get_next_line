/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:26:46 by dpiza             #+#    #+#             */
/*   Updated: 2021/08/06 13:48:09 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_line_break(char *save)
{
	int			i;
	char		*ret;

	i = 0;
	ret = ft_strdup(save);
	while (ret[i] != '\n')
		i++;
	ret[i + 1] = '\0';
	return (ret);
}

char	*ft_return_line(char **save)
{
	char		*ret;
	char		*temp;

	if (!*save || **save == '\0')
		return (NULL);
	temp = ft_strchr(*save, '\n');
	if (temp)
	{
		ret = ft_line_break(*save);
		free (*save);
		*save = ft_strdup(temp);
		if (**save == '\0')
		{
			free (*save);
			*save = NULL;
		}
	}
	else
	{
		ret = ft_strdup(*save);
		free (*save);
		*save = NULL;
	}
	return (ret);
}

char	*get_next_line(int fd)
{
	char		*temp;
	char		*buffer;
	static char	*save[OPEN_MAX];
	int			ret;

	if (fd < 0 || BUFFER_SIZE < 1 || fd > OPEN_MAX)
		return (NULL);
	buffer = (char *)malloc((1 + BUFFER_SIZE) * sizeof(char));
	if (!buffer)
		return (NULL);
	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = '\0';
		if (save[fd] == NULL)
			save[fd] = ft_strdup("");
		temp = ft_strjoin(save[fd], buffer);
		free (save[fd]);
		save[fd] = temp;
		if (ft_strchr(save[fd], '\n'))
			break ;
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	free (buffer);
	return (ft_return_line(&save[fd]));
}
