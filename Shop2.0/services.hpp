#ifndef _SERVICES_HPP_
#define _SERVICES_HPP_

#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include <cwctype>

void Getline(std::wstring& str, wchar_t ch = L'\n');

bool IsNumber(const std::wstring& str);
bool IsNotSame(const std::wstring& str, std::wstring* nameArr, size_t arrSize);


__forceinline void Err()
{
	std::wcout << L"Неккоректный ввод!";
	Sleep(1500);
}


template <class Arrtype>
void FillArr(Arrtype* dynamicArr, Arrtype* staticArr, size_t commonSize)
{
	for (size_t i = 0; i < commonSize; i++)
	{
		dynamicArr[i] = staticArr[i];
	}
}

template <class ArrType>
void ArrPushBack(ArrType*& arr, size_t arrSize)
{
	arrSize++;
	ArrType* temp = new ArrType[arrSize]{};
	for (size_t i = 0; i < arrSize - 1; i++)
	{
		temp[i] = arr[i];
	}
	std::swap(arr, temp);
	delete[]temp;
}


#endif // !_SERVICES_HPP_