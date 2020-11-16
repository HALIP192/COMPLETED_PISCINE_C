/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_foreach.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/11/16 17:04:38 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
**  Каталог сдачи задания: ex09/
**  Файлы для сдачи: ft_list_foreach.c, ft_list.h
**  Разрешенные функции: Никаких
**
** ************************************************************************** **
 *
 * 
 *	• Создайте функцию "ft_list_foreach", которая применяет функцию, заданную в
 *	качестве аргумента, к информации в каждой из ссылок списка.
 *
 * 
 *	• 'f' следует применять в том же порядке, что и в списке.
 *
 * 
 *	• Вот как эта функция должна быть объявлена :
 *
 *				void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
 * 
 * 
 *	• Функция, указанная "f", будет использоваться следующим образом:
 * 
 * 														(*f)(list_ptr->data);
 * 
 * 
 * ************************************************************************** */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	while (begin_list)
	{
		(*f)(begin_list->data);
		begin_list = begin_list->next;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data);
		list_ptr = list_ptr->next;
	}
}

/* ************************************************************************** */
/* ************************************************************************** */
