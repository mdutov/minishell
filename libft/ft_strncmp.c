/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/16 16:28:04 by tcynthia          #+#    #+#             */
/*   Updated: 2021/07/15 19:20:26 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	const char	*d1;
	const char	*d2;

	d1 = s1;
	d2 = s2;
	i = n;
	if (d1 == NULL || d2 == NULL)
		return (-1);
	if (i == 0)
		return (0);
	while (i != 0)
	{
		if (*d1 != *d2++)
			return (*(unsigned char *)d1 - *(unsigned char *)--d2);
		if (*d1++ == 0)
			break ;
		--i;
	}
	return (0);
}

int	ft_strncmp_1(const char *s1, const char *s2, size_t n)
{
	size_t		i;
	const char	*d1;
	const char	*d2;

	d1 = s1;
	d2 = s2;
	i = n;
	if (d1 == NULL || d2 == NULL)
		return (-1);
	if (i == 0)
		return (0);
	while (i != 0)
	{
		if (*d1 != *d2 && (*d2 - *d1) != 32)
			return (*(unsigned char *)d1 - *(unsigned char *)d2);
		if (*d1 == 0)
			break ;
		--i;
		d2++;
		d1++;
	}
	return (0);
}
