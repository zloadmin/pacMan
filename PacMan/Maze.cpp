//
//  Maze.cpp
//  PacMan
//
//  Created by Vladimir on 14.09.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//
#include "Maze.hpp"
#include "Dot.hpp"
#include <iostream>

const std::string ASSERT_DIR = "/Users/vladimir/Projects/PacMan/PacMan/PacMan/Resources/";

Maze::Maze()
: m_mazeSize(0,0)
{
    
}
void Maze::loadLevel(std::string name)
{
    sf::Image levelData;
    
    if (!levelData.loadFromFile(ASSERT_DIR + "/levels/"+name+".png"))
        throw std::runtime_error("Failed to load level (" + name +")");
    
    m_mazeSize = sf::Vector2i(levelData.getSize());
    if(m_mazeSize.x < 15 && m_mazeSize.y < 15)
        throw std::runtime_error("The load level os too small. Minimal 15 cells");
    
    for (unsigned int y; y < m_mazeSize.y; y++) {
        for (unsigned int x; x < m_mazeSize.x; x++) {
            sf::Color cellData = levelData.getPixel(x, y);
            if (cellData == sf::Color::Black)
            {
                m_mazeData.push_back(Wall);
            }
            else if (cellData == sf::Color::White)
            {
                m_mazeData.push_back(Dot);
            }
            else if (cellData == sf::Color::Green)
            {
                m_mazeData.push_back(SuperDot);
            }
            else if (cellData == sf::Color::Blue)
            {
                //pacwoman position
                m_pacManPosition = sf::Vector2i(x, y);
                    m_mazeData.push_back(Empty);
            }
            else if (cellData == sf::Color::Red)
            {
                //ghost position
                m_ghostPosition.push_back(sf::Vector2i(x,y));
                m_mazeData.push_back(Empty);
            }
            else
            {
                m_mazeData.push_back(Empty);
            }
        }
    }
    
    m_renderTexture.create(32 * m_mazeSize.x, 32* m_mazeSize.y);
    m_renderTexture.clear(sf::Color::Black);
    
    
    m_renderTexture.display();
    
    for (unsigned int i = 0; i < m_mazeData.size(); i++) {
        sf::Vector2i position = indexToPosition(i);
        std::cout << i << std::endl;
        std::cout << position.x << std::endl;
        std::cout << position.y << std::endl;
        std::cout << "" << std::endl;
        
        if(m_mazeData[i] == Wall) {
            sf::RectangleShape wall;
            wall.setSize(sf::Vector2f(32, 32));
            wall.setFillColor(sf::Color::Blue);
            wall.setPosition(32*position.x, 32*position.y);
            m_renderTexture.draw(wall);
        }
    }
    
    
}
void Maze::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(sf::Sprite(m_renderTexture.getTexture()), states);
    static sf::CircleShape dot = getDot();
    static sf::CircleShape superDot = getSuperDot();
    
    for (unsigned int i = 0; i < m_mazeData.size(); i++) {
        sf::Vector2i position = indexToPosition(i);
        std::cout << i << std::endl;
        std::cout << position.x << std::endl;
        std::cout << position.y << std::endl;
        std::cout << "" << std::endl;
        
        if(m_mazeData[i] == Dot) {
            dot.setPosition(32*position.x+16, 32*position.y+16);
            target.draw(dot, states);
        } else if(m_mazeData[i] == SuperDot) {
            superDot.setPosition(32*position.x+16, 32*position.y+16);
            target.draw(superDot, states);
        }
    }
    
}

sf::Vector2i Maze::getPacManPosition() const
{
    return m_pacManPosition;
};
std::vector<sf::Vector2i> Maze::getGhostPositions() const
{
    return m_ghostPosition;
};
std::size_t Maze::positionToIndex(sf::Vector2i position) const
{
    return position.y * m_mazeSize.x + position.x;
};
sf::Vector2i Maze::indexToPosition(std::size_t index) const
{
    sf::Vector2i position;
    position.x = index % m_mazeSize.x;
    position.y = index / m_mazeSize.x;
    
    return position;
};
