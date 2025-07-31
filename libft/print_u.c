/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_u.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42berlin.d      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 15:39:32 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/07/31 15:39:34 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	devider_cal(unsigned int m)
{
	long	devider;

	devider = 1;
	while (devider <= m / 10)
	{
		devider *= 10;
	}
	return (devider);
}

int	print_u(va_list ap)
{
	char			out;
	int				devider;
	unsigned int	m;
	int				count;

	count = 0;
	m = va_arg(ap, unsigned int);
	devider = devider_cal (m);
	while (devider > 0)
	{
		out = (m / devider) + '0';
		write(1, &out, 1);
		m %= devider;
		devider /= 10;
		count ++;
	}
	return (count);
}
