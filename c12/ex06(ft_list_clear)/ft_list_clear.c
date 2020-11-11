/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/11 14:37:58 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** **
**
**  Каталог сдачи задания: ex06/
**  Файлы для сдачи: ft_list_clear.c, ft_list.h
**  Разрешенные функции: free
**
** ************************************************************************** **
 *
 * 
 *	• Создайте функцию "ft_list_clear", которая удаляет и освобождает память у
 *  всех ссылок из списка. Затем он присвоит указателю списка значение null.
 *	
 *
 *	• "free_fct", чтобы освободить каждый элемент "data".
 *
 * 
 *	• Вот как эта функция должна быть объявлена :
 *
 *			void	ft_list_clear(t_list *begin_list,void(*free_fct)(void*));
 * 
 * 
 * ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

void	free_fct(void *data)
{
	free(data);
}

void	ft_list_clear(t_list **begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;
	t_list	*list;

	list = *begin_list;
	while (list)
	{
		tmp = list->next;
		if (list->data)
			free_fct(list->data);
		free(list);
		list = tmp;
	}
	*begin_list = ((void *)0);
}


/* ************************************************************************** */
/* ************************************************************************** */
/* ************************************************************************** */