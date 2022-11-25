#include <iostream>
#include "ChatCrab.h"


int main() {
	//setlocale(LC_ALL, "ru"); мой xcode не знает что это такое
	Chat chat;
    chat.start();
    
    while (chat.workChat())
    {
        chat.show_Log_Menu();
        
        while (chat.get_Current_User())
        {
            chat.show_User_Menu();
        }
    }
    return 0;
}
