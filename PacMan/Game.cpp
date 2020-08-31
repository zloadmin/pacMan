//
//  Game.cpp
//  PacMan
//
//  Created by Vladimir on 31.08.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//
#include <iostream>
#include "Game.hpp"
#include <SFML/Graphics.hpp>

Game::Game()
:m_window(sf::VideoMode(640, 480), "PacMan")
{
    
} 
void Game::run()
{
    
    while (m_window.isOpen()) {
           sf::Event event;
           while (m_window.pollEvent(event)) {
               if(event.type == sf::Event::Closed)
                   m_window.close();
               if(event.type == sf::Event::KeyPressed) {
                   if(event.key.code == sf::Keyboard::I)
                   insertCoin();
                   if(event.key.code == sf::Keyboard::S)
                   pressButton();
                   if(event.key.code == sf::Keyboard::Left)
                   moveStick(sf::Vector2i(-1, 0));
                   if(event.key.code == sf::Keyboard::Right)
                   moveStick(sf::Vector2i(1, 0));
                   if(event.key.code == sf::Keyboard::Up)
                   moveStick(sf::Vector2i(0, -1));
                   if(event.key.code == sf::Keyboard::Down)
                   moveStick(sf::Vector2i(0, 1));
                   
               }
           }
           m_window.clear();
            // draw
           m_window.display();
       }

    
}
void Game::insertCoin() {
    std::cout << "insert coin " << std::endl;
}
void Game::pressButton() {
    std::cout << " press button " << std::endl;
}
void Game::moveStick(sf::Vector2i direction)
{
    std::cout << " move stick " << std::endl;
}
