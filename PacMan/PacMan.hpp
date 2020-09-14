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
#include "Animator.hpp"

class PacMan : public Character
{
public:
    PacMan(sf::Texture& texture);
    void die();
    bool isDying() const;
    bool isDead() const;
    
    void update(sf::Time delta);
    
    
private:
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    bool m_isDying;
    bool m_isDead;
    sf::Sprite m_visual;
    Animator m_runAnimator;
    Animator m_dieAnimator;
};


#endif /* PacMan_hpp */
