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
class Ghost : public Character
{
public:
    Ghost(sf::Texture texture);
    void setWeak(sf::Time duration);
    bool isWeak() const;
    
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
    
};

#endif /* Ghost_hpp */
