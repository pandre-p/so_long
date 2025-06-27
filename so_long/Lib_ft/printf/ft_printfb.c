/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printfb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppassos <ppassos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 16:34:10 by ppassos           #+#    #+#             */
/*   Updated: 2024/11/07 14:40:31 by ppassos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	identifies(char id, va_list args)
{
	char	*base16;

	base16 = "0123456789abcdef";
	if (id == 'c')
		return (ft_putcharb_fd(va_arg(args, int), 1));
	else if (id == 's')
		return (ft_putstrb_fd(va_arg(args, char *), 1));
	else if (id == 'p')
		return (ft_ppercentage(va_arg(args, unsigned long)));
	else if (id == 'd')
		return (ft_putnbr_baseb(va_arg(args, int), "0123456789", 0));
	else if (id == 'i')
		return (ft_putnbr_baseb(va_arg(args, int), "0123456789", 0));
	else if (id == 'u')
		return (ft_putnbr_baseb(va_arg(args, unsigned int), "0123456789", 1));
	else if (id == 'x')
		return (ft_putnbr_baseb(va_arg(args, unsigned int), base16, 1));
	else if (id == 'X')
	{
		base16 = "0123456789ABCDEF";
		return (ft_putnbr_baseb(va_arg(args, unsigned int), base16, 1));
	}
	else if (id == '%')
		return (ft_putcharb_fd('%', 1));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	int		count;
	int		add;
	va_list	args;

	add = 0;
	count = 0;
	va_start(args, format);
	while (format[count] != '\0')
	{
		if (format[count] == '%')
		{
			add = add + identifies(format[count + 1], args);
			count += 2;
		}
		else
		{
			ft_putcharb_fd(format[count++], 1);
			add++;
		}
	}
	va_end(args);
	return (add);
}
/*int main ()
{
    int *e = 0;
    unsigned int d = 4;
    int a = 5587900;
    char b = 'C';
    char *c = "correto?";
    printf("afk%%\n");
    ft_printf("afk%%\n\n");
    printf("%c\n", b);
    ft_printf("%c\n\n", b);
    printf("%s\n", c);
    ft_printf("%s\n\n", c);
    printf("%p\n", e);
    ft_printf("%p\n\n", e);
    printf("um numero->%d\n", a);
    ft_printf("um numero->%d\n\n", a);
    printf("%i\n", a);
    ft_printf("%i\n\n", a);
    printf("%u\n", d);
    ft_printf("%u\n\n", d);
    printf("%x\n", a);
    ft_printf("%x\n\n", a);
    printf("%X\n", a);
    ft_printf("%X\n", a);
}
int	main()
{
	int INT_MAX = 2147483647;
	int INT_MIN = -2147483648;
	unsigned int UINT_MAX = 4294967295;

printf("  MY: %i\n", ft_printf("%c	", 'c'));
printf("  OR: %i\n\n",    printf("%c	", 'c'));
printf("  MY: %i\n", ft_printf(" p %p	", (void *)321321321321321));
printf("  OR: %i\n\n",    printf(" p %p	", (void *)321321321321321));
printf("  MY: %i\n", ft_printf(" p %p ", 0));
printf("  OR: %i\n\n",    printf(" p %p ", 0));
printf("  MY: %i\n", ft_printf("  d %d	", 31313131));
printf("  OR: %i\n\n",    printf("  d %d	", 31313131));
printf("  MY: %i\n", ft_printf("   s %s	", "string"));
printf("  OR: %i\n\n",    printf("   s %s	", "string"));
printf("  MY: %i\n", ft_printf("    i %i	", -1));
printf("  OR: %i\n\n",    printf("    i %i	", -1));
printf("  MY: %i\n", ft_printf("    i %i	", INT_MIN));
printf("  OR: %i\n\n",    printf("    i %i	", INT_MIN));
printf("  MY: %i\n", ft_printf("    i %i	", INT_MAX));
printf("  OR: %i\n\n",    printf("    i %i	", INT_MAX));
printf("  MY: %i\n", ft_printf("     u %u	", UINT_MAX));
printf("  OR: %i\n\n",    printf("     u %u	", UINT_MAX));
printf("  MY: %i\n", ft_printf("     u %u	", 543487));
printf("  OR: %i\n\n",    printf("     u %u	", 543487));
printf("  MY: %i\n", ft_printf("     u %u	", 0));
printf("  OR: %i\n\n",    printf("     u %u	", 0));
printf("  MY: %i\n", ft_printf("      X %X	", 31));
printf("  OR: %i\n\n",    printf("      X %X	", 31));
printf("  MY: %i\n", ft_printf("       x %x	", 31));
printf("  OR: %i\n\n",    printf("       x %x	", 31));
printf("  MY: %i\n", ft_printf("only text, only text!	"));
printf("  OR: %i\n\n",    printf("only text, only text!	"));
printf("MY %i\n", ft_printf("MX %c %p %d %s\n", 'c', (void *)32132, 313, "str"));
printf("OR %i\n\n", printf("MX %c %p %d %s\n", 'c', (void *)32132, 313, "str"));
printf("MY: %i\n", ft_printf("MIX 2%i %u %X %x %%\n", -313, 31313131, 31, 31));
printf("OR: %i\n\n", printf("MIX 2%i %u %X %x %%\n", -313, 31313131, 31, 31));
}*/
