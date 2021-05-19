#ifndef MARKET_ON_WHEELS_MENU_H
#define MARKET_ON_WHEELS_MENU_H

#include "../Application.h"
#include "../gui/GUI.h"
#include "../graph/Node.h"

#define CLR_SCREEN "\033[2J\033[1;1H"

class Menu{
protected:
    Application &application;

    Menu * invalidOption();
public:
    explicit Menu(Application &application);
    virtual ~Menu() = default;
    /**
     * Show information associated with the menu
     */
    virtual void show() = 0;
    /**
     * Return a pointer to the next menu ('nullptr' and 'this' can also be returned)
     * nullptr -> Return to previous menu
     * this -> Don't change the menu
     * @return Menu * to next menu
     */
    virtual Menu * getNextMenu() = 0;
};

class MainMenu : public Menu {
    void showLogo();
public:
    explicit MainMenu(Application &application);
    void show() override;
    Menu * getNextMenu() override;
};

class GraphMenu : public Menu {
    GUI gui;
public:
    explicit GraphMenu(Application &application);
    void show() override;
    Menu * getNextMenu() override;
};

class MapMenu : public Menu {
public:
    explicit MapMenu(Application &application);
    void show() override;
    Menu * getNextMenu() override;
};

#endif //MARKET_ON_WHEELS_MENU_H
