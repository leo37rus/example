#pragma once
#include "User.h"

class Message
{
	const std::string _from;//откуда
	const std::string _to;// кому
	const std::string _text;//текст

public:
	Message(const std::string& from, const std::string& to, const std::string& text)
		:_from(from), _to(to), _text(text) {}

	const std::string& get_From() { return _from; }
	const std::string& get_To() { return _to; }
	const std::string& get_Text() { return _text; }

};
