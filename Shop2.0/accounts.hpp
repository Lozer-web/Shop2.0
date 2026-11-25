#ifndef _ACCOUNTS_HPP_
#define _ACCOUNTS_HPP_

#include "services.hpp"


extern size_t usersize;
extern size_t currentid;
extern std::wstring currentstatus;

extern std::wstring* loginArr;
extern std::wstring* passArr;
extern std::wstring* statusArr;
extern size_t* useridArr;



extern size_t maxLogin;
extern size_t minLogin;
extern size_t maxPass;
extern size_t minPass;

extern std::unordered_set<wchar_t> loginSymbols;
extern std::unordered_set<wchar_t> passSymbols;

void ChangeAccs();

void CreateNewAcc();



#endif // !_ACCOUNTS_HPP_