/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:53:45 by khorike           #+#    #+#             */
/*   Updated: 2023/09/25 13:29:37 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main()
{
	// test int
	std::cout << YELLOW << "test int" << END << std::endl;
	int arr[] = {1, 2, 3, 4, 5};
	size_t len = 5;
	iter(arr, len, printElement<int>);
	
	std::cout << "------------------------" << std::endl;

	// test double
	std::cout << YELLOW << "test double" << END << std::endl;
	double arr2[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	size_t len2 = 5;
	iter(arr2, len2, printElement<double>);

	std::cout << "------------------------" << std::endl;

	// test char *
	std::cout << YELLOW << "test char *" << END << std::endl;
	const char *arr3[] = {"Toukaiteio", "Sinborirudoruhu", "Eaguru-vu"};
	size_t len3 = 3;
	iter(arr3, len3, printElement<const char*>);

	std::cout << "------------------------" << std::endl;

	// test const int
	std::cout << YELLOW << "test const int" << END << std::endl;
	const int arr4[] = {8, 9, 10};
	iter(arr4, 3, printElement<const int>);


	std::cout << "------------------------" << std::endl;

	// test const error
	std::cout << YELLOW << "test const int" << END << std::endl;
	iter(arr, 3, zero<int>);

	// constを渡そうとするとコンパイルエラーになる
	// iter(arr4, 3, zero<int>);


	std::cout << "------------------------" << std::endl;

	// test null error
	char *null = NULL;
	std::cout << YELLOW << "test null error" << END << std::endl;
	iter(null, 3, printElement<char>);

	// またT をNULLにするには無理やりcast しないといけない
	// NULLは整数としてLONG として解釈される。
	iter(reinterpret_cast<long*>(NULL), 3, printElement<long>);
	// test over range error
	// std::vectorが使えないので、領域外参照はこちらで管理しなければならない
	// std::cout << YELLOW << "test over range error" << END << std::endl;
	// iter(arr, 6,  printElement<int>);


	// constを渡そうとするとコンパイルエラーになる
	// iter(arr4, 3, zero<int>);


	std::cout << "------------------------" << std::endl;

	// test func null
	// func が　NULL だとコンパイルエラー
	// iter(reinterpret_cast<long*>(NULL), 3, NULL);

	std::cout << "------------------------" << std::endl;

	// int arr[] = {1, 2, 3, 4, 5};
	iter(arr, 3, print);
	// iter(arr, 3, printChar);
	return 0;
}
