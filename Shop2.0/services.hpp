#ifndef _SERVICES_HPP_
#define _SERVICES_HPP_

#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>

void Getline(std::wstring& str, wchar_t ch = L'\n');

bool IsNumber(const std::wstring& str);


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



#endif // !_SERVICES_HPP_