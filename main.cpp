#include<SFML/Graphics.hpp>
#include<SFMl/Window.hpp>
#include<Player.h>
#include<Bullets.h>
#include<iostream>
#include<vector>
#include<sstream>



using namespace sf;
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    RenderWindow window(VideoMode(1000,600),"Game");


    Vector2f size={80.0f,80.0f};
    Vector2f mid={40.0f,40.0f};

    Vector2f pos1={40.0f,window.getSize().y/2};
    Vector2f pos2={window.getSize().x-40.0f,window.getSize().y/2};

    Player player1(size,pos1),player2(size,pos2);
    player1.Origin(mid);
    player2.Origin(mid);

    //Score
    Vector2f scoreSize={400.0f,20.0f};
    Vector2f cover1Size={10.0f,20.0f};
    Vector2f cover2Size={10.0f,20.0f};

    Vector2f score1Pos={20.0,25.0f};
    Vector2f score2Pos={580.0,25.0f};

    RectangleShape score1,score2,cover1,cover2;
    score1.setSize(scoreSize);
    score1.setPosition(score1Pos);
    score2.setSize(scoreSize);
    score2.setPosition(score2Pos);

    cover1.setSize(cover1Size);
    cover1.setPosition(score1Pos);
    cover2.setSize(cover2Size);
    cover2.setPosition(score2Pos);

    score1.setFillColor(Color::Red);
    score2.setFillColor(Color::Red);
    cover1.setFillColor(Color::Blue);
    cover2.setFillColor(Color::Blue);

    //Firing variables
    bool p1fire=false;
    bool p2fire=false;

    vector<Bullets> bulletvec1;
    vector<Bullets> bulletvec2;
    bool   khtm=false;

    //Text
    Text text1,text2,text3;
    Font font;
    font.loadFromFile("sansation.ttf");

    text1.setCharacterSize(20);
    text2.setCharacterSize(20);
    text3.setCharacterSize(40);

    text1.setFont(font);
    text2.setFont(font);
    text3.setFont(font);

    text1.setString("Player 1");
    text2.setString("Player 2");
    text3.setString(" FIGHT !");

    text1.setPosition(Vector2f(205.0f,0.0f));
    text2.setPosition(Vector2f(765.0f,0.0f));
    text3.setPosition(Vector2f(430.0f,0.0f));

    text1.setFillColor(Color::White);
    text2.setFillColor(Color::White);
    text3.setFillColor(Color::White);

    while(window.isOpen())
    {
        Event e;
        while(window.pollEvent(e))
        {
            switch(e.type)
            {
            case Event::Closed:
                window.close();
                break;
            case Event::KeyPressed:
                if(e.key.code==Keyboard::Escape)
                    window.close();
                break;
            }

            if(Keyboard::isKeyPressed(Keyboard::F))
               {
                    p1fire=true;
               }

            if(Keyboard::isKeyPressed(Keyboard::Insert))
            {
                p2fire=true;
            }

        }
        //player1 controls
        if(Keyboard::isKeyPressed(Keyboard::W))
            if(player1.GetPos().y>100.0)
                player1.Move(0.0f,-0.8f);
        if(Keyboard::isKeyPressed(Keyboard::S))
            if(player1.GetPos().y<560.0)
                player1.Move(0.0f,0.8f);

        if(p1fire==true)
        {
            Bullets newbullet1;
            newbullet1.SetPos(player1.GetPos());
            bulletvec1.push_back(newbullet1);
            p1fire=false;
        }



        //player2 controls
        if(Keyboard::isKeyPressed(Keyboard::Up))
            if(player2.GetPos().y>100.0)
                player2.Move(0.0f,-0.8f);
        if(Keyboard::isKeyPressed(Keyboard::Down))
            if(player2.GetPos().y<560.0)
                player2.Move(0.0f,0.8f);

        if(p2fire==true)
        {
            Bullets newbullet1;
            newbullet1.SetPos(player2.GetPos());
            bulletvec2.push_back(newbullet1);
            p2fire=false;
        }

        window.clear();

        cover1Size.x=4*(100-player1.currenthealth());
        cover1.setSize(cover1Size);
        cover2Size.x=4*(100-player2.currenthealth());
        cover2.setSize(cover2Size);

        for(int i=0;i<bulletvec1.size();i++)
        {
            bulletvec1[i].Draw(window);
            if(bulletvec1[i].getX()<window.getSize().x+20)
                bulletvec1[i].Fire(3.0f);
            player2.checkColl(bulletvec1[i]);
            if(player2.currenthealth()==0)
            {
                 cout<<"player1 wins";
                 khtm=true;
                 break;
            }

        }

        for(int i=0;i<bulletvec2.size();i++)
        {
            bulletvec2[i].Draw(window);
            if(bulletvec2[i].getX()>-20)
                bulletvec2[i].Fire(-3.0);
            player1.checkColl(bulletvec2[i]);
            if(player1.currenthealth()==0)
            {
                cout<<"player2 wins";
                khtm=true;
                break;
            }

        }

        window.draw(score1);
        window.draw(score2);

        window.draw(cover1);
        window.draw(cover2);

        window.draw(text1);
        window.draw(text2);
        window.draw(text3);

        player1.Draw(window);
        player2.Draw(window);

        window.display();
        if(khtm==true) break;
    }
}
