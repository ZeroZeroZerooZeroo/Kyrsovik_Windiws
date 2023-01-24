#include "Hero.h"

//Конструктор героя
Hero::Hero(int x, int y, int w, int h)
{
	m_hx=x;
	m_hy=y;
	m_hw = w;
	m_hh = h;
}

//Деструктор героя
Hero::~Hero()
{
}

//Установка позиции героя
void Hero::HSetup()
{
	m_hero.setOrigin(m_hw / 2, m_hh / 2);
	m_hero.setPosition(m_hx, m_hy);
	m_texture.loadFromFile("image/Hero.png");
	m_hero.setTexture(m_texture);
}

//Прорисока героя
Sprite Hero::HDraw()
{
	return m_hero;
}

//Движение героя
void Hero::HMove()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		m_hx -= speed;
		m_hero.setPosition(m_hx, m_hy);
	}

	if (Keyboard::isKeyPressed(Keyboard::D))
	{
		m_hx += speed;
		m_hero.setPosition(m_hx, m_hy);
	}
	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		m_hy += speed;
		m_hero.setPosition(m_hx, m_hy);
		
	}
	if (Keyboard::isKeyPressed(Keyboard::W))
	{
		m_hy -= speed;
		m_hero.setPosition(m_hx, m_hy);
	}

	//Ограничение игровой области
	if (m_hx <= m_hw/2) {
		m_hero.setPosition(m_hw/2, m_hy);
	}

	if (m_hx >= 600-m_hw/2) {
		m_hero.setPosition(600-m_hw/2, m_hy);
	}

	if (m_hy >= 950-m_hh/2) {
		m_hero.setPosition(m_hx, 950-m_hh/2);
	}

	if (m_hy <= m_hh/2) {
		m_hero.setPosition(m_hx, m_hh/2);
	}
}

int Hero::GetHX()
{
	return m_hx;
}

int Hero::GetHY()
{
	return m_hy;
}
int Hero::GetHH() {
	return m_hh;
}