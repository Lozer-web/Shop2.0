#include "storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;
bool isstoragecreated = false;
double MaxPrice = 600000;

size_t MaxStorageSize = 7000;
size_t CurrentStorageSize = 0;

void CreateStorage(int mode)
{
	if (mode == 0 && !isstoragecreated)
	{
		const size_t stsize = 11;

		size_t idArrSt[stsize]{ 1,2,3,4,5,6,7,8,9,10,11, };
		std::wstring nameArrSt[stsize]
		{
			L"Хавчик для массанапора", L"Газява для качка", L"Хрумки для большой пиструнки",
			L"Креатин для мущщин", L"Протеин для мудрил", L"Кистевики страховики", L"Лямки вонялки"
			L"Солевой скачок", L"Изотоник мазолик", L"Батончики для наборчика",L"Печенюхи для жимухи",
			L"Магнезия из Скандинезии"
		};
		size_t countArrSt[stsize]{ 25,100,100,70,50,20,30,34,70,60,50, };
		double priceArrSt[stsize]{130,80,60,2000,2500,700,1000,500,60,90,130, };
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

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t" << std::setprecision(2) << priceArr[i] << L"\t\t\t\n";
		}
		std::wcout << L"\n";
		system("pause");
	}
	else if (mode == 1)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tПополнение Товаров \"Горилы-Варилы\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Кол-во\t";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t\t" << std::fixed << std::left << std::setw(40) << nameArr[i]
				<< L"\t\t" << countArr[i] << L"\t\t";
		}
		std::wcout << L"\n";
		std::wcout << "Занято на слкаде " << CurrentStorageSize << L" из " << MaxStorageSize 
			<< L" мест\n\n";

	}
	else if (mode == 2)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tСписание Товаров \"Горилы-Варилы\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"Кол-во\t";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t\t" << std::fixed << std::left << std::setw(40) << nameArr[i]
				<< L"\t\t" << countArr[i] << L"\t\t";
		}
		std::wcout << L"\n";
		std::wcout << "Занято на слкаде " << CurrentStorageSize << L" из " << MaxStorageSize
			<< L" мест\n\n";
	}
	else if (mode == 3)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tИзменение цен \"Горилы-Варилы\"\n\n";

		std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
			<< L"цена\t";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t\t" << std::fixed << std::left << std::setw(40) << nameArr[i]
				<< L"\t\t" << std::setprecision(2) << priceArr[i] << L"\t\t";
		}
		std::wcout << L"\n";
		;
	}
}

void FillProduct()
{
	std::wstring chooseId, chooseCount, choose;

	while (true)
	{
		ShowStorage();
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции пополнения товара\n\n";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите количество товара на пополнение: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					size_t count = std::stoull(chooseCount);
					if (count < 0 || count > MaxStorageSize - CurrentStorageSize)
					{
						std::wcout << L"Неккоректное кол-во! На складе осталось "
							<< MaxStorageSize - CurrentStorageSize << L" свободных мест\n\n";
						Sleep(1700);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> "
								<< countArr[id] + count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - да\n2 - нет\n\nВвод: ";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"Товар успешно пополнен. Красава!\n\n";
								countArr[id] += count;
								CurrentStorageSize += count;
								Sleep(1500);
								break;
							}
							else if(choose == L"2")
							{
								std::wcout << L"отмена пополнения товара, Вась " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}

						}
					}
				}
			}
		}
	}
}

void RemoveProduct()
{
	std::wstring chooseId, chooseCount, choose;
	ShowStorage(2);

	while (true)
	{
		ShowStorage();
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции пополнения товара\n\n";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите количество товара для списания: ";
				Getline(chooseCount);
				if (IsNumber(chooseCount))
				{
					size_t count = std::stoull(chooseCount);
					if (count < 0 || count > MaxStorageSize - CurrentStorageSize)
					{
						std::wcout << L"Неккоректное кол-во! На складе осталось "
							<< countArr[id] << L" штук\n\n";
						Sleep(1700);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> "
								<< countArr[id] + count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - да\n2 - нет\n\nВвод: ";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"Товар успешно списан. Красава!\n\n";
								countArr[id] += count;
								CurrentStorageSize += count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"отмена списания товара, Вась " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}

						}
					}
				}
			}
		}
	}
}

void ChangePrice()
{
	std::wstring chooseId, choosePrice, choose;
	ShowStorage(3);

	while (true)
	{
		ShowStorage();
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции изменения цены\n\n";
			Sleep(1500);
			return;
		}
		else if (IsNumber(chooseId))
		{
			int id = std::stoi(chooseId) - 1;
			if (id < 0 || id > sizeSt - 1)
			{
				Err();
			}
			else
			{
				std::wcout << L"Введите новую стоимость товара: ";
				Getline(choosePrice);
				if (IsNumber(choosePrice))
				{
					size_t count = std::stod(choosePrice);
					if (count < 0 || count > MaxPrice)
					{
						std::wcout << L"Неккоректное кол-во! На складе осталось "
							<< countArr[id] << L" штук\n\n";
						Sleep(1700);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << countArr[id] << L" -----> "
								<< countArr[id] + count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - да\n2 - нет\n\nВвод: ";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"Товар успешно списан. Красава!\n\n";
								countArr[id] += count;
								CurrentStorageSize += count;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"отмена списания товара, Вась " << nameArr[id] << L"\n";
								Sleep(1500);
								break;
							}
							else
							{
								Err();
							}

						}
					}
				}
			}
		}
	}
}

