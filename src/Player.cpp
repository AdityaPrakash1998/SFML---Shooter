#include "Player.h"
#include<SFML/Graphics.hpp>
#include<Bullets.h>
#include<iostream>
using namespace std;

using namespace sf;

Player::Player(Vector2f size,Vector2f position)
{
    this->size=size;
    this->position=position;

    player.setSize(this->size);
    player.setPosition(this->position);
    player.setFillColor(Color::Cyan);

}

void Player::Move(float X,float Y)
{
        player.move(X,Y);
}

void Player::Origin(Vector2f mid)
{
    player.setOrigin(mid.x,mid.y);
}

Vector2f Player::GetPos()
{
    return player.getPosition();
}

void Player::checkColl(Bullets bullet)
{
    if(bullet.getX()<player.getPosition().x+2.0)
    {
        if(bullet.getY()<player.getPosition().y+40.0
       && bullet.getY()>player.getPosition().y-40.0
       && bullet.getX()>player.getPosition().x-2.0)

        health-=5;
    }

}

void Player::Draw(RenderWindow& window)
{
    window.draw(player);
}

Player::~Player()
{
    //dtor
}
