/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nonsign.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcynthia <tcynthia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 16:21:47 by tcynthia          #+#    #+#             */
/*   Updated: 2021/05/22 17:20:27 by tcynthia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nonsign(int nbr)
{
	if (nbr < 0)
		return (-nbr);
	else
		return (nbr);
}
