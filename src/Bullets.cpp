#include "Bullets.h"
#include<SFML/Graphics.hpp>
#include<cmath>

using namespace sf;

Bullets::Bullets()
{
    bullet.setFillColor(Color(206,164,34));
    //bullet.setSize(Vector2f(50.0,50.0));
    bullet.setRadius(8.0f);
}
void Bullets::SetPos(Vector2f position)
{
    bullet.setPosition(position);
}
void Bullets::Fire(float x)
{
    bullet.move(x,0.0f);
}
float Bullets::getX()
{
    return bullet.getPosition().x;
}
float Bullets::getY()
{
    return bullet.getPosition().y;
}
void Bullets::Draw(RenderWindow& window)
{
    window.draw(bullet);
}
Bullets::~Bullets()
{
    //dtor
}
