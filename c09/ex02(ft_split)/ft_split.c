/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#             */
/*   Updated: 2021/01/23 21:31:00 by evgenkarlson     ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** **
**
** 
**  • Создайте функцию, которая разрезает одну строку символов в используя 
**  значения другой строки символов.
**
** 
** • Используйте каждый символ из строкового набора символов в качестве
**  разделителя.
**
** 
**  • Функция возвращает массив, где каждая ячейка этого массива содержит адрес
**  строки со словом между двумя разделителями. Последний элемент этого массива 
**  должен бытьравен 0, чтобы указать конец массива.
**
**
**  • В вашем массиве не может быть пустых строк. Сделайте свои выводы 
**  соответственно.
**
**
**  • Строка, указанная в качестве аргумента, не подлежит изменению.
**
**
**  • Вот как это должно быть прототипировано:
**
**                                  char  **ft_split(char *str, char *charset);
**
**
** ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_space(char to_find, char *str)
{
	while (*str)
	{
		if (to_find == *str++)
			return (1);
	}
	return (0);
}

int   ft_wordcount(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (ft_is_space(*str, charset)))
			str++;
		if (*str && !(ft_is_space(*str, charset)))
		{
			count++;
			while (*str && !(ft_is_space(*str, charset)))
				str++;
		}
	}
	return (count);
}
/*
int   ft_wordcount(char *str, char *charset)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!(words) && !(ft_is_space(*str, charset)))
			words++;
		else if (ft_is_space(*(str - 1), charset) && !(ft_is_space(*str, charset)))
			words++;
		str++;
	}
	return (words);
}

int		ft_wordcount(char *str, char *charset)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (ft_is_space(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !(ft_is_space(str[i], charset)))
			i++;
	}
	return (count);
}

int		ft_wordcount(char *str, char *charset)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (ft_is_space(*str, charset))
			flag = 1;
		if (!ft_is_space(*str, charset))
		{
			if (flag)
				count++;
			flag = 0;
		}
		str++;
	}
	return (count);
}

*/

char	*create_word(char *str, int i, int j)
{
	char	*word;
	int		o;

	o = 0;
	if ((word = (char *)malloc(sizeof(char) * (j - i))) == ((void *)0))
		return ((void *)0);
	while (i < j)
	{
		word[o] = str[i];
		i++;
		o++;
	}
	word[o] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		index;
	int		j;
	int		i;
	int		words;

	index = 0;
	if ((words = ft_wordcount(str, charset)))
	{
		if (!str || ((arr = (char **)malloc(sizeof(char *) * (words + 1))) == ((void *)0)))
			return ((void *)0);
		i = 0;
		while (index < words)
		{
			while (ft_is_space(str[i], charset) && (str[i]))
				i++;
			j = i;
			while (!(ft_is_space(str[j], charset)) && (str[j]))
				j++;
			arr[index++] = create_word(str, i, j);
			i = j + 1;
		}
	}
	else
		arr = (char **)malloc(sizeof(char *));
	arr[index] = (void *)0;
	return (arr);
}


/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>

int		ft_is_space(char to_find, char *str)
{
	while (*str)
	{
		if (to_find == *str++)
			return (1);
	}
	return (0);
}

int   ft_wordcount(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (ft_is_space(*str, charset)))
			str++;
		if (*str && !(ft_is_space(*str, charset)))
		{
			count++;
			while (*str && !(ft_is_space(*str, charset)))
				str++;
		}
	}
	return (count);
}
/*
int   ft_wordcount(char *str, char *charset)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!(words) && !(ft_is_space(*str, charset)))
			words++;
		else if (ft_is_space(*(str - 1), charset) && !(ft_is_space(*str, charset)))
			words++;
		str++;
	}
	return (words);
}

int		count_words(char *str, char *charset)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (ft_is_space(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !(ft_is_space(str[i], charset)))
			i++;
	}
	return (count);
}

int		ft_wordcount(char *str, char *charset)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (ft_is_space(*str, charset))
			flag = 1;
		if (!ft_is_space(*str, charset))
		{
			if (flag)
				count++;
			flag = 0;
		}
		str++;
	}
	return (count);
}

*/

int		ft_wordlen(char *str, char *charset)
{
	int		len;

	len = 0;
	while (ft_is_space(*str, charset))
		str++;
	while (*str && !(ft_is_space(*str, charset)))
	{
		str++;
		len++;
	}
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	**arr;
	int		words;

	words = ft_wordcount(str, charset);
	i = 0;
	if (!str || (((arr = (char **)malloc(sizeof(char*) * (words + 1)))) == ((void *)0)))
		return ((void *)0);
	while (i < words)
	{
		if ((arr[i] = (char *)malloc(sizeof(char) * (ft_wordlen(str, charset) + 1))) == ((void *)0))
			return ((void*)0);
		j = 0;
		while (ft_is_space(*str, charset))
			str++;
		while (*str && !(ft_is_space(*str, charset)))
			arr[i][j++] = *str++;
		arr[i][j] = '\0';
		i++;
	}
	arr[i] = ((void *)0);
	return (arr);
}

/* ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_space(char to_find, char *str)
{
	while (*str)
	{
		if (to_find == *str++)
			return (1);
	}
	return (0);
}

int   ft_wordcount(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (ft_is_space(*str, charset)))
			str++;
		if (*str && !(ft_is_space(*str, charset)))
		{
			count++;
			while (*str && !(ft_is_space(*str, charset)))
				str++;
		}
	}
	return (count);
}
/*
int   ft_wordcount(char *str, char *charset)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!(words) && !(ft_is_space(*str, charset)))
			words++;
		else if (ft_is_space(*(str - 1), charset) && !(ft_is_space(*str, charset)))
			words++;
		str++;
	}
	return (words);
}

int		count_words(char *str, char *charset)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (ft_is_space(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !(ft_is_space(str[i], charset)))
			i++;
	}
	return (count);
}

int		ft_wordcount(char *str, char *charset)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (ft_is_space(*str, charset))
			flag = 1;
		if (!ft_is_space(*str, charset))
		{
			if (flag)
				count++;
			flag = 0;
		}
		str++;
	}
	return (count);
}

*/


char  *ft_create_word(char *str, char *charset)
{
	char *word;
	int	i;

	i = 0;
	while (str[i] && !ft_is_space(str[i], charset))
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	while (str[i] && !ft_is_space(str[i], charset))
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int i;
	char **arr;

	arr = (char **)malloc(sizeof(char *) * (ft_wc(str, charset) + 1));
	i = 0;
	while (*str)
	{
		while (*str && ft_is_space(*str, charset))
			str++;
		if (*str && !ft_is_space(*str, charset))
		{
			arr[i] = ft_create_word(str, charset);
			i++;
			while (*str && !ft_is_space(*str, charset))
				str++;
		}
	}
	arr[i] = ((void *)0);
	return (arr);
}

/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>

int		ft_is_space(char to_find, char *str)
{
	while (*str)
	{
		if (to_find == *str++)
			return (1);
	}
	return (0);
}

int		ft_wordcount(char *str, char *charset)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (ft_is_space(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !(ft_is_space(str[i], charset)))
			i++;
	}
	return (count);
}

int		ft_wordlen(char *str, char *charset)
{
	int		len;

	len = 0;
	while (str[len]
			&& !(ft_is_space(str[len], charset)))
		len++;
	return (len);
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		pos;
	int		i;
	int		j;

	if (!(tab = (char **)malloc((ft_wordcount(str, charset) + 1) * sizeof(char *))))
		return ((void *)0);
	pos = 0;
	i = 0;
	while (str[i])
	{
		while (ft_is_space(str[i], charset))
			i++;
		if (str[i])
		{
			if (!(tab[pos] = (char *)malloc(ft_wordlen(str + i, charset) * sizeof(char))))
				return ((void *)0);
			j = 0;
			while (str[i] && !(ft_is_space(str[i], charset)))
				tab[pos][j++] = str[i++];
			tab[pos++][j] = '\0';
		}
	}
	tab[pos] = (void *)0;
	return (tab);
}



/* ************************************************************************** */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_is_space(char to_find, char *str)
{
	while (*str)
	{
		if (to_find == *str++)
			return (1);
	}
	return (0);
}

int   ft_wordcount(char *str, char *charset)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str && (ft_is_space(*str, charset)))
			str++;
		if (*str && !(ft_is_space(*str, charset)))
		{
			count++;
			while (*str && !(ft_is_space(*str, charset)))
				str++;
		}
	}
	return (count);
}
/*
int   ft_wordcount(char *str, char *charset)
{
	int		words;

	words = 0;
	while (*str)
	{
		if (!(words) && !(ft_is_space(*str, charset)))
			words++;
		else if (ft_is_space(*(str - 1), charset) && !(ft_is_space(*str, charset)))
			words++;
		str++;
	}
	return (words);
}

int		count_words(char *str, char *charset)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (ft_is_space(str[i], charset))
			i++;
		if (str[i])
			count++;
		while (str[i] && !(ft_is_space(str[i], charset)))
			i++;
	}
	return (count);
}

int		ft_wordcount(char *str, char *charset)
{
	int	count;
	int	flag;

	count = 0;
	flag = 1;
	while (*str)
	{
		if (ft_is_space(*str, charset))
			flag = 1;
		if (!ft_is_space(*str, charset))
		{
			if (flag)
				count++;
			flag = 0;
		}
		str++;
	}
	return (count);
}

*/

int		ft_len_word(char *str, int i, char *charset)
{
	int count;

	count = 0;
	while (!(ft_is_space(str[i], charset)) && str[i])
	{
		count++;
		i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	if ((res = malloc(sizeof(char*) * (ft_wordcount(str, charset) + 1))) == NULL)
		return ((void *)0);
	while (str[i])
	{
		while (ft_is_space(str[i], charset) && str[i])
			i++;
		if (str[i])
		{
			k = 0;
			if ((res[j] = malloc(sizeof(char) * ft_len_word(str, i, charset) + 1)) == NULL)
				return ((void *)0);
			while (!ft_is_space(str[i], charset) && str[i])
				res[j][k++] = str[i++];
			res[j++][k] = '\0';
		}
	}
	res[j] = (void *)0;
	return (res);
}


/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>

int		ft_is_space(char to_find, char *str)
{
	while (*str)
	{
		if (to_find == *str++)
			return (1);
	}
	return (0);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int index;

	index = 0;
	while (index < n && src[index] != '\0')
		dest[index] = src[index++];
	while (index < n)
	{
		dest[index] = '\0';
		index++;
	}
	return (dest);
}

int		ft_wordcount(char *str, char *charset)
{
	int		count;
	char	*previous;
	char	*next;

	count = 0;
	previous = str;
	next = str;
	while (1)
	{
		if (ft_is_space(*str, charset))
			next = str;
		if (next - previous > 1)
			count++;
		if (*str == '\0')
			break ;
		previous = next;
		str++;
	}
	return (count);
}

int		ft_add_part(char **entry, char *previous, int size, char *charset)
{
	if (ft_is_space(previous[0], charset))
	{
		previous++;
		size--;
	}
	*entry = (char *)malloc((size + 3) * sizeof(char));
	ft_strncpy(*entry, previous, size);
	(*entry)[size] = '\0';
	(*entry)[size + 1] = '\0';
	return (1);
}

char	**ft_split(char *str, char *charset)
{
	int		index;
	int		size;
	char	*previous;
	char	*next;
	char	**array;

	array = (char **)malloc((ft_wordcount(str, charset) + 1) * sizeof(char *));
	index = 0;
	previous = str;
	next = str;
	while (1)
	{
		if (ft_is_space(*str, charset))
			next = str;
		if ((size = next - previous) > 1)
			index += ft_add_part(&array[index], previous, size, charset);
		if (*str == '\0')
			break ;
		previous = next;
		str++;
	}
	array[index] = 0;
	return (array);
}


/* ************************************************************************** */
/* ************************************************************************** */


#include <stdlib.h>

char	*ft_strncpy(char *dest, char *src, int nb)
{
	int i;

	i = 0;
	while (src[i] && (i < nb))
	{
		dest[i] = src[i];
		i++;
	}
	while (i < nb)
	{
		dest[i] = '\0';
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		is_valid(char str, char *charset)
{
	int i;

	i = 0;
	while (charset[i])
	{
		if (str == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int		scanstr(char *str, char *charset)
{
	int i;

	i = 0;
	while (!(is_valid(str[i], charset)) && str[i] != '\0')
		i++;
	return (i);
}

int		wordcount(char *str, char *charset)
{
	int i;
	int	count;

	i = 0;
	count = 0;
	if (!*str)
		return (0);
	while (str[i])
	{
		while (str[i] && is_valid(str[i], charset))
			i++;
		if (!(is_valid(str[i], charset)) && str[i])
			count++;
		while (str[i] && (!(is_valid(str[i], charset))))
			i++;
	}
	return (count);
}

char	**ft_split(char *str, char *charset)
{
	int		wc;
	int		i;
	int		k;
	char	**out;
	char	*ptr;

	i = 0;
	k = 0;
	ptr = str;
	wc = wordcount(ptr, charset);
	if (!(out = (char **)malloc(sizeof(char*) * (wc + 1))))
		return (0);
	while (k < wc)
	{
		i = scanstr(ptr, charset);
		if (!(out[k] = (char *)malloc(i + 1)))
			return (0);
		ft_strncpy(out[k], ptr, i);
		ptr += (i + 1);
		while (*ptr && (is_valid(*ptr, charset)))
			ptr++;
		k++;
	}
	out[k] = 0;
	return (out);
}
