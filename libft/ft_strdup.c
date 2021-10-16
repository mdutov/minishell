/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 17:43:15 by tcynthia          #+#    #+#             */
/*   Updated: 2021/06/27 16:57:00 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	lens;
	void	*dest;

	if (s == NULL)
		return (NULL);
	lens = ft_strlen(s) + 1;
	dest = malloc(lens);
	if (dest == NULL)
		return (NULL);
	return ((char *)ft_memcpy(dest, s, lens));
}
