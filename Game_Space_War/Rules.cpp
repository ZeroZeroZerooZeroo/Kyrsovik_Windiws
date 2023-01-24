#include "Rules.h"
#include <SFML/Graphics.hpp>

using namespace sf;

void Rules::rules()
{
    //��������� ��� ������� ����
    int const height = 600;
    int const width = 400;

    //�������� ����
    RenderWindow window(VideoMode(width, height), "Space War rules", Style::Close);
    window.setPosition(Vector2i(10, 50));

    //�������� �������
    Texture PR;
    PR.loadFromFile("image/PR.png");

    //�������� � �������
    Sprite pr(PR);

    //��������� ������� ��������
    pr.setPosition(0, 0);
    pr.setOrigin(0, 0);

    //������
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

        //������� ����
        window.clear();

        //��������� ���� ��������
        window.draw(pr);
        window.display();
    }

}