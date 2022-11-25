#include <iostream>
#include "ChatCrab.h"


int main() {
	setlocale(LC_ALL, "ru");
	
	//цикл пока чат работает
	Chat chat;//создание объекта чат
	chat.start(); // startAChat
	chat.show_login_menu();

	return 0;
}
