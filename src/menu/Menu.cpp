#include "Menu.h"
#include "../util/Input.h"

Menu::Menu(Application &application) : application(application) {}

Menu * Menu::invalidOption() {
    std::cout << "Invalid option" << std::endl;
    waitEnter();
    return this;
}

// --------------- Main Menu ---------------

void MainMenu::showLogo() {
    std::cout << "\n"
                 "  __  __            _        _      ____        \n"
                 " |  \\/  |          | |      | |    / __ \\       \n"
                 " | \\  / | __ _ _ __| | _____| |_  | |  | |_ __  \n"
                 " | |\\/| |/ _` | '__| |/ / _ \\ __| | |  | | '_ \\ \n"
                 " | |  | | (_| | |  |   <  __/ |_  | |__| | | | |\n"
                 " |_|  |_|\\__,_|_|  |_|\\_\\___|\\__|  \\____/|_| |_|\n"
                 " \\ \\        / / |             | |               \n"
                 "  \\ \\  /\\  / /| |__   ___  ___| |___            \n"
                 "   \\ \\/  \\/ / | '_ \\ / _ \\/ _ \\ / __|           \n"
                 "    \\  /\\  /  | | | |  __/  __/ \\__ \\           \n"
                 "     \\/  \\/   |_| |_|\\___|\\___|_|___/           \n"
                 "                                                \n"
                 "                                                \n"
                 "";
}

MainMenu::MainMenu(Application &application) : Menu(application) {}
void MainMenu::show() {
    unsigned int options = 0;

    std::cout << CLR_SCREEN;
    showLogo();

    std::cout << "Main Menu:\n\n";
    std::cout << "[" << ++options << "] " << "Graph Visualisation\n";
    std::cout << "\n[0] Exit\n";
}
Menu * MainMenu::getNextMenu() {
    int option;
    if(!get(option)){
        return invalidOption();
    }
    switch(option){
        case 0: return nullptr;
        case 1: return this;
    }
    return invalidOption();
}

// --------------- Main Menu ---------------

GraphMenu::GraphMenu(Application &application) : Menu(application) {}
void GraphMenu::show() {
    unsigned int options = 0;

    std::cout << CLR_SCREEN;

    std::cout << "Graph Menu:\n\n";
    std::cout << "[" << ++options << "] " << "Change Type of Graph\n";
    std::cout << "[" << ++options << "] " << "Change Origin Point\n";
    std::cout << "[" << ++options << "] " << "Show Current POI'S\n";
    std::cout << "[" << ++options << "] " << "Show Full Graph\n";
    std::cout << "[" << ++options << "] " << "Show Shortest Path\n";
    std::cout << "[" << ++options << "] " << "Show Path with Latest Departure Time\n";
    std::cout << "[" << ++options << "] " << "Show Connectivity\n";
    std::cout << "[" << ++options << "] " << "Show Connectivity from Origin\n";
    std::cout << "\n[0] Exit\n";
}
Menu * GraphMenu::getNextMenu() {
    int option;
    if(!get(option)){
        return invalidOption();
    }
    switch(option){
        case 0: return nullptr;
        case 1: return this;
        case 2: return this;
        case 3: return this;
        case 4: return this;
        case 5: return this;
        case 6: return this;
        case 7: return this;
        case 8: return this;
    }
    return invalidOption();
}