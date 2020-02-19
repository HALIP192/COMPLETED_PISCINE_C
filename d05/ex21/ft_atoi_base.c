/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** 


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || c == '\f' || c == '\r'
		|| c == ' ');
}

static int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i += 1;
	return (i);
}

static int	ft_find_char(char c, char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != c)
		i += 1;
	return (i);
}

int			ft_atoi_base(char *str, char *base)
{
	int		result;
	int		neg;
	int		base_len;

	result = 0;
	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	while (ft_isspace(*str))
		str++;
	neg = *str == '-';
	str += (*str == '+' || *str == '-') ? 1 : 0;
	while (ft_find_char(*str, base) < base_len)
		result = result * base_len - ft_find_char(*str++, base);
	return (neg ? result : -result);
}

/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


int		ft_ctoi(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	return (-1);
}

double	ft_pow(double x, double y)
{
	double	r;

	r = 1;
	while (y--)
		r *= x;
	return (r);
}

int		ft_atoi_base(char *s, int b)
{
	int		n;
	int		negative;
	int		i;
	int		exp;

	exp = 0;
	i = 0;
	negative = 1;
	n = 0;
	if (*s == '-')
	{
		i++;
		negative = -1;
	}
	while (s[i])
		i++;
	while (--i >= 0)
	{
		if (ft_ctoi(s[i]) != -1 && ft_ctoi(s[i]) < b)
			n += ft_ctoi(s[i]) * ft_pow(b, exp++);
	}
	return (n * negative);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */




static int	ft_isspace(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\v' || c == '\f' ||
			c == '\r')
		return (1);
	return (0);
}

static int	_isdigit(char c)
{
	if ((c >= '0' && c <= '9') ||
			(c >= 'A' && c <= 'F'))
		return (1);
	return (0);
}

static char	toupper(char c)
{
	if (c >= 'a' && c <= 'f')
		return (c - 32);
	return (c);
}

int			ft_atoi_base(char *str, int str_base)
{
	int		i;
	int		neg;
	int		ret;

	neg = 1;
	ret = 0;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i])
	{
		if (!_isdigit(toupper(str[i])))
			return (-1);
		ret *= str_base;
		ret += (str[i] <= '9') ? str[i] - '0' : toupper(str[i]) - 55;
		i++;
	}
	return (ret * neg);
}
