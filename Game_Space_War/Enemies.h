#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS

using namespace sf;

class Enemies
{
protected:
	int m_ex, m_ey, m_espeed, m_er;
	Texture m_Etexture;
	Sprite m_enemy;
public:
	Enemies(int x, int y, int speed, int r);

	Enemies();

	~Enemies();

	Sprite EDraw();

	void ESetup();

	void EMove();

	int GetEY();

	int GetEX();

	void SetESpeed(int speed);

	void SetEY(int y);
	
	int GetER();
};