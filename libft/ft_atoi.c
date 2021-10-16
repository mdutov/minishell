/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:11:27 by tcynthia          #+#    #+#             */
/*   Updated: 2021/07/15 19:21:27 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi(const char	*str)
{
	unsigned long long int		res;
	int							i;
	int							minus;

	i = 0;
	minus = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			minus = -1;
	while (ft_isdigit(str[i]) == 1)
	{
		if (minus == -1 && res > 4294967295)
			return (0);
		if (res > 4294967295)
			return (-1);
		res = res * 10 + (str[i] - '0');
		i++;
	}
	return (res * minus);
}
