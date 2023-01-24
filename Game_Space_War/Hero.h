#include <SFML/Graphics.hpp>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace sf;

class Hero
{
private:
	int m_hx, m_hy, m_hw, m_hh, speed=15;
	Texture m_texture;
	Sprite m_hero;
public:

	Hero(int x,int y, int w, int h);

	~Hero();

	Sprite HDraw();

	void HSetup();

	void HMove();

	int GetHX();

	int GetHY();

	int GetHH();
};