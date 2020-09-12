//
//  Ghost.cpp
//  PacMan
//
//  Created by Vladimir on 12.09.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//

#include "Ghost.hpp"
#include <SFML/Graphics.hpp>

Ghost::Ghost(sf::Texture texture)
:m_visual(texture)
,m_isWeak(false)
,m_weaknessDuration(sf::Time::Zero)
{
    
    setOrigin(20, 20);
};
void Ghost::setWeak(sf::Time duration)
{
    m_isWeak = true;
    m_weaknessDuration = duration;
    
};
bool Ghost::isWeak() const
{
    return m_isWeak;
};
void Ghost::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_visual, states);
    
};
