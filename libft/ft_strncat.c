/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amarandi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:39:42 by amarandi          #+#    #+#             */
/*   Updated: 2017/12/06 19:16:14 by amarandi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	l;

	l = ft_strlen(s1);
	i = 0;
	while (s2[i] && i < n)
	{
		s1[i + l] = s2[i];
		i++;
	}
	s1[i + l] = '\0';
	return (s1);
}