#include "Menu.h"
#include <windows.h>
#include <cstdio>
#include <iostream>
#include <string>
#include <cstdio>
	
page* Menu::testPage(page* aux,std::wstring nombre) {

	//page* home = aux;

	while (aux->next != nullptr) {
		aux = aux->next;
	}

	page* nova = new page;
	aux->next = nova;
	nova->name = nombre;
	nova->last = aux;
	nova->next = nullptr;
	siteAtual = nova;
	return siteAtual;
}

	short Menu::invoke(page* aux) {
		short choice = 10;
		while (choice < 0 or choice > 9) {
			system("CLS");
			std::wcout << L"\n\t Endereço Atual: " << aux->name;
			if (aux->isFav == TRUE) { std::wcout << L" ★\n\t " << std::endl; } else { std::wcout << "\n\t" << std::endl; }
			std::wcout << L"\n\t\t 1 - Novo Site. \n\t\t 2 - Site Anterior. \n\t\t 3 - Próximo Site \n\t\t 4 - Excluir Site Atual. \n\t\t 5 - Mostrar Histórico. \n\t\t 6 - Adicionar aos Favoritos. \n\t\t 7 - Acessar Próximo Favorito. \n\t\t 8 - Remover Favoritos. \n\t\t 9 - Listar Favoritos. \n\t\t 0 - Sair. " << std::endl;
			std::wcin >> choice;
			if (choice < 0 or choice > 9) { std::wcout << "\n\t Opção inválida de menu. \n\t" << std::endl; }
		}
		std::cin.ignore();
		return choice;
	}

	page* Menu::newPage(page* aux) {
		std::wstring site;
		system("CLS");
		std::wcout << L"\n\t\t Digite o endereço da página que deseja acessar.\n" << std::endl;
		std::getline(std::wcin, site);

		//page* home = aux;

		while (aux->next != nullptr) {
			aux = aux->next;
			}

		page* nova = new page;
		aux->next = nova;
		nova->name = site;
		nova->last = aux;
		nova->next = nullptr;
		system("CLS");
		siteAtual = nova;
		return siteAtual;
	}

	page* Menu::removePage(page* aux)
	{
		if (siteAtual->name != L"Home.com") {
			short choice = 3;
			system("CLS");
			std::wcout << "\n\t Site atual: " << siteAtual->name << std::endl;
			std::wcout << " \n\t Deseja excluir a página atual? \n" << std::endl;
			while (choice != 1 and choice != 2) {
				std::wcout << "\n\t 1 - Sim. \n\t 2 - Não. \n\t" << std::endl;
				std::wcin >> choice;
			}
			std::cin.ignore();
			switch (choice) {
			case 1:
				while (aux->name != siteAtual->name) {
					aux = aux->next;
				}
				if (aux->next != nullptr) {
					aux->last->next = aux->next;
					aux->next->last = aux->last;
					siteAtual = aux->next;
					free(aux);
					return siteAtual;
					break;
				}
				else {
					aux->last->next = nullptr;
					siteAtual = aux->last;
					free(aux);
					siteAtual->name;
				}
			case 2:
				return siteAtual;
				break;
			}
		}
		else {
			system("CLS");
			std::wcout << "\n\t Não é possível excluir a página inicial. \n" << std::endl;
			Sleep(1023);
		}
		return siteAtual;
	}

	page* Menu::lastPage(page* aux) {
		if (aux->last != nullptr) {
			siteAtual = aux->last;
			return siteAtual;
		}
		else {
			system("CLS");
			std::wcout << "\n\t Não existe site anterior. \n" << std::endl;
			Sleep(1024);
			return siteAtual;
		}
	}

	page* Menu::nextPage(page* aux) {
		if (aux->next != nullptr) {
			siteAtual = aux->next;
			return siteAtual;
		}
		else {
			system("CLS");
			std::wcout << "\n\t Não existe próximo site. \n" << std::endl;
			Sleep(1024);
			return siteAtual;
		}
	}
	

	page* Menu::printHistory(page* aux) {
		system("CLS");
		std::wcout << "\n\t " << aux->name << ". \n\t";
		while (aux->next != nullptr) {
			aux = aux->next;
			std::wcout << "\n\t " << aux->name << ". \n\t";
		} 
		std::wcout << std::endl;
		system("PAUSE");
		return siteAtual;
	}
	
	page* Menu::addFavorite(page* aux, page* ret, page* froot) {
		system("CLS");
		if (aux->name == L"Home.com") {
			std::wcout << "\n\t A página inicial não pode ser adicionada aos favoritos." << std::endl;
			Sleep(1024);
			return aux;
		} else if (aux->isFav == TRUE) {
			std::wcout << "\n\t A página ja é favorita." << std::endl;
			Sleep(1024);
			return aux;
		} else {
			if (ret->name == L"\0") {
				ret->name = aux->name;
				ret->isFav = TRUE;
				aux->isFav = TRUE;
				ret->last = nullptr;
				ret->next = nullptr;
				return siteAtual;
			} else {
				ret = froot;
				while (ret->next != nullptr) {
					ret = ret->next;
				}
				ret->next = new page();
				ret->next->name = aux->name;
				ret->next->last = ret;
				ret->next->next = nullptr;
				ret->next->isFav = TRUE;
				aux->isFav = TRUE;
				return siteAtual;
			}
		}
	}

	page* Menu::nextFavorite(page* aux, page* ret, page* root, page* froot) {
		system("CLS");
		if (froot->name == L"\0") {
			std::wcout << "\n\t Não ha favoritos." << std::endl;
			Sleep(1024);
			return siteAtual;
		} else {
			if (siteAtual->isFav == FALSE) {
				aux = root;
				ret = froot;
				while (aux->name != ret->name) {
					aux = aux->next;
				}
				siteAtual = aux;
				return siteAtual;
			} else {
				ret = froot;
				while (ret->name != aux->name) {
					ret = ret->next;
				}
				if (ret->next == nullptr) {
					std::wcout << "\n\t Não há próximo favorito." << std::endl;
					Sleep(1024);
					return siteAtual;
				} else {
					ret = ret->next;
					aux = root;
					while (aux->name != ret->name) {
						aux = aux->next;
					}
					siteAtual = aux;
					return aux;
				}
			}
		}
	}

	page* Menu::removeFavorite(page* aux, page* ret, page* root, page* froot) {
		system("CLS");
			if (aux->isFav == FALSE) {
				std::wcout << "\n\t O site não é um favorito." << std::endl;
				Sleep(1024);
				return siteAtual;
			} else {
				aux->isFav = FALSE;
				ret = froot;
				while (ret->name != aux->name) {
					ret = ret->next;
				}
				if (ret->last == nullptr) {
					if (ret->next == nullptr) {
						ret->next = nullptr;
						ret->last = nullptr;
						ret->name = L"\0";
						ret->isFav = FALSE;
						aux->isFav = FALSE;
						return siteAtual;
					}
				} else if(ret->next == nullptr) {
					ret->isFav = FALSE;
					aux->isFav = FALSE;
					ret->last->next = nullptr;
					free(ret);
					ret = froot;
					return siteAtual;
				} else {
					aux->isFav = FALSE;
					ret->isFav = FALSE;
					ret->last->next = ret->next;
					ret->next->last = ret->last;
					free(ret);
					ret = froot;
					return siteAtual;
				}
			}		
	}

	page* Menu::printFavorite(page* aux,page* ret) {
		system("CLS");
		if (ret->name != L"\0") {			
				std::wcout << "\n\t " << ret->name << std::endl;
				while (ret->next != nullptr) {
					ret = ret->next;
					std::wcout << "\n\t " << ret->name << std::endl;
				}
				std::wcout << "\n" << std::endl;
				system("PAUSE");
				return siteAtual;
		} else {
			std::wcout << "\n\t Não há favoritos." << std::endl;
			Sleep(1023);
			return siteAtual;
		}
	}

