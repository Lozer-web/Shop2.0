#include "authorise.hpp"

void Start()
{
	while (true)
	{
		if (Login())
		{
			system("pause");
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
					return true;
				}
			}
			std::wcout << L"Неверный лоигн или пароль. Повторите попытку\n\n";
			Sleep(1500);
		}
	}
}
