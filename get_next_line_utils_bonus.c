/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smlamali <smlamali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 13:21:02 by smlamali          #+#    #+#             */
/*   Updated: 2023/01/10 15:25:04 by smlamali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*nstr;

	i = 0;
	j = 0;
	nstr = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!nstr)
		return (0);
	while (s1 != NULL && s1[i])
	{
		nstr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		nstr[i] = s2[j];
		i++;
		j++;
	}
	nstr[i] = '\0';
	return (nstr);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char *)s + i);
	return (0);
}

char	*ft_line(char *stock)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	if (!stock[i])
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	tmp = malloc(sizeof(char) * (i + 1));
	if (!tmp)
		return (NULL);
	while (j < i)
	{
		tmp[j] = stock[j];
		j++;
	}
	if (stock[j] == '\n')
		tmp[j] = '\n';
	tmp[j++] = '\0';
	return (tmp);
}

static char	*ft_normsave(int i, int j, char *tmp, char *s)
{
	int	len;

	len = ft_strlen(s);
	while (i < len)
	{
		tmp[j] = s[i];
		j++;
		i++;
	}
	tmp[j] = '\0';
	return (tmp);
}

char	*ft_save(char *s)
{
	int		i;
	int		j;
	int		len;
	char	*tmp;

	i = 0;
	j = 0;
	len = ft_strlen(s);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	if ((len - i) == 0)
		return (free(s), NULL);
	tmp = malloc(sizeof(char) * (len - i) + 1);
	if (!tmp)
		return (0);
	tmp = ft_normsave(i, j, tmp, s);
	free(s);
	return (tmp);
}
