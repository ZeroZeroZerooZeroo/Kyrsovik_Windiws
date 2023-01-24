#include "Game.h"
#include "Hero.h"
#include "Enemies.h"
#include "LazerHero.h"
#include "LazerEnemy.h"
#include "Restart.h"
#include "Victory.h"
#include <SFML/Graphics.hpp>
#include <vector>
#include <iterator>
#include <thread>
#include <chrono>
#include <iostream>
#include <windows.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace std::chrono_literals;
using namespace sf;
using namespace std;

void Game::Start() {

    //��������� ��� ������� ����
    int const height = 950;
    int const width = 600;

    Hero he(250, 900,30,39);
    LazerHero lh(250, 900, 20, 10);

    //�������� ����
    RenderWindow window(VideoMode(width, height), "Spase War!", Style::Close);

    //�������� �������� ������� ���� 
    Texture background;
    background.loadFromFile("image/Space.jpg");

    //�������� � ������
    Sprite menu_background;
    menu_background.setTexture(background);

    //������
    Image icon;
    icon.loadFromFile("image/SpaceWar.png");
    window.setIcon(32, 32, icon.getPixelsPtr());

    //�������� ������
    Font font;
    font.loadFromFile("C:/Users/Zero/Desktop/Game_Space_War/arial.ttf");

    //��������� ���������� ��������
    Text counter,press;
    counter.setCharacterSize(30);
    counter.setFillColor(Color(127, 255, 212));
    counter.setFont(font);

    //������� ����� ������
    press.setCharacterSize(20);
    press.setFillColor(Color(240, 255, 240));
    press.setFont(font);

    //���������� ��������
    int score = 0;

    //��������� ������� �����
    he.HSetup();
    lh.SetupLH();
     
    //�������� ������ � �� �������
    vector<Enemies*> enemys;
    vector<LazerEnemy*> lazer_en;
    for (int i = 30; i <= width; i += width / 9)
    {
        enemys.push_back(new Enemies(i,10, rand()%5+5, 20));
        lazer_en.push_back(new LazerEnemy(i, 15, 20, 10));
    }

    //��������� ������� ������
    for (const auto& en : enemys) {
        en->ESetup();
    }

    //��������� ������� ������ ������
    for (const auto& le : lazer_en) {
        le->LESetup();
    }

    //�������� ���� ������ ���������
    while (window.isOpen())
    {
        //����� �� �������� ����
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //�������� �����
        he.HMove();

        //�������� ������ �����
        lh.LazerMove();
        if (lh.GetLHY() <= 0)
            lh.SetHLazer(he.GetHX(), he.GetHY());

        //�������� ������ � �� �������
        for (int i = 0; i < enemys.size();i++) {
            enemys[i]->EMove();
            if (enemys[i]->GetEY() >= 950) {
                enemys[i]->SetEY(-20);
                enemys[i]->SetESpeed(rand() % 5 + 5);
            }

            for (int j = 0; j < lazer_en.size(); j++) {
                if (lazer_en[j]->GetLHX() == enemys[i]->GetEX()) {
                    lazer_en[j]->LazerEMove();
                    if (lazer_en[j]->GetLEY() >= 950) {
                        lazer_en[j]->SetLEY(enemys[i]->GetEY()+10);
                    }
                }

                //���������� �� ����� �� ������ �����
                float d1 = sqrt((he.GetHX() - lazer_en[j]->GetLHX()) * (he.GetHX() - lazer_en[j]->GetLHX()) + (he.GetHY() - lazer_en[j]->GetLHY()) * (he.GetHY() - lazer_en[j]->GetLHY()));

                //���������� �� ����� �� �����
                float d2 = sqrt((he.GetHX() - enemys[i]->GetEX()) * (he.GetHX() - enemys[i]->GetEX()) + (he.GetHY() - enemys[i]->GetEY()) * (he.GetHY() - enemys[i]->GetEY()));

                //���� �� ����� ������ ��� � ��� �����������
                if ((he.GetHH() / 2 + lazer_en[j]->GetLHH() / 2 >= d1+11)||(he.GetHH() / 2 + enemys[i]->GetER()>=d2)) {
                    lazer_en.clear();
                    window.close();
                    Restart::restart();
                }
            }
            //���� �� ����� ������
            //���������� �� ����� �� ������ �����
            float d3 = sqrt((lh.GetLHX() - enemys[i]->GetEX()) * (lh.GetLHX() - enemys[i]->GetEX()) + (lh.GetLHY() - enemys[i]->GetEY()) * (lh.GetLHY() - enemys[i]->GetEY()));

            if (lh.GetLHH()/2 + enemys[i]->GetER() -3 >= d3)
            {
                if (score <10)
                {
                    enemys[i]->SetEY(-20);
                    lh.SetHLazer(he.GetHX(), he.GetHY());
                    score++;
                }
                else
                {
                    auto iter = enemys.begin();
                    lazer_en.clear();
                    for (int z = 0; z < enemys.size(); z++)
                    {
                        enemys[z]->SetESpeed(-10);
                        if (enemys[z]->GetEY() <= -20)
                            enemys.erase(iter + z);
                    }
                    press.setString(String(L"������� 'R' ��� �����������"));
                    press.setPosition(100, 50);
                }
            }
            //���� ������
            if (Keyboard::isKeyPressed(Keyboard::R))
            {
                window.close();
                Victory::victory();
            }
        }
        //�������
        counter.setString(String(L"����: ") + to_string(score));

        //������� ����
        window.clear();

        //��������� ������� ����
        window.draw(menu_background);

        //��������� ��������
        window.draw(counter);

        //�������� ������� ������
        window.draw(press);

        //��������� �����
        window.draw(he.HDraw());

        //��������� ������ �����
        window.draw(lh.LazerHdraw());

        //��������� ������ ������
        for (const auto& le : lazer_en) {
            window.draw(le->LazerEDraw());
        }

        //��������� ������
        for (const auto& enemy : enemys)
            window.draw(enemy->EDraw());

        window.display();

        //��������� ������
        std::this_thread::sleep_for(30ms);
    }
}