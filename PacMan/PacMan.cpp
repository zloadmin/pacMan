//
//  PacMan.cpp
//  PacMan
//
//  Created by Vladimir on 12.09.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//

#include "PacMan.hpp"

PacMan::PacMan(sf::Texture& texture)
: m_visual(texture)
, m_isDead(false)
{
    setOrigin(20, 20);
}
void PacMan::die()
{
    m_isDead = true;
};
bool PacMan::isDead() const
{
    return m_isDead;
};
void PacMan::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    if(!isDead()) target.draw(m_visual, states);
};
