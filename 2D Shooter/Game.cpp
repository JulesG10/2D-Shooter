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

bool Game::Run()
{
    sf::RenderWindow window(sf::VideoMode(600, 500), "Game", sf::Style::Resize | sf::Style::Close);
    sf::View view = window.getDefaultView();

    sf::Clock clock;
    float deltatime = 0;
    
    Player player = Player(sf::Vector2f(100.0f,100.0f));
    Map map = Map(sf::Vector2f(0.0f,0.0f),sf::Vector2f(600.0f,500.0f));

    map.loadFromFile("C:\\Users\\jules\\source\\repos\\2D Shooter\\Debug\\assets\\map.json");

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
                view.setSize(event.size.width, event.size.height);
                view.setCenter(event.size.width / 2, event.size.height / 2);
                window.setView(view);
            }
        }
        
        map.Update(deltatime);
        player.Update(deltatime);

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