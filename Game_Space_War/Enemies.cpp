#include "Enemies.h"


//Конструктор врагов
Enemies::Enemies(int x, int y, int speed, int r)
{
	m_ex = x;
	m_ey = y;
	m_espeed = speed;
	m_er = r;
}

Enemies::Enemies()
{
}

//Деструктор врагов
Enemies::~Enemies()
{
}

//Установка позиции врагов
void Enemies::ESetup()
{
	m_Etexture.loadFromFile("image/Enemies.png");
	m_enemy.setTexture(m_Etexture);
	m_enemy.setPosition(m_ex, m_ey);
	m_enemy.setOrigin(m_er, m_er);
}

//Движение врагов
void Enemies::EMove()
{
	m_ey += m_espeed;
	m_enemy.setPosition(m_ex, m_ey);
}

int Enemies::GetEY()
{
	return m_ey;
}

int Enemies::GetEX()
{
	return m_ex;
}

//Установка скорости врагов
void Enemies::SetESpeed(int speed)
{
	m_espeed = speed;
}

void Enemies::SetEY(int y)
{
	m_ey = y;
}

int Enemies::GetER()
{
	return m_er;
}

//Отрисовка врагов
Sprite Enemies::EDraw()
{
	return m_enemy;
}