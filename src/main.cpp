#include "menu/Menu.h"
#include <iostream>
#include <stack>

int main() {
    std::cout << std::left;
    Application application;
    std::stack<Menu *> menus;
    menus.push(new MainMenu(application));

    while (!menus.empty()) {
        menus.top()->show();
        Menu * ptr = menus.top()->getNextMenu();
        if(ptr){
            if(ptr != menus.top()){
                menus.push(ptr);
            }
        }
        else{
            delete menus.top();
            menus.pop();
        }
    }
    return 0;
}
