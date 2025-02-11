/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdeliot <tdeliot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:59:32 by tdeliot           #+#    #+#             */
/*   Updated: 2025/01/30 10:52:36 by tdeliot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

static int	ft_isspace(int c)
{
	if (c == 9 || c == 10 || c == 11 || c == 12 || c == 13 || c == 32)
		return (1);
	return (0);
}

double	ft_atod(char *str)
{
	double	result;
	double	temp;
	char	*ptr;
	int		pow; 
	int		i;

	i = 0; 
	pow = 1;
	result = (double)ft_atoi(str);
	if (ft_strchr(str, '.'))
	{
		ptr = ft_strchr(str, '.') + 1;
		temp = ft_atoi(ptr);
		while (i < ft_strlen(ptr))
		{
			pow = pow * 10;
			i++;
		}
		temp /= pow;
		result += temp;
	}
	i = 1;
	if (str[0] == '-')
		i = -1;
	return (result * i);
}

static int	has_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_strchr("0123456789", str[i]))
			return (1);
		i++;
	}
	return (0);
}

//control if the input is corect. (sign allow, one . allow, digit required)
int	valid_input(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	if (!has_digit(str))
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
		{
			if (str[i] != '.')
				return (0);
			else
				flag++;
			if (flag > 1)
				return (0);
		}
		i++;
	}
	return (1);
}
