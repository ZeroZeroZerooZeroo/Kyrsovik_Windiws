#include "Menu.h"
#include "Rules.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#define _CRT_SECURE_NO_WARNINGS

using namespace sf;

void Menu::menu()
{
    //Константы для размера окна
    int const height = 950;
    int const width = 600;

    //Создание окна
	RenderWindow window(VideoMode(width, height), "Space War!",Style::Close);

    //Загрузка текстур
    Texture background,button_start,button_exit,name_game,qv;
    qv.loadFromFile("image/qv.png");
    name_game.loadFromFile("image/Name_Game.png");
    background.loadFromFile("image/Space.jpg");
    button_start.loadFromFile("image/Button_menu_start.png");
    button_exit.loadFromFile("image/Button_menu_exit.png");

    //Текстуры в спрайты
    Sprite menu_background, button_exit_menu(button_exit), button_start_menu(button_start),name_g(name_game), question(qv);
    
    //Установка спрайтов на их позиции
    question.setPosition(530, 890);
    name_g.setPosition(100, 120);
    menu_background.setTexture(background);
    button_start_menu.setPosition(180, 725);
    button_start_menu.setScale(0.5f, 0.55f);
    button_exit_menu.setPosition(180, 800);
    button_exit_menu.setScale(0.5f, 0.55f);

    //Иконка
    Image icon;
    icon.loadFromFile("image/SpaceWar.png");
    window.setIcon(32, 32, icon.getPixelsPtr());

    //Основной цикл работы программы
    while (window.isOpen())
    {
        //Если пользователь наводится курсором на кнопку курсор меняется на "руку"
        Cursor cursor;
        if (IntRect(180, 725, 239, 68).contains(Mouse::getPosition(window)) || IntRect(180, 800, 239, 68).contains(Mouse::getPosition(window))|| IntRect(530, 890, 60, 60).contains(Mouse::getPosition(window)))
        {
            if (cursor.loadFromSystem(Cursor::Hand))
                window.setMouseCursor(cursor);
        }
        else
        {
            if (cursor.loadFromSystem(Cursor::Arrow))
                window.setMouseCursor(cursor);
        }

        if (Mouse::isButtonPressed(Mouse::Left) && IntRect(180, 725, 239, 68).contains(Mouse::getPosition(window)))
        {
            window.close();
            Game::Start();
        }

        if (Mouse::isButtonPressed(Mouse::Left) && IntRect(180, 800, 239, 68).contains(Mouse::getPosition(window)))
        {
            window.close();
        }

        if (Mouse::isButtonPressed(Mouse::Left) && IntRect(530, 890, 60, 60).contains(Mouse::getPosition(window)))
        {
            Rules::rules();
        }

        //Ивент на закрытия окна
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //Очистка окна
        window.clear();

        //Отрисовка всех спрайтов
        window.draw(menu_background);
        window.draw(question);
        window.draw(name_g);
        window.draw(button_start_menu);
        window.draw(button_exit_menu);
        window.display();
    }
}