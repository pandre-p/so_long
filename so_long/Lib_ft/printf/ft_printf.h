/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:34:04 by ppassos           #+#    #+#             */
/*   Updated: 2024/11/07 14:07:10 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <strings.h>
# include <string.h>

int		ft_printf(const char *format, ...);
int		ft_putcharb_fd(char c, int fd);
int		ft_putstrb_fd(char *s, int fd);
size_t	ft_strlenb(const char *s);
int		ft_putnbr_baseb(long nbr, char *base, int neg);
int		ft_ppercentage(unsigned long decimal);
#endif