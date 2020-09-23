//
//  Character.cpp
//  PacMan
//
//  Created by Vladimir on 12.09.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//

#include "Character.hpp"
#include <cmath>

Character::Character()
:m_maze(nullptr)
,m_speed(1.f)
,m_currentDerection(1,0)
,m_nextDerection(0,0)
{
    
};
void Character::setMaze(Maze* maze)
{
    m_maze = maze;
}
void Character::setSpeed(float speed)
{
    m_speed = speed;
};
float Character::getSpeed() const
{
    return m_speed;
};
void Character::setDirection(sf::Vector2i drection)
{
    m_nextDerection = drection;
}
sf::Vector2i Character::getDirection() const
{
    return m_currentDerection;
}
void Character::update(sf::Time delta)
{
    sf::Vector2f pixelPosition = getPosition();
    float pixelTreveled = getSpeed() * delta.asSeconds();
    sf::Vector2f nextPixelPosition = pixelPosition + sf::Vector2f(m_currentDerection) * pixelTreveled;
    setPosition(nextPixelPosition);
    sf::Vector2i cellPosition = m_maze->mapPixelToCell(pixelPosition);
    sf::Vector2f offset;
    offset.x = std::fmod(pixelPosition.x, 32) - 16;
    offset.y = std::fmod(pixelPosition.y, 32) - 16;
    
    if(m_maze->isWall(cellPosition + m_currentDerection)) {
        
        if(
            (m_currentDerection.x ==  1 && offset.x > 0) ||
            (m_currentDerection.x == -1 && offset.x < 0) ||
            (m_currentDerection.y ==  1 && offset.y > 0) ||
            (m_currentDerection.y == -1 && offset.y < 0)
        )
        {
            setPosition(m_maze->mapCellToPixel(cellPosition));
        }
    }
    if(!m_maze->isWall(cellPosition + m_currentDerection) && m_currentDerection != m_nextDerection)
    {
        if(
           (!m_currentDerection.y && (offset.x > -2 && offset.y < 2)) ||
           (!m_currentDerection.x && (offset.y > -2 && offset.x < 2))
           )
        {
            setPosition(m_maze->mapCellToPixel(cellPosition));
            m_currentDerection = m_nextDerection;
            
            if (m_currentDerection == sf::Vector2i(1, 0))
            {
                setRotation(0);
                setScale(-1, 1);
            }
            else if (m_currentDerection == sf::Vector2i(0, 1))
            {
                setRotation(90);
                setScale(-1, 1);
            }
            else if (m_currentDerection == sf::Vector2i(-1, 0))
            {
                setRotation(0);
                setScale(1, 1);
            }
            else if (m_currentDerection == sf::Vector2i(0, -1))
            {
                setRotation(90);
                setScale(1, 1);
            }
            
        }
    }
        
    m_currentDerection = m_nextDerection;
}
