#pragma once
#include<vector>
#include<exception>
#include"Message.h"
#include"User.h"

class Chat
{
	bool workChat_ = false; //WorkChat_ isChatWork_
	std::vector<User> users_;// users_ AllUsers_
	std::vector<Message> messages_;
	std::shared_ptr<User> currentUser_ = nullptr; //текущий пользователь

	void reg_Chat();//регистрация в чате
	void log_Chat();// вход в чат
	void show_Chat() const;//показать чат
	void show_All_Users() const;// показать всех пользователей
	void add_Message();//добавить сообщение

	std::vector<User>& get_All_Users() { return users_; }//получить список пользователей
	std::vector<Message>& get_All_Messages() { return messages_; }// получить все сообщения
	std::shared_ptr<User> get_user_by_login(const std::string& login) const;//геттер логина активного пользователя
	std::shared_ptr<User> get_user_by_name(const std::string& name) const;//геттер имени активного пользователя
public:
	void start() {workChat_ = true;}
	bool workChat() const { return workChat_; }
	std::shared_ptr<User> getCurrentUser() const { return currentUser_; }
	void show_login_menu();
	void showUserMenu();

};
