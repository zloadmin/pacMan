//
//  PacMan.hpp
//  PacMan
//
//  Created by Vladimir on 12.09.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//

#ifndef PacMan_hpp
#define PacMan_hpp

#include "Character.hpp"
class PacMan : public Character
{
public:
    PacMan(sf::Texture& texture);
    void die();
    bool isDead() const;
    
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool m_isDead;
    sf::Sprite m_visual;
};

#endif /* PacMan_hpp */
