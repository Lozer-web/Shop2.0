#include "authorise.hpp"

void Start()
{
	while (true)
	{
		if (Login())
		{
			if (currentstatus == L"Superadmin")
			{
				CreateStorage();
				SwarzniggaMenu();
			}
			else if (currentstatus == L"Liladmin")
			{
				//todo
			}
			else if (currentstatus == L"Justdude")
			{
				//todo
			}
			else
			{
				std::wcerr << L"\n\nCURRENT_STATUS_LOGIN_ERROR";
			}
		}
		else
		{
			
		}
	}

}
bool Login()
{
	std::wstring login, pass;
	while (true)
	{
		system("cls");
		std::wcout << L"==============================" << std::endl;
		std::wcout << L"========Горилла-Варила========" << std::endl;
		std::wcout << L"==============================" << std::endl;
		std::wcout << L"Введите логин или \"exit\" для выхода: ";
		Getline(login);
		if (login == L"exit" || login == L"Exit")
		{
			return false;
		}
		else
		{
			std::wcout << L"Введите пароль: ";
			Getline(pass);
			for (size_t i = 0; i < usersize; i++)
			{
				if (login == loginArr[i] && pass == passArr[i])
				{
					std::wcout << L"Добро пожаловать! " << loginArr[i] << L"\n";
					std::wcout << L"Ваш уровень доступа: " << statusArr[i] << L"\n";
					currentid = useridArr[i];
					currentstatus = statusArr[i];
					Sleep(1500);
					return true;
				}
			}
			std::wcout << L"Неверный лоигн или пароль. Повторите попытку\n\n";
			Sleep(1500);
		}
	}
}

void SwarzniggaMenu()
{
	std::wstring choose;

	while (true)
	{
		system("cls");

		std::wcout << L"1 - Начать продажу\n";
		std::wcout << L"2 - Показать склад\n";
		std::wcout << L"3 - Пополнить товары\n";
		std::wcout << L"4 - Списать товары\n";
		std::wcout << L"5 - Изменить цены\n";
		std::wcout << L"6 - Редактировать склад\n";
		std::wcout << L"7 - Редактировать сотрудников\n";
		std::wcout << L"8 - Редактировать сотрудников\n";
		std::wcout << L"9 - Показать прибыль\n";
		std::wcout << L"0 - Выход\n";
		Getline(choose);

		if (choose == L"1")
		{

		}
		else if (choose == L"2")
		{
			ShowStorage();
		}
		else if (choose == L"3")
		{

		}
		else if (choose == L"4")
		{

		}
		else if (choose == L"5")
		{

		}
		else if (choose == L"6")
		{

		}
		else if (choose == L"7")
		{

		}
		else if (choose == L"8")
		{

		}
		else if (choose == L"9")
		{

		}
		else if (choose == L"0")
		{

		}
		else
		{
			Err();
		}
	}
}
