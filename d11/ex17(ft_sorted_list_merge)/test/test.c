/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/12 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2020/09/28 19:31:51 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*         команда для компиляции и одновременного запуска                    */
/*                                                                            */
/*  gcc -Wall -Werror -Wextra test.c && chmod +x ./a.out && ./a.out           */
/* ************************************************************************** */

#include <unistd.h>						/* Подключаем библиотеку содержащую функцию "write" */
#include <stdlib.h>						/* Подкоючаем библиотеку содержащую функцию для выделения памяти(malloc) и функцию для
										** подсчета размера (sizeof) и функцию(free) для освобождения выделеной памяти */
#include "ft_list.h"					/* Подключаем заголовочный файл содержащий нужную нам структуру */


/* ************************************************************************** */

void		ft_putchar(char c)			/* Функция печати символа */
{
	write(1, &c, 1);
}

/* ************************************************************************** */

void		ft_putstr(char *str)		/* Функция печатает строку */
{
	int	i;

	i = 0;
	while (*(str + i))
		i++;
	write(1, str, i);
}

/* ************************************************************************** */

void		ft_put_list(t_list *list)	/* Функция печати связанных между собой экземпляров структуры типа 't_list' */
{
	while (list)
	{
		ft_putstr((char *)list->data);
		list = list->next;
	}
}

/* ************************************************************************** */

t_list		*ft_create_elem(void *data)	/* Функция создает экземпляр структуры типа t_list, заполняет его данными - адрес из указателя data
										** в первый элемент экземпляра структуры, нулевой адрес во второй элемент экземпляра структуры. И в 
										** конце функция его возвращает адрес созданого экземпляра структуры типа t_list*/
{
	t_list	*tmp;						/* Обьявляем указатель структуры типа t_list для хранения там адреса экземпляра структуры типа t_list */

	if ((tmp = (t_list *)malloc(sizeof(t_list))) == ((void *)0))/* Инициализируем указатель, сохраняя туда адрес выделеной под экземпляр памяти */
		return ((void *)0);										/* Если память не выделилась то завершаем функцию и возвращаем нулевой указатель */
	tmp->next = ((void *)0);			/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры нулевой указатель */
	tmp->data = data;					/* Заполняем Экземпляр структуры типа t_list записывая в этот элемент экземпляра структуры адрес принятого
										** в аргументах элемента неизвестного типа */
	return (tmp);						/* Завершаем функцию и возвращаем адрес созданного нами экземпляра структуры типа t_list */
}

/* ************************************************************************** */

int			ft_strcmp(char *s1, char *s2)	/* Функция сравнивает две строки и возвращает разницу между ними */
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/* ************************************************************************** */

void		ft_list_sort(t_list **begin_list, int (*cmp)())	/* Функция сортирует цепь связанных между собой экземпляров структур в порядке возростания */
{
	t_list	*last;						/* Обьявим указатель для хранения адреса экземпляра структуры, с которым цикл работал в прошлой итерации */
	t_list	*current;					/* Обьявим указатель для хранения адреса экземпляра структуры, с которым цикл работает в данный момент */
	t_list	*tmp;						/* Обьявим указатель для временнного хранения адреса экземпляра структуры */

	last = ((void *)0);					/* Иициализируем указатель нулевым адресом, который должен будет хранить адрес экземпляра структуры с
										** прошлой итерации */
	current = *begin_list;				/* Иициализируем указатель, который должен хранить адрес экземпляра в прошлой итерации цикла,
										** адресом первого экземпляра структуры цепи связанных между собой структур */
	while (current->next)				
	{
		if ((*cmp)(current->data, current->next->data) > 0) /* Если содержимое элемента "data" у текущего экземпляра больше чем содережимое такого же
										** элемента у следующего экземпляра, то меняем местами эти экземпляры структуры в цепи связанных между собой
										** экземпляров структур */
		{
			if (current == *begin_list)	/* Если адрес экземпляра в указателе 'current' такой же как и адрес в указателе '*begin_list', значит экземпляры
										** которые мы сейчас хотим поменять местами находятся в начале цепи связянных между собой экземпляров структур. */
				last = *begin_list = (*begin_list)->next; /*Для начала мы перезаписываем адрес в указателе '*begin_list' на адрес следующего экземпляра 
										** структуры('*begin_list' хранит адрес начала цепи связанных между собой экземпляров) и этот же адрес мы сразу 
										** сохраняем в указателе 'last' перезаписывая его для использования этого адреса в след итерации цикла для 
										** сортировки экземпляров, которые будут находится в середине цепи связанных между собой экземпляров */

			else						/* Если адрес экземпляра в указателе 'current' НЕ такой же как и адрес в указателе '*begin_list', значит 
										** экземпляры, которые мы сейчас хотим поменять местами находятся НЕ в начале а в где то СЕРЕДИНЕ цепи 
										** связянных между собой экземпляров структур. */
				last = last->next = current->next; /* Тогда мы используем адрес, который мы сохранили в прошлой итерации цикла во временный указатель 
										** 'last'. Этот указатель хранит адрес предыдущего экземпляра и с помощью него мы сможем поменять местами
										** текущий и следующий экземпляр. 
										** Мы перезаписывая "указатель хранящий адрес текущего экземпляра", сохраняя туда адрес следующего экземпляра
										** и сохраняем этот же адрес в указателе 'last' перезаписывая его для использования этого адреса в след 
										** итерации цикла для сортировки экземпляров, которые будут находится в середине цепи связанных между
										** собой экземпляров */

			tmp = current->next->next;	/* Чтобы не потерять всю последующую цепь связанных между собой структур при дальнейшейм завершениии 
										** сортировки этих двух экземпляров мы сохраняем во временный указатель 'tmp' адрес третьего экземпяра
										** структуры(третий адрес относительно адреса текущего экземплятора) */
			current->next->next = current; /* Теперь, когда мы сдвинули "второй" экземпляр на позициию ниже, следом за ним мы запишем "первый"
										** экземпляр. А реализуем мы это так - запишем в указатель сдвинутого ниже "второго" экземпляра адресс 
										** "первого" экземпляра */
			current->next = tmp;		/* А в указатель "первого" экземпляра который тееперь на второй позиции мы запишем сохраненный во временном
										** указателе адрес "третьего" экземпляра */
			current = *begin_list;		/* Сбрасываем на новое начальное значение указатель хранящий адрес экземпляра с которым мы сейчас работаем
										** чтобы начать сортировку с самого начала цепи связанных между собой структур и так до тех пор пока не 
										** закончим сортировку */
		}
		else							/* В другом случае(Если содержимое элемента "data" у текущего экземпляра не больше чем содережимое такого же
										** элемента у следующего экземпляра) */
		{
			last = current;				/* Сохраняем адрес текущего экземпляра в указатель "last" для следующей итерации цикла */
			current = current->next;	/* Перезаписываем указатель хранящий адрес текущего экземпляра на адрес следующего экземпляра структура в цепи
										** связанных между собой структур для поиска в следующей итерации цикла неотсортированных экземпляров */
		}
	}
}


void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2, \
								int (*cmp)())	/* Функция объединяет элементы отсортированного списка «begin_list2» с другим отсортированным списком
										**  «begin_list1», так что «begin_list1» остается отсортированным в порядке возрастания*/
{
	t_list *current;					/* Обьявляем указатель для хранения адреса текущего экземпляра */

	if (*begin_list1)					/* Если указатель '*begin_list' хранящий начало первой цепи связанных между собой экземпляров структур 
										** содержит адрес экземпляра структуры, значит первая цепь связанных между собой экземпляров существует. 
										** Мы запускаем код ниже*/
	{
		if (begin_list2)				/* Если и указатель 'begin_list2' хранящий начало второй цепи связанных между собой экземпляров структур  
										** содержит адрес экземпляра структуры, значит существует и вторая цепь связанных между собой экземпляров.
										** И мы чтобы обьединить их в одну цепь связанных между собой экземпляров структуры будем искать 
										** последний экземпляр структуры первой цепи 'begin_list1' чтобы записать в его указатель адрес первого
										** экземпляра структуры второй цепи 'begin_list2' */
		{
			current = *begin_list1;		/* Инициализируем указатель адресом первого экземпляра цепи связанных между собой экземпляров структур */
			while (current->next)		/* Запускаем цикл, который дойдет до последнего экземпляра в цепи связаннанных между собой экземпляров */
				current = current->next;/* Перезаписываем указатель на адресс следующего экземпляра структуры цепи связанных между собой экземпляров
										** для перемещения по этой цепи. И так до тех пор пока мы не найдем экземпляр структуры, указатель которого
										** не содержит адреса следующего экземпляра структуры */
			current->next = begin_list2;/* Помещаем в указатель найденого нами экземпляра структуры адресс адрес первого экземпляра структуры цепи
										** 'begin_list2' */
			ft_list_sort(begin_list1, (*cmp));/* Сортируем обьединенную цепь связанных между собой экземпляров структуры */
		}
	}
	else if (begin_list2)				/* Если же указатель 'begin_list1' хранящий начало первой цепи связанных между собой экземпляров
										** структур не содержит адрес экземпляра структуры, значит первая цепь связанных между собой экземпляров не
										** существует то мы проверяем существует ли указатель 'begin_list2' хранящий начало второй цепи связанных 
										** между собой экземпляров структур и если указатель содержит адрес экземпляра структуры, значит существует
										** вторая цепь связанных между собой экземпляров.
										** И мы просто помещаем адресс экземпляра структуры, являющегося началом второй цепи 'begin_list2' 
										** в указатель, который должен хранить начало первой цепи связанных между собой экземпляров структур */
	{
		*begin_list1 = begin_list2;		/* Сохраняем в указателе, который должен хранить адрес первого экземпляра цепи 'begin_list1' адрес
										** первого экземпляра цепи 'begin_list2' и Завершаем функцию */
	}
}


int			main(void)
{
	t_list	*list1;						/* Обьявим указатель структуры типа t_list для хранения адреса экземпляра структуры типа t_list */
	t_list	*list2;						/* Обьявим указатель структуры типа t_list для хранения адреса экземпляра структуры типа t_list */

	list1 = ft_create_elem("Bro ");		/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
										** данных которыем мы ей отправим) и вернет адрес этого экземпляра структуры типа t_list,
										** который мы сохраним в указателе на экземпляр структуры типа t_list */
	list1->next = ft_create_elem("Hey ");/* Запустим фунцию которая создаст экземпляр структуры типа t_list, заполнит его элементы(взяв для этого часть
										** данных которыем мы ей отправим) и вернет адрес этого экземпляра структуры типа t_list 
										** И сохранит этот адрес в указателе на экземпляр структуры типа t_list, который хранится в одном из элементов 
										** текущего экземпляра структуры, адрес которой хранится в указателе 'list' */
	list1->next->next = ft_create_elem("Hello ");

	/* И создадим еще дополнительно несколько экземпляров структуры, соединив их между собой, создав таким образом еще одну цепь связанных между собой
	экземпляров структур типа t_list для теста функции 'ft_sorted_list_merge' */
	list2 = ft_create_elem("My ");
	list2->next = ft_create_elem("Cool ");
	list2->next->next = ft_create_elem("Friend ");

	ft_list_sort(&list1, &ft_strcmp);	/* Сортируем цепь связанных между собой экземпляров структур в порядке возростания */
	ft_list_sort(&list2, &ft_strcmp);	/* Сортируем цепь связанных между собой экземпляров структур в порядке возростания */

	ft_sorted_list_merge(&list1, list2, &ft_strcmp);/* Используя адресс указателя хранящего адрес первого экземпляра цепи  «list1», так же используя
										** адресс первого экземпляра цепи «list2» и адресс функции для сравнения строк, мы объединим элементы
										** отсортированного списка «list2» с другим отсортированным списком «list1» с помощью функции
										** 'ft_sorted_list_merge', так что «list1» остается отсортированным в порядке возрастания */
	ft_put_list(list1);					/* Печатаем результат */
	ft_putchar('\n');					/* Печатаем символ переноса строки для кореектного отображения вывода */
	return (0);							/* Завершаем функцию и возвращаем ноль */
}