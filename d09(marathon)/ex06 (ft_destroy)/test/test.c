/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/05/12 10:51:23 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*	команда для компиляции и одновременного запуска                           */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out	   	      */
/* ************************************************************************** */


#include <unistd.h>
#include <stdlib.h>
#include "ft_ultimator.h"


void	ft_putstr(char *str)						/* функция печати строки */
{
	while(*str)
		write(1, str++, 1);
}


void 	ft_destroy(char ***factory)					/* функция освобождает выделенную нами память пробегаясь по всем
													 * указателям в которых мы сохранили адреса выделеной памяти */
{
	int i;
	int j;

	i = 0;
	while (factory[i] != ((void *)0))				/* Проходимся по всем ячейкам массива "указателей на указатели", до тех пор пока они не закончатся */
	{
		j = 0;
		while (factory[i][j] != ((void *)0))		/* Проходимся по всем ячейкам массива указателей, в каждой из которых храниться адрес массива символов, до тех пор пока они не закончатся */
		{
			free(factory[i][j]);					/* Освобождаем память выделеную под массив символов, используя адрес который хранится в текущей ячейке массива указателей */
			j++;
		}
		free(factory[i]);							/* Освобождаем память по адресу который хранится в этом указателе */
		i++;
	}
	free(factory);
}


int		main()										/* Основная функция */
{	
	char	***ptr;									/* Обьявим указатель на указатель на указатель, в который сохраним адресс выделенной нами памяти */
	int 	i;										/* Обьявим счетчик для перемещения по указателям на указатели */
	int 	j;										/* Обьявим счетчик для перемещения по указателям в которые запишем адреса памяти выделенной под строки */

	if ((ptr = (char ***)malloc(sizeof(char *) * 2)) == ((void *)0))	/* Выделяем память и приводим ее к типу "указатели на указатели на указатели", там  
													 * будут храниться адреса указателей на указатели, сохраняем ее в ptr */
		return (0);									/* Если память выделить не удалось возвращаем ноль и завершаем функцию main */
	i = 0;
	while (i < 2)
	{	
		if ((ptr[i] = (char **)malloc(sizeof(char *) * 1)) == ((void *)0))/* Выделяем память и приводим ее к типу "указатели на указатели", там будут 
													 * храниться адреса указателей на адреса массивов с символами, сохраняем ее в **ptr */
			return (0);								/* Если память выделить не удалось возвращаем ноль и завершаем функцию main */
		j = 0;
		while (j < 1)
		{
			if ((ptr[i][j] = (char *)malloc(sizeof(char) * 6)) == ((void *)0))/* Выделяем память под шесть символов и сохраняем ее адресс в указателе ptr[i][j] */
				return (0);							/* Если память выделить не удалось возвращаем ноль и завершаем функцию main */
			ptr[i][j][0] = (char)'h';				/* Запишем в выделенную под символы память любые символы, например строку "hola" */
			ptr[i][j][1] = (char)'o';
			ptr[i][j][2] = (char)'l';
			ptr[i][j][3] = (char)'a';
			ptr[i][j][4] = (char)'\n';
			ptr[i][j][5] = (char)'\0';
			j++;
		}
		i++;
	}

													/* Проверим как прошло выделение памяти */
	ft_putstr(ptr[0][0]);							/* Возьмем из памяти символы и напечатаем их */
	ft_putstr(ptr[0][0]);							/* Возьмем из памяти символы и напечатаем их */

	ft_destroy(ptr);								/* Теперь можно проверить функцию ft_destroy, которая освобождает выделеную память нами */


	ft_putstr(ptr[0][0]);							/* Проверим, осталась ли память с симолами символы. Попробуем напечатать их */
	ft_putstr(ptr[1][0]);							/* Если память освободилась отлично то вместо слова "hola" в выводе появятся непонятные символы */
	return 0;
}