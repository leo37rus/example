#include <iostream>
#include "ChatCrab.h"
#include "string"
#include <stdio.h>
#include<vector>
#include<string>
#include <iostream>
using namespace std;

void login();
std::shared_ptr<User> Chat::get_user_by_login(const std::string& login) const {
	//вдресат по логину
	for (auto user : AllUsers_)// было  пишет ошибка - беспокоит &------------------------------------
		//for (User user : users_) // https://metanit.com/cpp/tutorial/7.2.php
	{
		if (login == user.get_user_login())//бежит по массиву проверяет 
			return std::make_shared<User>(user);//получаем указатель по логину
	}
	return nullptr;
}
std::shared_ptr<User> Chat::get_user_by_name(const std::string& name) const {//нужно для ошибок-----------------------------------------
	//адресат по имени, 
	for (auto user : AllUsers_)// в видео было так не компилируется -----------------------------------------
		//for (User user : users_)
	{
		if (name == user.getUserName())//бежит по массиву проверяет 
			return std::make_shared<User>(user);
	}
	return nullptr;
}
void Chat::show_login_menu() {//реализовать выбор языка??
	currentUser_ = nullptr;
	char operation;// option

	std::cout << "здравствуй, хочешь войти или зарегистрироваться?" << std::endl;
	std::cout << "1 - зарегистрироваться" << std::endl;
	std::cout << "2 - войти в чат" << std::endl;
	std::cout << "0 - закрыть чат" << std::endl;
	std::cin>> operation;
	//цикл
	switch (operation)
	{
	case '1'://регистрация
		registration_in_the_chat();
		break;
	case '2'://войти в чат
		void log_ln_to_the_chat();// вход в чат-----------
		break;
	case '0'://закрыть чат

		break;
	default:
		break;
	}
}

void Chat::registration_in_the_chat() {//регестрация
	string login;
	string password;//такое объявление не трогать в варианте через запятую не пашет -_-
	string name;
	//char operation;// option

	for (size_t i = 0; i < 4; i++) //проверочный цыкл на работоспособнось вектора AllUsers_ 
	{
	//цикл
	std::cout << "вы выбрали 1 - зарегистрироваться" << std::endl;
	std::cout << "введите ваш логин" << std::endl;
	std::cin >> login; std::cout << std::endl;
	//проверка на  занятость логина по vector<User> AllUsers_
	//если занят выдать ошибку
	std::cout << "введите ваш пороль" << std::endl;
	std::cin >> password; std::cout << std::endl;
	std::cout << "введите ваш имя" << std::endl;
	std::cin >> name; std::cout << std::endl;
	//проверка на  занятость имени по vector<User> AllUsers_
	//если занят выдать ошибку

	//std::cout << "0 - закрыть чат" << std::endl;
	//std::cin >> operation;
	

	//создание объекта юзер 
	User user=User(login, password, name);
	AllUsers_.push_back(user);//добоаление в список юзеров vector<User> AllUsers_
	//currentUser_ = std::make_shared<User>(&user);//& серый указатель на текущего пользователя
	cout << "size(AllUsers_)количество пользователей " << size(AllUsers_) << std::endl;
	}
	
	//vector::push_back	Вставка элемента в конец вектора
	// https://ru.wikipedia.org/wiki/Vector_(C%2B%2B)
	//сосладся на вход в чат(вход успешен) показать чат
	}
	
void Chat::log_ln_to_the_chat() {
	std::string login, password;
	//char operation;// option//для закрытия 

	//войти в чат
	//ввод логина
	//ввод пороля
	
	//цикл
	std::cout << "вы выбрали 2 - войти" << std::endl;
	std::cout << "введите ваш логин" << std::endl;
	std::cin >> login; std::cout << std::endl;
	std::cout << "введите ваш пороль" << std::endl;
	std::cin >> password; std::cout << std::endl;
	
	//std::cout << "0 - закрыть чат" << std::endl;
	//std::cin >> operation;

	//проерка правельности ввода по vector<User> AllUsers_
	//если не верно вывести ошибку

	//сосладся на вход в чат(вход успешен) показать чат
}

void Chat::show_chat() const {//показать чат vector::sizeВозвращает количество элементов в векторе

	//вывод чата с заменой имени текущего пользователя на (me)
	//  и проверкой что доступно текущему юзеру std::vector<Message> messages_; проверка на аll
	//проверка личных сообщениий вывод в std::vector<Message> messages_; по const std::string _to;



	//меню чата (видимо перенести в отдельное место)
	//покозать всех пользователей вывести vector<User> AllUsers_ рядом со своим именем (me) void show_all_users_name() const;
	//отправить сообщение кому-то сослаться void add_message();
	//отправить сообщение всем сослаться
	//выход 
}
void Chat::show_all_users_name() const {//покозать всех пользователей
	// получить имя текущего пользователя
	//вывод vector<User> AllUsers_ только миена
	//если имя текущего пользователя совпадает с именем из списка радом написать (me)
}
void Chat::add_message() {
	//получение имени текущего пользователя и запись в const std::string _from;//откуда
	
	//ввод кому 
	//проверка на наличее такого пользователя

	//ввод текста
	
	//создать объекта 
	//запись в std::vector<Message> messages_;
}

void Chat::CAT() {


	std::cout << "____________________________________________________" << std::endl;
	std::cout << "___________________$$____________$$" << std::endl;std::cout << "__________________$___$________$___$" << std::endl;
	std::cout << "__________________$_____$$$$$$_____$" << std::endl;std::cout << "__________________$____sss___sss____$" << std::endl;
	std::cout << "__________________$____іі_____іі_____$" << std::endl;std::cout << "_________________$_______$$$________$" << std::endl;
	std::cout << "_____$$$$$$$$_____$_______$________$" << std::endl;std::cout << "___$$________$_______$$_________$$" << std::endl;
	std::cout << "____$_________$_____$___$$$$$$___$" << std::endl;std::cout << "_______$______$____$__$________$__$" << std::endl;
	std::cout << "_______$_____$____$__$__________$__$" << std::endl;std::cout << "______$____$___$$$$__$__________$__$$$$" << std::endl;
	std::cout << "_____$___$____$____$__$________$___$___$" << std::endl;std::cout << "_____$__$_____$____$__$________$__$____$" << std::endl;
	std::cout << "____$___$______$____$__$____$_$__$____$" << std::endl;std::cout << "______$__$______$____$___$_$_____$___$" << std::endl;
	std::cout << "_______$___$$$$$_$___$___$_$____$___$" << std::endl;std::cout << "__________$$$$$_$____$____$_____$____$" << std::endl;
	std::cout << "________________$$$_$_____$______$_$$$" << std::endl;std::cout << "_____________________$$$$___$$$$$" << std::endl;
	std::cout << "____________________________________________________" << std::endl << std::endl;std::cout << "__________не_расстаивайся_пробуй_еще_раз_________" << std::endl;
std::cout << "____________________________________________________" << std::endl;
}
