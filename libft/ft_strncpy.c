/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 21:54:36 by tcynthia          #+#    #+#             */
/*   Updated: 2021/07/15 19:19:07 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int	i;

	i = 0;
	if (src == NULL)
	{
		dst = NULL;
		return (NULL);
	}
	while (src[i] && len > 0)
	{
		dst[i] = src[i];
		i++;
		len--;
	}
	while (len-- > 0 && dst[i])
	{
		dst[i] = '\0';
		i++;
	}
	return (dst);
}
