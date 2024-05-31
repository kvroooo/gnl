/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 12:28:36 by smlamali          #+#    #+#             */
/*   Updated: 2023/01/10 15:32:55 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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
	static char		*stock[1024];
	char			*line;
	char			*buf;

	r = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > 1024)
		return (NULL);
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!ft_strchr(stock[fd], '\n') && r > 0)
	{
		r = read(fd, buf, BUFFER_SIZE);
		if (r == -1)
			return (free(buf), NULL);
		stock[fd] = ft_norm(r, buf, stock[fd]);
	}
	free(buf);
	if (!stock[fd])
		return (NULL);
	line = ft_line(stock[fd]);
	stock[fd] = ft_save(stock[fd]);
	return (line);
}

// int	main(void)
// {
// 	int		fd;
// 	int		r;
// 	char	*buf;

// 	r = 0;
// 	fd = open("file.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (0);
// 	printf("--------- MAIN ---------\n");
// 	while (r < 3)
// 	{
// 		buf = get_next_line(fd);
// 		printf("%s", buf);
// 		r++;
// 	}
// 	free(buf);
// 	printf("\n--------- END ---------\n");
// 	close(fd);
// }
