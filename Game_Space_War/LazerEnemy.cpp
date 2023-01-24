#include "LazerEnemy.h"

//Коструктор лазеров врагов
LazerEnemy::LazerEnemy(int x, int y, int h, int w)
{
		m_lhx = x;
		m_lhy = y;
		m_lhh = h;
		m_lhw = w;
}

//Деструктор лазеров врагов
LazerEnemy::~LazerEnemy()
{
}

//Движение лазеров врагов
void LazerEnemy::LazerEMove()
{
	m_lhy += 10;
	m_elazer.setPosition(m_lhx, m_lhy);
}

//Отрисовка лазеров врагов
Sprite LazerEnemy::LazerEDraw()
{
	return m_elazer;
}

int LazerEnemy::GetLEY()
{
	return m_lhy;
}

void LazerEnemy::SetLEY(int y)
{
	m_lhy = y;
}

//Установка позиции лазеров врагов
void LazerEnemy::LESetup()
{
	m_elazer.setOrigin(m_lhw / 2, m_lhh / 2);
	m_elazer.setPosition(m_lhx, m_lhy);
	m_letexture.loadFromFile("image/Enemy_lazer.png");
	m_elazer.setTexture(m_letexture);
}