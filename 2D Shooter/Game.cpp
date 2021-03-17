#include<iostream>
#include<SFML/Window.hpp>
#include<vector>
#include "Game.h"
#include "Macro.hpp"
#include "Player.h"
#include "Map.h"

#include<chrono>

Game::Game()
{
    
}

bool Game::Run(std::string startLocation)
{
    sf::RenderWindow window(sf::VideoMode(600, 500), "Game", sf::Style::Resize | sf::Style::Close);
    sf::View view = window.getDefaultView();

    sf::Clock clock;
    float deltatime = 0;
    
    Player player = Player(sf::Vector2f(0.0f,0.0f), startLocation);
    Map map = Map(sf::Vector2f(0.0f,0.0f),sf::Vector2f(600.0f,500.0f),startLocation);

    map.loadFromFile(startLocation + "assets\\map.json");

    while (window.isOpen())
    {
        deltatime = clock.restart().asSeconds();

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (event.type == sf::Event::Resized)
            {
                int h = event.size.height;
                int w = event.size.width;

                if (w < 600.0f)
                {
                    w = 600.0f;
                }
                if (h < 500.0f)
                {
                    h = 500.0f;
                }

                view.setSize(w, h);
                window.setSize(sf::Vector2u(w, h));
                
                view.setCenter(w / 2, h / 2);
                
                window.setView(view);

                map.Resize(sf::Vector2f(w,h));
            }
        }
        
        map.Update(deltatime);
        player.Update(deltatime,map);

        // sf::Color::Color(5, 110, 35)
        window.clear();

        map.Draw(window);
        player.Draw(window);

        window.display();
    }
    return true;
}

Game::~Game()
{

}