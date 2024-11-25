#include "Menu.h"
#include <iostream>
#include <cstdio>
#include <windows.h>
#include <locale.h>
#include <codecvt>
#include <string>

Menu menu;

int main() {

	// Set UTF_8

	std::setlocale(LC_ALL, "en_US.UTF-8");
	SetConsoleOutputCP(CP_UTF8);
	SetConsoleCP(CP_UTF8);

	// Set UTF_8

	page* home = new page();
	page* fav = new page();
	home->next = nullptr;
	home->last = nullptr;
	home->name = L"Home.com";
	home->isFav = FALSE;
	fav->next = nullptr;
	fav->last = nullptr;
	fav->name = L"\0";
	fav->isFav = FALSE;
	short temp;
	menu.fav = fav;
	menu.siteAtual = home;

	// VALORES INCLUIDOS PARA TESTE, 9 SITES.

	/*menu.testPage(home, L"A1");
	menu.testPage(home, L"B2");
	menu.testPage(home, L"C3");
	menu.testPage(home, L"D4");
	menu.testPage(home, L"E5");
	menu.testPage(home, L"F6");
	menu.testPage(home, L"G7");
	temp = menu.invoke(menu.testPage(home, L"H8"));*/

	// COMENTAR PARA NÃO TESTAR.
	menu.fav->name = L"\0";
	home->name = L"Home.com";
	temp = menu.invoke(home);
	do {
		switch (temp) {
		case 1:
			temp = menu.invoke(menu.newPage(home));
			break;
		case 2:
			temp = menu.invoke(menu.lastPage(menu.siteAtual));
			break;
		case 3:
			temp = menu.invoke(menu.nextPage(menu.siteAtual));
			break;
		case 4:
			temp = menu.invoke(menu.removePage(home));
			break;
		case 5:
			temp = menu.invoke(menu.printHistory(home));
			break;
		case 6:
			temp = menu.invoke(menu.addFavorite(menu.siteAtual, menu.fav, fav));
			break;
		case 7:
			temp = menu.invoke(menu.nextFavorite(menu.siteAtual, menu.fav, home, fav));
			break;
		case 8:
			temp = menu.invoke(menu.removeFavorite(menu.siteAtual,menu.fav,home, fav));
			break;
		case 9:
			temp = menu.invoke(menu.printFavorite(menu.siteAtual, fav));
			break;
		case 0:
			return 0;
			break;
		}
	} while (temp != 0);
	return 0;
}