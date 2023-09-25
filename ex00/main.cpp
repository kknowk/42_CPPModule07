/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:53:45 by khorike           #+#    #+#             */
/*   Updated: 2023/09/24 16:38:39 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main()
{
	// test 1 int
	std::cout << YELLOW << "test 1 int" << END << std::endl;
	
	int a = 2;
	int b = 3;

	std::cout << std::endl;
	std::cout << GREEN << "befor " << "a = " << a << ", b = " << b << std::endl;

	::swap(a,b);

	std::cout << std::endl;
	std::cout << "after " << "a = " << a << ", b = " << b << END << std::endl;
	std::cout << std::endl;

	// test max min
	std::cout << YELLOW << "test max min\n" << END << std::endl;
	std::cout << GREEN << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << END << std::endl;

	std::cout << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << std::endl;


	// test2 char
	std::cout << YELLOW << "test2 char" << END << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";

	std::cout << std::endl;
	std::cout << GREEN << "befor " << "c = " << c << ", d = " << d << std::endl;

	::swap(c,d);

	std::cout << std::endl;
	std::cout << "after " << "c = " << c << ", d = " << d << END << std::endl;

	std::cout << std::endl;

	// test max min
	std::cout << YELLOW << "test max min\n" << END << std::endl;

	std::cout << GREEN << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << END << std::endl;

	std::cout << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << std::endl;


	// test3 equal
	a = 97;
	b = 'a';

	std::cout << std::endl;
	std::cout << YELLOW << "test3 equal\n" << END << std::endl;
	std::cout << GREEN << "befor " << "a = " << a << ", b = " << b << std::endl;

	::swap(a,b);

	std::cout << std::endl;
	std::cout << "after " << "a = " << a << ", b = " << b << END << std::endl;
	std::cout << std::endl;

	// test max min
	std::cout << YELLOW << "test max min\n" << END << std::endl;
	std::cout << GREEN << "a adress " << &a << std::endl;
	std::cout << "b adress " << &b << std::endl;
	
	int& min_result = ::min(a, b);
	int& max_result = ::max(a, b);

	// 同じ値だと後者が呼ばれるのでbのアドレスになる
	std::cout << std::endl;
	std::cout << "Address of min function: " << &min_result << std::endl;
	std::cout << "Address of max function: " << &max_result << std::endl;
	std::cout << std::endl;

	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << END << std::endl;

	std::cout << std::endl;
	std::cout << "------------------------" << std::endl;
	std::cout << std::endl;
	
	return 0;
}
