/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:53:47 by khorike           #+#    #+#             */
/*   Updated: 2023/09/25 13:14:32 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#define END             "\033[0m"
#define BOLD            "\033[1m"
#define BLACK           "\033[30m"
#define RED             "\033[31m"
#define GREEN           "\033[32m"
#define YELLOW          "\033[33m"
#define BLUE            "\033[34m"
#define MAGENTA         "\033[35m"
#define CYAN            "\033[36m"
#define WHITE           "\033[37m"
#define UNDERLINE       "\033[4m"
#define BOLD_UNDERLINE  "\033[1;4m"

#include <iostream>

template <typename T>
void printElement(T element)
{
	std::cout << BLUE << element << END << std::endl;;
}

void printChar(char *element)
{
	std::cout << BLUE << element << END << std::endl;;
}

void print(int element)
{
	std::cout << BLUE << element << END << std::endl;;
}

template <typename T>
void iter(T *arr, size_t length, void (*func)(T))
{
	if (!arr || !func)
	{
		std::cout << RED << "null eroor" << END << std::endl;;
		return;
	}
	for (size_t i = 0; i < length; ++i)
		func(arr[i]);
}

// const ver オーバーロード
template <typename T>
void iter(const T *arr, size_t length, void (*func)(const T))
{
	if (!arr || !func)
	{
		std::cout << RED << "null eroor" << END << std::endl;;
		return;
	}
	for (size_t i = 0; i < length; ++i)
	{
		func(arr[i]);
	}
}

// const 絶対許さないマン
template <typename T>
void zero(T a)
{
	a = 0;
	std::cout << a << std::endl;;
}

#endif