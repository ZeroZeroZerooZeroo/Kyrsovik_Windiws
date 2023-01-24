#pragma once
#include "LazerHero.h"

class LazerEnemy :
    public LazerHero
{
private:
    Texture m_letexture;
    Sprite m_elazer;
public:
    LazerEnemy (int x, int y, int h, int w);

    ~LazerEnemy();

    void LazerEMove();

    Sprite LazerEDraw();

    int GetLEY();

    void SetLEY(int y);

    void LESetup();
};