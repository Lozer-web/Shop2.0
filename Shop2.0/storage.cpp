#include "storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool isstoragecreated = false;

void CreateStorage(int mode)
{
	if (mode == 0 && isstoragecreated)
	{
		const size_t stsize = 15;

		size_t idArrSt[stsize]{ 1,2,3,4,5,6,7,8,9,10,11,12 };
		std::wstring nameArrSt[stsize]
		{
			L"Хавчик для массанапора", L"Газява для качка", L"Хрумки для большой пиструнки",
			L"Креатин для мущщин", L"Протеин для мудрил", L"Кистевики страховики", L"Лямки вонялки"
			L"Солевой скачок", L"Изотоник мазолик", L"Батончики для наборчика",L"Печенюхи для жимухи",
			L"Магнезия из Скандинезии"
		};
		size_t countArrSt[stsize]{ 25,100,100,70,50,20,30,34,70,60,50,33 };
		double priceArrSt[stsize]{130,80,60,2000,2500,700,1000,500,60,90,130,210 };
		sizeSt = stsize;
		idArr = new size_t[sizeSt];
		nameArr = new std::wstring[sizeSt];
		countArr = new size_t[sizeSt];
		priceArr = new double[sizeSt];

		FillArr(idArr, idArrSt, sizeSt);
		FillArr(nameArr, nameArrSt, sizeSt);
		FillArr(countArr, countArrSt, sizeSt);
		FillArr(priceArr, priceArrSt, sizeSt);

		isstoragecreated = true;
	}

	else if (mode == 1)
	{
		//to do
	}
	else
	{
		std::wcout << L"Склад уже создан!\n\n";
		Sleep(1500);
	}
}

void ShowStorage(int mode)
{
	if (mode == 0)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tТовары \"Горилы-Варилы\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Кол-во\t" << L"Цена\n\n";
	}
}