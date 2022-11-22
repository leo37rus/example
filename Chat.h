#pragma once
#include<vector>
#include<exception>
#include<memory>
#include"Message.h"

class Chat {
	bool isChatWork_ = false;
	std::vector<User> users_;
	std::vector<Message> messages_;
	std::shared_ptr<User> currentUser_ = nullptr;

	//constructor(through the initialization string?)
	//getMessages_
	//getUsers_
	//getCurrentUser_
public:
	//start??
};

