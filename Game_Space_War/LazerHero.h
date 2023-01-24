#pragma once
#include <SFML/Graphics.hpp>

using namespace sf;

class LazerHero
{
protected:
	int m_lhx, m_lhy, m_lhh, m_lhw;
	Texture m_ltexture;
	Sprite m_lazer;
public:
	LazerHero(int x, int y, int h, int w);

	LazerHero();

	~LazerHero();

	int GetLHX();

	int GetLHY();

	void LazerMove();

	Sprite LazerHdraw();

	void SetHLazer(int x, int y);

	int GetLHH();

	void SetupLH();
};