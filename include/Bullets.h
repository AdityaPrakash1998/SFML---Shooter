#ifndef BULLETS_H
#define BULLETS_H
#include<SFML/Graphics.hpp>

using namespace sf;


class Bullets
{
    public:
        Bullets();
        void SetPos(Vector2f);
        void Fire(float);
        void Draw(RenderWindow& window);
        float getX();
        float getY();
        virtual ~Bullets();

    protected:

    private:
        CircleShape bullet;
};

#endif // BULLETS_H
