/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: athonda <athonda@student.42singapore.sg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 20:36:13 by athonda           #+#    #+#             */
/*   Updated: 2024/09/17 13:41:39 by athonda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar_var(char **buffer, char c)
{
	**buffer = c;
	(*buffer)++;
}

void	ft_putstr_var(char **buffer, char *str)
{
	while (str)
		ft_putchar_var(buffer, *str++);
}

void	ft_putnbr_var(char **buffer, long long nb)
{
	char	tmp[20];
	int		i;

	if (nb < 0)
	{
		ft_putchar_var(buffer, '-');
		nb = -nb;
	}
	i = 0;
	if (nb == 0)
		tmp[i++] = '0';
	else
	{
		while (nb > 0)
		{
			tmp[i++] = (nb % 10) + '0';
			nb = nb / 10;
		}
	}
	while (i > 0)
		ft_putchar_var(buffer, tmp[--i]);
}

void	ft_dtoa(double nb, char *buffer, int precision)
{
	long long	int_part;
	double		fractional_part;
	long long	fractional_digit;

	if (nb < 0)
	{
		ft_putchar_var(&buffer, '-');
		nb = -nb;
	}
	int_part = (long long)nb;
	ft_putnbr_var(&buffer, int_part);
	fractional_part = nb - int_part;
	if (precision > 0)
	{
		ft_putchar_var(&buffer, '.');
		while (precision > 0)
		{
			fractional_part *= 10;
			fractional_digit = (long long)fractional_part;
			ft_putnbr_var(&buffer, fractional_digit);
			fractional_part -= fractional_digit;
			precision--;
		}
	}
	*buffer = '\0';
}