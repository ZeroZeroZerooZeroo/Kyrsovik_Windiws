#include "LazerHero.h"

//Конструктор лазера героя
LazerHero::LazerHero(int x, int y, int h,int w)
{
	m_lhx = x;
	m_lhy = y;
	m_lhh = h;
	m_lhw = w;
}

LazerHero::LazerHero()
{
}

//Деструктор лазера героя
LazerHero::~LazerHero()
{
}

int LazerHero::GetLHX()
{
	return m_lhx;
}

int LazerHero::GetLHY()
{
	return m_lhy;
}

//Движение лазера героя
void LazerHero::LazerMove()
{
	m_lhy -= 10;
	m_lazer.setPosition(m_lhx, m_lhy);
}

//Отрисовка лазера героя
Sprite LazerHero::LazerHdraw()
{
	return m_lazer;
}

int LazerHero::GetLHH()
{
	return m_lhh;
}

//Установка текстуры лазера героя
void LazerHero::SetupLH()
{
	m_lazer.setOrigin(m_lhw / 2, m_lhh / 2);
	m_ltexture.loadFromFile("image/Hero_lazer.png");
	m_lazer.setTexture(m_ltexture);
}

//Установка позиции лазера героя 
void LazerHero::SetHLazer(int x, int y)
{
	m_lhx = x;
	m_lhy = y;
	m_lazer.setPosition(m_lhx, m_lhy);
}