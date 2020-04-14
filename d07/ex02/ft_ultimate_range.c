 /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
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

• Создать функцию ft_ultimate_range, которая выделяет и присваивает массив целых 
  чисел. Этот массив int должен содержать все значения от мин до макс.

• Минимум включен - максимум исключен.

• Вот как это должно быть прототипировано:
	int ft_ultimate_range(int **range, int min, int max);

• Если значение min больше или равно значению max, диапазон будет указывать на NULL.

• Размер диапазона должен быть возвращен (или 0 при ошибке).

   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*tab;

	i = 0;
	if ((tab = (int *)malloc(sizeof(int) * (max - min))) == ((void *)0))
		return ((void *)0);
	while (min < max)
	{
		tab[i] = min;
		min++;
		i++;
	}
	*range = tab;
	return (i);
}


/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */

int		ft_ultimate_range(int **range, int min, int max)
{
	int **t;
	int m;

	if (min >= max)
		return (0);
	m = max - min - 1;
	if ((t = (int **)malloc(sizeof(int) * m)) == NULL)
		return (0);
	m++;
	while (m > min)
		t[m--] = m;
	range = t;
	return (m);
}


/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */


int		ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int *arr;

	if (min >= max)
	{
		range = NULL;
		return (0);
	}
	arr = (int*)malloc(sizeof(int) * (max - min));
	i = min;
	while (min < max)
	{
		arr[min - i] = min;
		min++;
	}
	*range = arr;
	return (max - i);
}


/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */

int		ft_ultimate_range(int **range, int min, int max)
{
	int	*ret;
	int i;

	i = 0;
	ret = (int*)malloc(sizeof(int) * (max - min));
	while (min < max)
	{
		ret[i] = min;
		min++;
		i++;
	}
	*range = ret;
	return (i);
}

/* ************************************************************************** */
/* ******************************_ИЛИ_*************************************** */
/* ************************************************************************** */


int		ft_ultimate_range(int **range, int min, int max)
{
	int i;

	i = 0;
	if (max > min)
	{
		*range = (int *)malloc(sizeof(int) * (max - min) + 1);
		if (*range[i])
		{
			while (min < max)
				*range[i++] = min++;
		}
		return (i);
	}
	return (0);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

