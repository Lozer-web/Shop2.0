#include "accounts.hpp"

size_t usersize = 3;
size_t currentid = 0;
std::wstring currentstatus;

std::wstring* loginArr = new std::wstring[usersize]{L"Swarznigga", L"Smaev", L"Laid"};
std::wstring* passArr = new std::wstring[usersize]{ L"superkoch", L"9september", L"2010legend" };
std::wstring* statusArr = new std::wstring[usersize]{ L"Superadmin", L"Liladmin", L"Justdude" };
size_t* useridArr = new size_t[usersize]{0, 1, 2};
 