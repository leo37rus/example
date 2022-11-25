#pragma once
#include <string>
class User
{
	std::string login_;
	std::string password_;
	std::string name_;

public:
	User( const std::string &login, const std::string& password, const std::string& name)
		:login_(login), password_(password), name_(name) {}

	const std::string& get_user_login() { return login_; }
	const std::string& getUserPassword() { return password_; }
	void setUserPassword(const std::string& password) { password_ = password; }
	const std::string& getUserName() { return name_; }
	void setUserName(const std::string& name) { name_ = name; }
};
