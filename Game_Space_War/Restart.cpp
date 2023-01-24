#include "Restart.h"
#include "Menu.h"
#include "Game.h"
#include <SFML/Graphics.hpp>
#include <string>
#define _CRT_SECURE_NO_WARNINGS

using namespace sf;
using namespace std;

void Restart::restart()
{
    //Константы для размера окна
    int const height = 950;
    int const width = 600;

    //Создание окна
    RenderWindow window(VideoMode(width, height), "Space War!", Style::Close);

    //Загрузка текстур
    Texture background, button_start, button_exit, menu, name_game;
    name_game.loadFromFile("image/Name_Game.png");
    menu.loadFromFile("image/Button_menu.png");
    background.loadFromFile("image/Space.jpg");
    button_start.loadFromFile("image/Button_restart.png");
    button_exit.loadFromFile("image/Button_menu_exit.png");

    //Текстуры в спрайты
    Sprite menu_background, button_exit_menu(button_exit), button_start_menu(button_start), menu_r(menu), name_g(name_game);

    //Установка спрайтов на их позиции
    name_g.setPosition(100, 120);
    menu_background.setTexture(background);
    menu_r.setPosition(180, 650);
    menu_r.setScale(0.5f, 0.55f);
    button_start_menu.setPosition(180, 725);
    button_start_menu.setScale(0.5f, 0.55f);
    button_exit_menu.setPosition(180, 800);
    button_exit_menu.setScale(0.5f, 0.55f);

    //Загрузка шрифта
    Font font;
    font.loadFromFile("C:/Users/Zero/Desktop/Game_Space_War/arial.ttf");


    //Установка надписи "Вы проиграли"    
    Text restart;
    restart.setCharacterSize(40);
    restart.setFillColor(Color(0, 255, 255));
    restart.setFont(font);
    restart.setString(String(L"Вы проиграли("));
    restart.setPosition(180, 575);

    //Основной цикл работы программы
    while (window.isOpen())
    {
        //Если пользователь наводится курсором на кнопку курсор меняется на "руку"
        Cursor cursor;
        if (IntRect(180, 725, 239, 68).contains(Mouse::getPosition(window)) || IntRect(180, 800, 239, 68).contains(Mouse::getPosition(window))|| IntRect(180, 650, 239, 68).contains(Mouse::getPosition(window)))
        {
            if (cursor.loadFromSystem(Cursor::Hand))
                window.setMouseCursor(cursor);
        }
        else
        {
            if (cursor.loadFromSystem(Cursor::Arrow))
                window.setMouseCursor(cursor);
        }

        if (Mouse::isButtonPressed(Mouse::Left) && IntRect(180, 650, 239, 68).contains(Mouse::getPosition(window)))
        {
            window.close();
            Menu::menu();
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
        //Отрисовка заднео фона
        window.draw(menu_background);

        //Отрисовка надписи "Вы проиграли"
        window.draw(restart);

        //Отрисовка названия игры
        window.draw(name_g);

        //Отрисовка кнопки рестарт
        window.draw(menu_r);

        //Отрисовка кнопки выхода в меню
        window.draw(button_start_menu);

        //Отрисовка кнопки выхода
        window.draw(button_exit_menu);

        window.display();
    }
}
