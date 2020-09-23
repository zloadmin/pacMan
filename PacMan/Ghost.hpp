//
//  Ghost.hpp
//  PacMan
//
//  Created by Vladimir on 12.09.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//

#ifndef Ghost_hpp
#define Ghost_hpp

#include "Character.hpp"
#include "PacMan.hpp"
#include "Animator.hpp"

class Ghost : public Character
{
public:
    Ghost(sf::Texture& texture);
    void setWeak(sf::Time duration);
    bool isWeak() const;
    void update(sf::Time delta);
    
    enum State
    {
        Strong,
        Weak
    };


    
private:
    
    bool m_isWeak;
    sf::Time m_weaknessDuration;
    sf::Sprite m_visual;
    
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    
    PacMan* m_pacMan;
    
    Animator m_strongAnimator;
    Animator m_weakAnimator;
    
};

#endif /* Ghost_hpp */
