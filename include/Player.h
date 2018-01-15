#ifndef PLAYER_H
#define PLAYER_H
#include <SFML/Graphics.hpp>
#include<Bullets.h>

using namespace sf;
class Player
{
    public:
        Player(Vector2f size,Vector2f position);

        void Draw(RenderWindow& window);
        void Move(float X,float Y);
        void Origin(Vector2f mid);
        Vector2f GetPos();
        void checkColl(Bullets);
        int currenthealth()
        {
            return health;
        }

        virtual ~Player();

    protected:

    private:
        int health=100;
        RectangleShape player;
        Vector2f size;
        Vector2f position;

};

#endif // PLAYER_H
