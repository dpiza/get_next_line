/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpiza <dpiza@student.42sp.org.br>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/06 14:17:58 by dpiza             #+#    #+#             */
/*   Updated: 2021/08/07 17:34:12 by dpiza            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
	// ft_putchars('\n');
}

int	main(void)
{
	char *buffer;
	int fd;
	// int n;

	// fd = open("files/bin", O_RDONLY);
	// fd = -2147483647;
	// fd = open("files/41_no_nl", O_RDONLY);
	// fd = open("files/41_with_nl", O_RDONLY);
	// fd = open("files/42_no_nl", O_RDONLY);
	// fd = open("files/42_with_nl", O_RDONLY);
	// fd = open("files/43_no_nl", O_RDONLY);
	// fd = open("files/43_with_nl", O_RDONLY);
	// fd = open("files/alternate_line_nl_no_nl", O_RDONLY);
	// fd = open("files/alternate_line_nl_with_nl", O_RDONLY);
	// fd = open("files/big_line_no_nl", O_RDONLY);
	// fd = open("files/big_line_with_nl", O_RDONLY);
	fd = open("files/multiple_nlx5", O_RDONLY);
	// fd = open("files/nl", O_RDONLY);
	// n = 1;
	while (true)
	{
		buffer = get_next_line(fd);
		if (buffer)
		{
			ft_putstr(buffer);
			free (buffer);
		}
		else
			break ;
		// n--;
	}
	ft_putchar('\n');
	close(fd);


	return (0);
}