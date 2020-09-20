#!/bin/sh
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    find_nicolas_bauer.sh                              :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: evgenkarlson <RTFM@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 12:33:14 by evgenkarlson      #+#    #+#              #
#    Updated: 2020/09/20 17:21:09 by evgenkarlson     ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#	Фрау Фарбиссина должна найти в телефонном справочнике контактные данные	   #
#	от Ника Бомбера, эксперта по сносу.										   #
# **************************************************************************** #
#	• Создайте файл find_nicolas_bauer.sh, в котором будет отображаться  	   #
#	  номер для всех Николя Бауэра из телефонной книги, переданной в качестве  #
#     аргумента.															   #
#																			   #
#	• Ваша программа будет вызываться из телефонной книги sh 				   #
#     find_nicolas_bauer.sh.												   #
#																			   #
#	• Вы, вероятно, пропустите несколько!									   #
# **************************************************************************** #



cat $1 | grep -i 'Nicolas'$'\t''Bomber' | awk '{print $(NF-1)}'


# *******************************__OR__*************************************** #


cat $1 | grep -i -e 'Nicolas'$'\t''Bomber' -e 'Bomber'$'\t''Nicolas' | awk '{print $(NF-1)}'



# **************************************************************************** #
# **************************************************************************** #
# **************************************************************************** #



if [ $# -eq 1 ]; then
	cat $1 | grep -i 'Nicolas'$'\t''Bomber' | awk -F '\t' '{print $3}' | awk -F'[^0-9]*' '$1'
fi


# ********************************__OR__************************************** #


if [ $# -eq 1 ]; then
	cat $1 | grep -i -e 'Nicolas'$'\t''Bomber' -e 'Bomber'$'\t''Nicolas' | awk -F '\t' '{print $3}' | awk -F'[^0-9]*' '$1'
fi



# **************************************************************************** #
# **************************************************************************** #
# **************************************************************************** #


grep -i -e '\(nicolas\)\|\(bomber[[:blank:]]nicolas\)' $1


# **************************************************************************** #
# **************************************************************************** #
# **************************************************************************** #


cat $1 | grep -i 'Nicolas'$'\t''Bomber' | awk -F'\t' '{print$3}' | awk -F'[^0-9]*' '$1'


# **************************************************************************** #
# **************************************************************************** #
# **************************************************************************** #
