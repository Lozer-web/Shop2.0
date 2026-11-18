#ifndef _STORAGE_HPP_
#define _STORAGE_HPP_
#include "services.hpp"

extern size_t sizeSt;
extern size_t* idArr;
extern std::wstring* nameArr;
extern size_t* countArr;
extern double* priceArr;

extern bool isstoragecreated;
extern double MaxPrice;

extern size_t MaxStorageSize;
extern size_t CurrentStorageSize;
void CreateStorage(int mode = 0);
void ShowStorage(int mode = 0);
void FillProduct();

void RemoveProduct();

void ChangePrice();

#endif // !_STORAGE_HPP_