/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_pieces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apelissi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 12:54:35 by apelissi          #+#    #+#             */
/*   Updated: 2017/12/15 09:59:17 by amarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		liaison(char *str, int i)
{
	int			k;

	k = 0;
	if (str[i] == '#' && str[i + 1] == '#')
		k++;
	if (str[i] == '#' && str[i - 1] == '#')
		k++;
	if (str[i] == '#' && str[i + 5] == '#')
		k++;
	if (str[i] == '#' && str[i - 5] == '#')
		k++;
	return (k);
}

static int		test(char *str)
{
	int i;
	int j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (i < 20)
	{
		if (i % 5 != 4 && str[i] != '.' && str[i] != '#')
			return (0);
		if (i % 5 == 4 && str[i] != '\n')
			return (0);
		if (str[i] == '#' && str[i + 1] != '#' && str[i - 1] != '#' &&
				str[i + 5] != '#' && str[i - 5] != '#')
			return (0);
		if (str[i] == '#')
			j++;
		k += liaison(str, i);
		i++;
	}
	if (j != 4 || (str[20] != '\n' && str[20] != '\0') || (k != 6 && k != 8))
		return (0);
	return (1);
}

char			**recup(char *str)
{
	char	**tab;
	int		i;
	int		j;
	int		fd;

	if (!(tab = (char **)malloc(27 * sizeof(char *))))
		return (NULL);
	i = 0;
	j = 21;
	fd = open(str, 0);
	while (i < 26 && (j == 21 || j == 20))
	{
		if (j == 20)
			return (tab);
		tab[i] = (char *)malloc(21 * sizeof(char));
		tab[i + 1] = (NULL);
		if (!(j = read(fd, tab[i], 21)))
			return (NULL);
		if (!(test(tab[i])))
			return (NULL);
		tab[i][20] = '\0';
		i++;
	}
	return (NULL);
}
