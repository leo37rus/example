#include <iostream>
#include "ChatCrab.h"


int main() {
	setlocale(LC_ALL, "ru");
	
	Chat chat;//создание объекта чат
	chat.start(); // startAChat
	chat.show_login_menu();

	return 0;
}
