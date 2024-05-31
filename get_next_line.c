/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:15:48 by smlamali          #+#    #+#             */
/*   Updated: 2024/05/31 14:21:09 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

static char	*ft_norm(int r, char *buf, char *stock)
{
	char	*tmp;

	buf[r] = '\0';
	tmp = stock;
	stock = ft_strjoin(tmp, buf);
	free(tmp);
	return (stock);
}

char	*get_next_line(int fd)
{	
	int				r;
	static char		*stock;
	char			*line;
	char			*buf;

	r = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(stock, '\n') && r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (free(buf), NULL);
		stock = ft_norm(r, buf, stock);
	}
	free(buf);
	if (!stock)
		return (NULL);
	line = ft_line(stock);
	stock = ft_save(stock);
	return (line);
}

int	main(void)
{
	int		fd;
	int		r;
	char	*buf;

	r = 0;
	fd = open("text", O_RDONLY);
	if (fd == -1)
		return (0);
	printf("--------- MAIN ---------\n");
	while (r < 10)
	{
		buf = get_next_line(fd);
		printf("%s", buf);
		free(buf);
		r++;
	}
	printf("\n--------- FIN ---------\n");
	close(fd);
}
