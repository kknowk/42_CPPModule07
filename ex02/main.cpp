/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 12:53:45 by khorike           #+#    #+#             */
/*   Updated: 2023/09/25 12:34:15 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
	Array<int> arr1(5);
	Array<int> arr2 = arr1;
	arr1[0] = 10;

	// test 他方の配列に影響を与えてない
	std::cout << BLUE << arr1[0] << std::endl << END;
	std::cout << BLUE << arr2[0] << std::endl << END;

	std::cout << "------------------------" << std::endl;

	// test another type
	Array<unsigned int> arr3(10);
	Array<unsigned int> arr4 = arr3;
	arr3[0] = 0;
	arr3[1] = 4294967295;
	std::cout << BLUE << arr3[1] << std::endl << END;
	std::cout << BLUE << arr4[1] << std::endl << END;

	std::cout << "------------------------" << std::endl;

	// test インデックスが範囲外かどうか
	try {
		std::cout << arr1[10] << std::endl;
	} catch(const std::exception& e) {
		std::cerr << RED <<"Out of range access!" << std::endl << END;
	}

	std::cout << "------------------------" << std::endl;

	// test 要素数を投げているか
	std::cout << GREEN <<"Array size: " << arr1.size() << std::endl << END;
	std::cout << GREEN <<"Array size: " << arr3.size() << std::endl << END;

	// test another range unsigned int
	// compile error
	// Array<unsigned int> arr_max_plus_1(4294967296);
	// std::cout << GREEN <<"Array size: " << arr_max.size() << std::endl << END;

	std::cout << "------------------------" << std::endl;

	// OK 重いのでコメントアウト
	// Array<unsigned int> arr_minus(-1);
	// std::cout << GREEN <<"Array size: " << arr_minus.size() << std::endl << END;


	std::cout << "------------------------" << std::endl;

	// test 自己代入をした時にバグらないか、またリークしないか
	Array<int> arr10(5);
	arr10[0] = 1;
	arr10[0] = arr10[0];
	std::cout << BLUE << arr10[0] << END << std::endl;
	
	return 0;
}

// __attribute__((destructor)) static void destructor(void)
// {
// 	system("leaks -q ex02");
// }


// #include <iostream>
// #include "Array.hpp"

// #define MAX_VAL 750
// int main(int, char**)
// {
//     Array<int> numbers(MAX_VAL);
//     int* mirror = new int[MAX_VAL];
//     srand(time(NULL));
//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         const int value = rand();
//         numbers[i] = value;
//         mirror[i] = value;
//     }
//     //SCOPE
//     {
//         Array<int> tmp = numbers;
//         Array<int> test(tmp);
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         if (mirror[i] != numbers[i])
//         {
//             std::cerr << "didn't save the same value!!" << std::endl;
//             return 1;
//         }
//     }
//     try
//     {
//         numbers[-2] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }
//     try
//     {
//         numbers[MAX_VAL] = 0;
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << '\n';
//     }

//     for (int i = 0; i < MAX_VAL; i++)
//     {
//         numbers[i] = rand();
//     }
//     delete [] mirror;//
//     return 0;
// }

// int * a = new int();
// std::cout << *a << std::endl;

// ０と　出力される。

// プリミティブ型の変数はデフォルトで初期化されず、未定義の値を持つ
// 括弧を使用すると、
// プリミティブ型の変数もデフォルトで0に初期化されます。

// プリミティブ型
// 1.整数型 (int, short, long, long long)
// 2.符号なし整数型 (unsigned int, unsigned short, unsigned long, unsigned long long)
// 3.文字型 (char, wchar_t, char16_t, char32_t)
// 4.浮動小数点型 (float, double)
// 5.論理型 (bool)