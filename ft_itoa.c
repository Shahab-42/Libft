/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smuhamma <smuhamma@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:52:06 by smuhamma          #+#    #+#             */
/*   Updated: 2022/12/10 17:07:06 by smuhamma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_len(long num)
{
	int	len;

	len = 0;
	if (num == 0)
		len = 1;
	else if (num < 0)
	{
		num = -num;
		len++;
	}
	while (num > 0)
	{
		num /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int nb)
{
	char	*res;
	long	num;
	int		i;

	num = nb;
	i = nb_len(num);
	res = (char *)malloc (sizeof(char) * (nb_len(num) + 1));
	if (!res)
		return (NULL);
	res[i--] = '\0';
	if (num == 0)
		res[0] = '0';
	if (num < 0)
	{
		res[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		res[i--] = 48 + (num % 10);
		num /= 10;
	}
	return (res);
}
