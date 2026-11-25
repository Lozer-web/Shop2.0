#ifndef _STORAGE_HPP_
#define _STORAGE_HPP_

#include "accounts.hpp"

extern size_t sizeSt;
extern size_t* idArr;
extern std::wstring* nameArr;
extern size_t* countArr;
extern double* priceArr;

extern bool isstoragecreated;
extern double MaxPrice;

extern size_t* supplierCountArr;//ПОСТАВЩИК ДЗ
extern double* supplierPriceArr;

extern size_t MaxStorageSize;
extern size_t CurrentStorageSize;


void CreateStorage(int mode = 0);
void ShowStorage(int mode = 0);
void FillProduct();
void RemoveProduct();
void ChangePrice();
void ShowSupplierStorage();//ПОСТАВЩИК ДЗ
void ChangeStorage();

void AddNewProduct();

void ChangeProductName();

void DeleteProduct();

void ChangeStorageLimits();

#endif // !_STORAGE_HPP_