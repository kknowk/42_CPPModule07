/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khorike <khorike@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 16:42:11 by khorike           #+#    #+#             */
/*   Updated: 2023/09/22 18:53:13 by khorike          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

// 空の配列を作成
template<typename T>
Array<T>::Array() : data(NULL), length(0) {}

// デフォルトで初期化されたn個の要素の配列を作成
template<typename T>
Array<T>::Array(unsigned int n) : data(NULL), length(n)
{
	try {
		data = new T[n]();
	} catch(const std::bad_alloc& ex) {
		std::cerr << "Memory allocation failed: " << ex.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
}

template<typename T>
Array<T>::Array(const Array& other) : data(NULL), length(other.length)
{
	try {
		data = new T[other.length];
	} catch(const std::bad_alloc& ex) {
		std::cerr << "Memory allocation failed: " << ex.what() << std::endl;
		std::exit(EXIT_FAILURE);
	}
	for(unsigned int i = 0; i < length; ++i)
		data[i] = other.data[i];
}

template<typename T>
Array<T>& Array<T>::operator=(const Array& other)
{
	if (this != &other)
	{
		// 新しいメモリ割り当てが失敗すると例外となり抜ける
		// 先に　delete[] data; するとNULLでもない変なところを指してしまう
		T* tempData = NULL;
		try {
			tempData = new T[other.length];
		} catch(const std::bad_alloc& ex) {
			std::cerr << "Memory allocation failed: " << ex.what() << std::endl;
			std::exit(EXIT_FAILURE);
		}
		// 新しいメモリ割り当て成功時のみdeleteする
		delete[] data;
		data = tempData;
		length = other.length;
		for(unsigned int i = 0; i < length; ++i)
			data[i] = other.data[i];
	}
}

template<typename T>
Array<T>::~Array()
{
	delete[] data;
}

// 要素は[]演算子を使用してアクセスできる
// そのインデックスが範囲外の場合はstd::exceptionがスロー
template<typename T>
T& Array<T>::operator[](unsigned int index)
{
	// 配列なので、要素数 - １が範囲
	if (index >= length)
		throw std::exception();
	return data[index];
}

// 配列内の要素の数を返すメンバ関数size()
template<typename T>
unsigned int Array<T>::size() const
{
	return length;
}
