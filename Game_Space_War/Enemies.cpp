#include "Enemies.h"


//����������� ������
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

//���������� ������
Enemies::~Enemies()
{
}

//��������� ������� ������
void Enemies::ESetup()
{
	m_Etexture.loadFromFile("image/Enemies.png");
	m_enemy.setTexture(m_Etexture);
	m_enemy.setPosition(m_ex, m_ey);
	m_enemy.setOrigin(m_er, m_er);
}

//�������� ������
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

//��������� �������� ������
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

//��������� ������
Sprite Enemies::EDraw()
{
	return m_enemy;
}