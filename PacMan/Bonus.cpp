//
//  Bonus.cpp
//  PacMan
//
//  Created by Vladimir on 12.09.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//

#include "Bonus.hpp"
#include <SFML/Graphics.hpp>

Bonuse::Bonuse(sf::Texture& texture)
: m_visual(texture)
{
    m_visual.setOrigin(15, 15);
    setFruite(Banana);
}

void Bonuse::setFruite(Fruit fruit)
{
    switch (fruit) {
        case Banana:
            m_visual.setTextureRect(sf::IntRect(32,0,30,30));
            break;
        case Apple:
            m_visual.setTextureRect(sf::IntRect(32+30,0,30,30));
            break;
        case Cherry:
            m_visual.setTextureRect(sf::IntRect(32+60,0,30,30));
            break;
    }
}
void Bonuse::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    states.transform *= getTransform();
    target.draw(m_visual, states);
}

