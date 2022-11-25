#include <iostream>
#include "ChatCrab.h"

void Chat::start()
{
    workChat_ = true;
}

std::shared_ptr<User> Chat::get_user_by_login(const std::string& login) const
{
    for (auto& user : users_)
    {
        if (login == user.get_user_login())
            return std::make_shared<User>(user);
    }
    return nullptr;
}

std::shared_ptr <User> Chat::get_user_by_name(const std::string& name) const
{
    for (auto& user : users_)
    {
        if (name == user.getUserName())
            return std:: make_shared<User>(user);
    }
    return nullptr;
}


void Chat::show_Log_Menu() //реализовать выбор языка??
{
    currentUser_ = nullptr;
    char operation;
    {
        currentUser_ = nullptr;
        char operation;
        
        do
        {
            std::cout << "здравствуй, хочешь войти или зарегистрироваться?" << std::endl;
            std::cout << "1 - зарегистрироваться" << std::endl;
            std::cout << "2 - войти в чат" << std::endl;
            std::cout << "0 - закрыть чат" << std::endl;
            std::cin>> operation;
            //цикл
            switch (operation)
            {
                case '1':
                    reg_Chat();
                    break;
                case '2':
                    try
                {
                    log_Chat();
                }
                    catch (const std::exception &e)
                {
                    std::cout << e.what() << std::endl;
                }
                    break;
                case '0':
                    workChat_=false;
                    break;
                default:
                    std::cout << "выбери действие: 1,2,3" << std::endl;
                    break;
            }
        } while (!currentUser_ && workChat_);
    }
}
    void Chat::show_User_Menu()
        {
            char operation;
            
            std::cout << "Hi, " << currentUser_ -> getUserName() << std::endl;
            
            while (currentUser_)
            {
                std::cout << "Menu: (1) Показать сообщения | (2) Написать сообщение | (3) Пользователи | (0) Выйти";
                
                std:: cout << std::endl;
                std:: cin >> operation;
                
                switch (operation)
                {
                    case '1':
                        show_Chat();
                        break;
                    case '2':
                        add_Message();
                        break;
                    case '3':
                        show_All_Users();
                        break;
                    case'0':
                        currentUser_=nullptr;
                        break;
                    default:
                        std::cout << "Неизвестный выбор, выберите действие от 1, 2, 3, 0" << std::endl;
                        break;
                }
            }
        }

    void Chat::reg_Chat()
    {
        std::string login, password, name;
        
        std::cout << "Введите логин: ";
        std::cin >> login;
        std::cout << "Введите пароль: ";
        std::cin >> password;
        std::cout << "Введите имя: ";
        std::cin >> name;
        
        if (get_user_by_login(login)|| login == "all")
        {
            throw UserLoginExp();
        }
        if (get_user_by_name(name) || name == "all")
        {
            throw UserNameExp();
        }
        User user = User(login, password, name);
        users_ .push_back(user);
        currentUser_ = std::make_shared<User>(user);
    }
	
    void Chat::log_Chat()
    {
        std::string login, password;
        char operation;
        
        do
        {
            std::cout << "Введите логин: ";
            std::cin >> login;
            std::cout << "Введите пароль: ";
            std::cin >> password;
            
            currentUser_ = get_user_by_login(login);
            
            if (currentUser_ == nullptr || (password != currentUser_ -> getUserPassword()))
            {
                std::cout << "Неверный логин!!!" << std::endl;
                std::cout << "Нажмите (0) чтобы выйти или любую клавишу для повтора: " << std::endl;
                std::cin >> operation;
                
                if (operation == 0)
                break;
            }
        } while (!currentUser_);
        
    }
    void Chat::show_Chat() const
    {
        std::string from;
        std::string to;
        
        std::cout <<"-#-#-#-#-Чат-#-#-#-#-" << std::endl;
        
        for (auto &mess : messages_)
        {
            if(currentUser_->get_user_login() == mess.get_From() || currentUser_ -> get_user_login() == mess.get_To() || mess.get_To() == "всем")
            {
                from = (currentUser_ -> get_user_login() == mess.get_From()) ? "Я" : get_user_by_login (mess.get_From()) -> getUserName();
                
                if(mess.get_To()=="всем")
                {
                    to = "(всем)";
                }
                else
                {
                    to = (currentUser_ -> get_user_login() == mess.get_To()) ? "Я" : get_user_by_login (mess.get_To()) -> getUserName();
                }
                std::cout << "Сообщение от " << from << " кому " << to << std::endl;
                std::cout << "Текст: " << mess.get_Text() << std::endl;
            }
        }
        std::cout << "-#-#-#-#-#-#-#-#-#-#";
    }
    void Chat::show_All_Users() const
    {
        std::cout << "-#-#-#-#-Users-#-#-#-#-" << std::endl;
        for (auto& user : users_)
        {
            std::cout << user.getUserName();
            if (currentUser_->get_user_login() == user.get_user_login())
                std::cout << "(Я)";

            std::cout << std::endl;
        }
        std::cout <<"-#-#-#-#-#-#-#-#-#-#" << std::endl;
    }

    void Chat::add_Message()
        {
            std::string to, text;
            
            std::cout << "Кому (Имя пользователя или всем):";
            std::cin >> to;
            std::cout << "Текст: ";
            std:: cin.ignore();
            getline (std::cin, text);
            
            if (!(to == "всем" || get_user_by_name(to)))
            {
                std::cout << "Ошибка отправки сообщения! Пользователь " << to << " не найден!" << std::endl;
                return;
            }
            if (to == "всем")
                
                messages_.push_back (Message{currentUser_->get_user_login(), "всем", text});
                else
                    messages_.push_back (Message{currentUser_->get_user_login(), get_user_by_name(to) -> get_user_login(), text});
            }
