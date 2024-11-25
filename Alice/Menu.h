#pragma once
#include <cstdio>
#include <iostream>
#include <string>
#include <windows.h>

struct page {
	std::wstring name;
	page* last = nullptr;
	page* next = nullptr;
	bool isFav = FALSE;
};

class Menu
{
public:
	page* siteAtual;

	page* fav;

	short invoke(page* aux);

	page* testPage(page* aux, std::wstring nombre);

	//std::wstring newPage(page* aux);

	page* lastPage(page* aux);

	page* nextPage(page* aux);

	page* newPage(struct page* aux);

	page* removePage(page* aux);

	page* printHistory(page* aux);

	page* addFavorite(page* aux,page* ret, page* froot);

	page* nextFavorite(page* aux, page* ret, page* root, page* froot);

	page* removeFavorite(page*aux, page* ret,page* root, page* froot);

	page* printFavorite(page* aux, page* froot);

};

