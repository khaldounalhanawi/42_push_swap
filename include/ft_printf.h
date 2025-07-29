/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalhanaw <kalhanaw@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 13:13:02 by kalhanaw          #+#    #+#             */
/*   Updated: 2025/07/29 18:05:22 by kalhanaw         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

int		ft_printf(const char *input, ...);
int		print_c(va_list ap);
int		print_s(va_list ap);
int		print_p(va_list ap);
int		print_d(va_list ap);
int		print_u(va_list ap);
int		print_x(va_list ap);
int		print_xc(va_list ap);
int		print_percent(void);
char	*ft_strchr(const char *s, int c);
void	ft_putstr(char *s);

#endif
