#ifndef MARKET_ON_WHEELS_MENU_H
#define MARKET_ON_WHEELS_MENU_H

#include <stdlib.h>
#include "../Application.h"
#include "../gui/GUI.h"
#include "../graph/Node.h"

#ifdef __linux__
    #define CLR_SCREEN "\033[2J\033[1;1H"
#elif _WIN32
    #define CLR_SCREEN "\n"
#else
    #define CLR_SCREEN "\033[2J\033[1;1H"
#endif

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

    /**
     * Show project title
     */
    void showLogo();

public:

    /**
     * Constructor
     * @param application - instance of Application
     */
    explicit MainMenu(Application &application);

    /**
     * Show main menu options
     */
    void show() override;

    /**
     * Gets the next menu
     * @return Menu to be opened
     */
    Menu * getNextMenu() override;

};

class GraphMenu : public Menu {

    GUI gui;

public:

    /**
     * Constructor
     * @param application - instance of Application
     */
    explicit GraphMenu(Application &application);

    /**
     * Show graph menu
     */
    void show() override;

    /**
     * Gets next menu
     * @return menu to be opened
     */
    Menu * getNextMenu() override;

};

class MapMenu : public Menu {
public:

    /**
     * Constructor
     * @param application - instance of Application
     */
    explicit MapMenu(Application &application);

    /**
     * Show map menu
     */
    void show() override;

    /**
     * Gets next menu
     * @return Menu to be opened
     */
    Menu * getNextMenu() override;

};

class CenterMenu : public Menu {

    GUI &gui;

public:

    /**
     * Constructor
     * @param application - instance of Application
     * @param gui - instance of GUI
     */
    explicit CenterMenu(Application &application, GUI &gui);

    /**
     * Show center menu
     */
    void show() override;

    /**
     * Changes center
     * @return Menu to be opened
     */
    Menu * getNextMenu() override;

};

#endif //MARKET_ON_WHEELS_MENU_H
