#include "storage.hpp"

size_t sizeSt = 0;
size_t* idArr = nullptr;
std::wstring* nameArr = nullptr;
size_t* countArr = nullptr;
double* priceArr = nullptr;

size_t* supplierCountArr = nullptr;//ПОСТАВЩИК ДЗ
double* supplierPriceArr = nullptr;

bool isstoragecreated = false;
double MaxPrice = 600000;

size_t MaxStorageSize = 7000;
size_t CurrentStorageSize = 0;

void CreateStorage(int mode)
{
	if (mode == 0 && !isstoragecreated)
	{
		const size_t stsize = 12;

		size_t idArrSt[stsize]{ 1,2,3,4,5,6,7,8,9,10,11,12 };
		std::wstring nameArrSt[stsize]
		{
			L"Хавчик для массанапора", L"Газява для качка", L"Хрумки для большой пиструнки",
			L"Креатин для мущщин", L"Протеин для мудрил", L"Кистевики страховики", L"Лямки вонялки",
			L"Солевой скачок", L"Изотоник мазолик", L"Батончики для наборчика",L"Печенюхи для жимухи",
			L"Магнезия из Скандинезии"
		};
		size_t countArrSt[stsize]{ 25,100,100,70,50,20,30,34,70,60,50,55 };
		double priceArrSt[stsize]{130,80,60,2000,2500,700,1000,500,60,90,130,222 };
		size_t supplierCountArrSt[stsize]{ 150,300,250,120,100,80,90,110,200,180,140,130 };//ПОСТАВЩИК ДЗ

		sizeSt = stsize;
		idArr = new size_t[sizeSt];
		nameArr = new std::wstring[sizeSt];
		countArr = new size_t[sizeSt];
		priceArr = new double[sizeSt];
		supplierCountArr = new size_t[sizeSt];
		supplierPriceArr = new double[sizeSt];

		FillArr(idArr, idArrSt, sizeSt);
		FillArr(nameArr, nameArrSt, sizeSt);
		FillArr(countArr, countArrSt, sizeSt);
		FillArr(priceArr, priceArrSt, sizeSt);
		FillArr(supplierCountArr, supplierCountArrSt, sizeSt);

		for (size_t i = 0; i < sizeSt; i++)
		{
			supplierPriceArr[i] = priceArr[i] * 0.8;
			CurrentStorageSize += countArr[i];
		}

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
			std::wcout << idArr[i] << L"\n\t" << std::fixed << std::left << std::setw(40) << nameArr[i]
				<< L"\t" << countArr[i] << L"\t";
		}
		std::wcout << L"\n";
		std::wcout << L"Занято на слкаде " << CurrentStorageSize << L" из " << MaxStorageSize 
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
	
	else if (mode == 4)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tПереименование товара \"Горилы-Варилы\"\n\n";

		std::wcout << L"ID\t" << L"Название товара\t\t";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t\t" << std::fixed << std::left << std::setw(40) << nameArr[i] << L"\n";
		}
		std::wcout << L"\n";
		;
	}

	else if (mode == 5)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tУдаление товара \"Горилы-Варилы\"\n\n";

		std::wcout << L"ID\t" << L"Название товара\t\t";

		for (size_t i = 0; i < sizeSt; i++)
		{
			std::wcout << idArr[i] << L"\t\t" << std::fixed << std::left << std::setw(40) << nameArr[i] << L"\n";
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
		ShowStorage(1);
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
				std::wcout << L"Доступно у поставщика: " << supplierCountArr[id]//ПОСТАВЩИК ДЗ
					<< L" шт. по цене " << supplierPriceArr[id] << L"\n";
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
					else if (count > supplierCountArr[id])//ПОСТАВЩИК ДЗ
					{
						std::wcout << L"У поставщика недостаточно товара! Доступно: "
							<< supplierCountArr[id] << L" шт.\n\n";
						Sleep(1700);
					}
					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\n";
							std::wcout << L"Склад магазина: " << countArr[id] << L" -----> "
								<< countArr[id] + count << L"\n";
							std::wcout << L"Склад поставщика: " << supplierCountArr[id] << L" -----> "//ПОСТАВЩИК ДЗ
								<< supplierCountArr[id] - count << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - да\n2 - нет\n\nВвод: ";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"Товар успешно пополнен. Красава!\n\n";
								countArr[id] += count;
								CurrentStorageSize += count;
								supplierCountArr[id] -= count;//ПОСТАВЩИК ДЗ
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
			std::wcout << L"Завершение изменения цены\n\n";
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
					double price = std::stod(choosePrice);

					if (price < 0 || price > MaxPrice)
					{
						std::wcout << L"Неккоректная цена! Максимально возможная цена: "
							<< MaxPrice << L" рублей\n\n";
						Sleep(1700);
					}

					else
					{
						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << priceArr[id] << L" -----> "
								<< price << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - да\n2 - нет\n\nВвод: ";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"Успешно изменена цена. Красава!\n\n";
								priceArr[id] = price;
							
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"отмена изменения цены, Вась " << nameArr[id] << L"\n";
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

void ShowSupplierStorage()
{
	system("cls");
	std::wcout << L"\n\n\t\t\tСклад поставщика \"Горилы-Варилы\"\n\n";

	std::wcout << L"ID\t" << std::left << std::setw(40) << L"Название товара\t\t"
		<< L"Кол-во\t" << L"Цена (-20%)\n\n";

	for (size_t i = 0; i < sizeSt; i++)
	{
		std::wcout << idArr[i] << L"\t" << std::fixed << std::left << std::setw(40) << nameArr[i]
			<< L"\t" << supplierCountArr[i] << L"\t" << std::setprecision(2) << supplierPriceArr[i] << L"\n";
	}
	std::wcout << L"\n";
	system("pause");
}

void ChangeStorage()
{
	std::wstring choose;

	while (true)
	{
		system("cls");
		std::wcout << L"\n\n\t\t\tРедактирование склада \"Горила-Варила\"\n\n";
		std::wcout << L"1 - Добавить новый товар\n";
		std::wcout << L"2 - Изменить название товара\n";
		std::wcout << L"3 - Удалить товар\n";
		std::wcout << L"4 - Изменить лимиты склада\n";
		std::wcout << L"0 - Выход\n";
		std::wcout << L"Ввод: ";
		Getline(choose);

		if (choose == L"1")
		{
			AddNewProduct();
		}
		else if (choose == L"2" && sizeSt > 0)
		{
			ChangeProductName();
		}
		else if (choose == L"3" && sizeSt > 0)
		{
			DeleteProduct();
		}
		else if (choose == L"4")
		{
			ChangeStorageLimits();
		}
		else if (choose == L"0")
		{
			std::wcout << L"Выход из редактора склада\n";
			Sleep(1500);
			break;
		}
		else
		{
			Err();
		}
	}
}

void AddNewProduct()
{
	std::wstring chooseName, chooseCount, choosePrice, choose;
	size_t count = 0;
	double price = 0;
	while (true)
	{
		while (true)
		{
			system("cls");
			std::wcout << L"введите название нового товара или \"exit\" для выхода: ";
			Getline(chooseName);
			if (chooseName == L"exit" || chooseName == L"Exit")
			{
				std::wcout << L"Отмена создания нового товара\n\n";
				Sleep(1500);
				return;
			}
			if (chooseName.size() < 3 || chooseName.size() > 40)
			{
				std::wcout << L"Ошибка длины названия товара \nДопустимое значение от 3 до 40 символов\n\n";
				Sleep(1500);
				continue;
			}
			if (IsNotSame(chooseName, nameArr, sizeSt))
			{
				break;
			}
			else
			{
				std::wcout << L"Такой товар уже есть на складе";
				Sleep(1500);
			}

		}

		while (true)
		{
			system("cls");
			std::wcout << L"введите количество нового товара или \"exit\" для выхода: ";
			Getline(chooseCount);
			if (chooseCount == L"exit" || chooseCount == L"Exit")
			{
				std::wcout << L"Отмена создания нового товара\n\n";
				Sleep(1500);
				return;
			}
			if (IsNumber(chooseCount))
			{
				
				count = std::stoull(chooseCount);
				if (count < 0 || count > MaxStorageSize - CurrentStorageSize)
				{
					std::wcout << L"Неккоректное кол-во! На складе осталось "
						<< MaxStorageSize - CurrentStorageSize << L" свободных мест\n\n";
					Sleep(1700);
				}
				else
				{
					break;
				}
			}
		}

		while (true)
		{
			system("cls");
			std::wcout << L"введите стоимость нового товара или \"exit\" для выхода: ";
			Getline(choosePrice);
			if (choosePrice == L"exit" || choosePrice == L"Exit")
			{
				std::wcout << L"Отмена изменения цены\n\n";
				Sleep(1500);
				return;
			}
			if (IsNumber(choosePrice))
			{
				price = std::stod(choosePrice);

				if (price < 0 || price > MaxPrice)
				{
					std::wcout << L"Неккоректная цена! Максимально возможная цена: " 
						<< MaxPrice << L" рублей\n\n";
					Sleep(1700);
				}
				else
				{
					break;
				}
			}
		}

		while (true)
		{
			system("cls");
			std::wcout << L"Новый товар: " << chooseName << L"\n";
			std::wcout << L"Кол-во: " << count << L"\n";
			std::wcout << L"Цена: " << price << L"\n";
			std::wcout << L"Подтвердить?\n1 - Да\n2 - Нет\n\nВвод: ";
			Getline(choose);

			if (choose == L"1")
			{
				std::wcout << L"Расширение склада";
				for (size_t i = 0; i < 5; i++)
				{
					Sleep(400);
					std::wcout << L" .";
				}
				Sleep(500);
				ArrPushBack(idArr, sizeSt);
				ArrPushBack(nameArr, sizeSt);
				ArrPushBack(countArr, sizeSt);
				ArrPushBack(priceArr, sizeSt);
				sizeSt++;
				idArr[sizeSt - 1] = sizeSt;
				nameArr[sizeSt - 1] = chooseName;
				countArr[sizeSt - 1] = count;
				priceArr[sizeSt - 1] = price;
				CurrentStorageSize += count;
				std::wcout << L"Товар успешно добавлен!\n\n";
				Sleep(1500);
				break;



			}
			else if (choose == L"2")
			{
				std::wcout << L"Отмена\n";
				Sleep(1500);
				break;
			}

		}
	}
}

void ChangeProductName()
{

	{
		std::wstring chooseId, chooseName, choose;
		ShowStorage(2);

		while (true)
		{
			ShowStorage();
			std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
			Getline(chooseId);
			if (chooseId == L"exit" || chooseId == L"Exit")
			{
				std::wcout << L"Завершение операции переименования товара\n\n";
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
					std::wcout << L"Введите новое название для товара: ";
					Getline(chooseName);
					if (chooseName.size() < 3 || chooseName.size() > 40)
					{
						std::wcout << L"Ошибка длины названия товара \nДопустимое значение от 3 до 40 символов\n\n";
						Sleep(1500);
						continue;
					}
					if (!IsNotSame(chooseName, nameArr, sizeSt))
					{
						std::wcout << L"Такой товар уже есть на складе";
						Sleep(1500);
					}
					else
					{

						while (true)
						{
							system("cls");
							std::wcout << nameArr[id] << L"\t" << chooseName << L"\n\n";
							std::wcout << L"Подтвердить?\n1 - да\n2 - нет\n\nВвод: ";
							Getline(choose);
							if (choose == L"1")
							{
								std::wcout << L"Товар успешно переименован. Красава!\n\n";
								nameArr[id] = chooseName;
								Sleep(1500);
								break;
							}
							else if (choose == L"2")
							{
								std::wcout << L"отмена переименования товара, Вась " << nameArr[id] << L"\n";
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

void DeleteProduct()
{
	std::wstring chooseId, pass;

	while (true)
	{
		ShowStorage(5);
		std::wcout << L"Введите ID товара или \"exit\" для выхода: ";
		Getline(chooseId);
		if (chooseId == L"exit" || chooseId == L"Exit")
		{
			std::wcout << L"Завершение операции удаления товара\n\n";
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
				std::wcout << L"Подтвердите удаление товара: " << nameArr[id] << L"\nВведите пароль супер администратора";
				Getline(pass);
				if (pass == passArr[0])
				{
					std::wcout << L"Удаление товара: ";
					for (size_t i = 0; i < 5; i++)
					{
						Sleep(400);
						std::wcout << L" .";
					}
					CurrentStorageSize -= countArr[id];
					Sleep(400);
					ArrDeleteByIndex(idArr, sizeSt, id);
					ArrDeleteByIndex(nameArr, sizeSt, id);
					ArrDeleteByIndex(countArr, sizeSt, id);
					ArrDeleteByIndex(priceArr, sizeSt, id);
					sizeSt--;

					for (size_t i = 0; i < sizeSt; i++)
					{
						idArr[i] = i + 1;
					}
					 
					
					std::wcout << L"Товар успешно удален\n\n";
					Sleep(1500);
					if (sizeSt < 1)
					{
						std::wcout << L"Вы удалили весь склад, емаё Васян ты че делаешь?????!?!?!?";
						Sleep(1500);
						return;
					}
					continue;

				}
				else
				{
					Err();
				}
			}
		}

	}
}

void ChangeStorageLimits()
{
	std::wcout << L"\n\nВ процессе выполнения ";

}






