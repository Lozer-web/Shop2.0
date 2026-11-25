#include "accounts.hpp"

size_t usersize = 3;
size_t currentid = 0;
std::wstring currentstatus;

std::wstring* loginArr = new std::wstring[usersize]{L"Swarznigga", L"Smaev", L"Laid"};
std::wstring* passArr = new std::wstring[usersize]{ L"superkoch", L"9september", L"2010legend" };
std::wstring* statusArr = new std::wstring[usersize]{ L"Superadmin", L"Liladmin", L"Justdude" };
size_t* useridArr = new size_t[usersize]{0, 1, 2};

size_t maxLogin = 15;
size_t minLogin = 5;
size_t maxPass = 13;
size_t minPass = 8;

std::unordered_set<wchar_t> loginSymbols;
std::unordered_set<wchar_t> passSymbols;


void ChangeAccs()
{
	while (true)
	{
		std::wstring choose;
		system("cls");
		std::wcout << L"\n\n\t\t\tРедактор учетных записей \"Горила-Варила\"\n\n";
		std::wcout << L"1 - Создать новый аккаунт\n";
		std::wcout << L"2 - Показать всех сотрудников\n";
		std::wcout << L"3 - Изменить пароль\n";
		std::wcout << L"4 - Изменить уровни доступа\n";
		std::wcout << L"5 - Редактировать премии и штрафов сотрудинков\n";
		std::wcout << L"6 - Удалить аккаунт\n";
		std::wcout << L"0 - Выход\n";
		std::wcout << L"Ввод: ";
		Getline(choose);

		if (choose == L"1")
		{

		}
		else if (choose == L"2")
		{

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

void CreateNewAcc()
{
	std::wstring chooseLogin, choosePass, chooseStatus, choose;
}
