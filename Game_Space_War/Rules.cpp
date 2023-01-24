#include "Rules.h"
#include <SFML/Graphics.hpp>

using namespace sf;

void Rules::rules()
{
    //Константы для размера окна
    int const height = 600;
    int const width = 400;

    //Создание окна
    RenderWindow window(VideoMode(width, height), "Space War rules", Style::Close);
    window.setPosition(Vector2i(10, 50));

    //Загрузка текстур
    Texture PR;
    PR.loadFromFile("image/PR.png");

    //Текстуры в спрайты
    Sprite pr(PR);

    //Установка позиции спрайтов
    pr.setPosition(0, 0);
    pr.setOrigin(0, 0);

    //Иконка
    Image icon;
    icon.loadFromFile("image/SpaceWar.png");
    window.setIcon(32, 32, icon.getPixelsPtr());

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        //Очистка окна
        window.clear();

        //Отрисовка всех спрайтов
        window.draw(pr);
        window.display();
    }

}