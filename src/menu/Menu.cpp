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
    std::cout << "[" << ++options << "] " << "Map Selector\n";
    std::cout << "\n[0] Exit\n";
}
Menu * MainMenu::getNextMenu() {
    int option;
    if(!get(option)){
        return invalidOption();
    }
    switch(option){
        case 0: return nullptr;
        case 1: return new GraphMenu(application);
        case 2: return new MapMenu(application);
    }
    return invalidOption();
}

// --------------- Graph Menu ---------------

GraphMenu::GraphMenu(Application &application) : Menu(application), gui(GUI(&application.getGraph(), 400, 400)) {}

void GraphMenu::show() {
    unsigned int options = 0;

    std::cout << CLR_SCREEN;

    std::cout << "Graph Menu:\n\n";
    std::cout << "[" << ++options << "] " << "Change Center Node\n";
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
        case 1: return new CenterMenu(application);
        case 2: return this;
        case 3: gui.show(application.getCenterId()); break;
        case 4: gui.showPaths(application.getCenterId(), application.shortestPath());
        case 5: return this;
        case 6: return this;
        case 7: return this;
        default: return invalidOption();
    }
    return this;
}

// --------------- Map Menu ---------------

MapMenu::MapMenu(Application &application) : Menu(application) {}
void MapMenu::show() {
    unsigned int options = 0;

    std::cout << CLR_SCREEN;

    std::cout << "Map Menu:\n\nSelect a map:\n\n";
    std::cout << "[" << ++options << "] " << "Espinho Full\n";
    std::cout << "[" << ++options << "] " << "Espinho Strong\n";
    std::cout << "[" << ++options << "] " << "Penafiel Full\n";
    std::cout << "[" << ++options << "] " << "Penafiel Strong\n";
    std::cout << "[" << ++options << "] " << "Porto Full\n";
    std::cout << "[" << ++options << "] " << "Porto Strong\n";
    std::cout << "[" << ++options << "] " << "Grid 4x4\n";
    std::cout << "[" << ++options << "] " << "Grid 8x8\n";
    std::cout << "[" << ++options << "] " << "Grid 16x16\n";
    std::cout << "\n[0] Exit\n";
}
Menu * MapMenu::getNextMenu() {
    int option;
    if(!get(option)){
        return invalidOption();
    }
    std::string map;
    switch(option){
        case 0: return nullptr;
        case 1: map = "espinho_full"; break;
        case 2: map = "espinho_strong"; break;
        case 3: map = "penafiel_full"; break;
        case 4: map = "penafiel_strong"; break;
        case 5: map = "porto_full"; break;
        case 6: map = "porto_strong"; break;
        case 7: map = "other/GridGraphs/4x4"; break;
        case 8: map = "other/GridGraphs/8x8"; break;
        case 9: map = "other/GridGraphs/16x16"; break;
        default: return invalidOption();
    }
    application.setMap(map);
    std::cout << "Map changed successfully\n";
    waitEnter();
    return nullptr;
}

// --------------- Center Menu ---------------

CenterMenu::CenterMenu(Application &application) : Menu(application) {}
void CenterMenu::show() {
    std::cout << CLR_SCREEN;

    std::cout << "Select the node that contains the center:\n\n";
}
Menu * CenterMenu::getNextMenu() {
    int option;
    if(!get(option) || option < 0){
        return invalidOption();
    }

    application.setCenterId(option);
    std::cout << "Center changed successfully to node " << option << std::endl;
    waitEnter();
    return nullptr;
}
