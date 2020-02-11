/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/02/15 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/* - Скомпилируй файл тест. В нем можно увидеть как работает эта функция вживую */

/* ************************************************************************** */
/* ************************************************************************** */
/* **************************************************************************


 Reproduce the behavior of the function strncpy (man strncpy).
 Воспроизвести поведение функции strncpy (man strncpy).


 ******************************************************************************


Аргументы:

destination – указатель на строку в которую будут скопированы данные.
source – указатель на строку источник копируемых данных.
n – ограничение длинны копирования

Возвращаемое значение:

Функция возвращает указатель на строку, в которую скопированы данные.

Описание:

Функция strncpy копирует данные из строки, на которую указывает аргумент source,
в строку на который указывает аргумент destination, пока не встретится символ конца 
строки (нулевой символ) или количество скопированных символов не достигнет величины 
указанной в аргументе n. При этом символ конца строки не копируется.

Если в аргументе n указана величина большая, чем длинна строки, т.е. символ конца 
строки '\000' встретился раньше, чем было скопировано n символов, то в массив, на 
который указывает аргумент destination, дозаписывается столько нулевых символов, 
чтобы общая длина записанной строки достигла величины указанной в аргументе n.

Если строки перекрываются, результат копирования будет не определен.


   ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


char    *ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int    i;
	int             size;

	size = 0;
	i = 0;
	while (i < n && src[i])
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}



/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */


char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	i = 0;
	while ((src[i] != '\0') && (i < n))
	{
		dest[i] = src[i];
		i++;
	}
	while ((dest[i] != '\0') && (i < n))
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */
