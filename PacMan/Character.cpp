//
//  Character.cpp
//  PacMan
//
//  Created by Vladimir on 12.09.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//

#include "Character.hpp"
Character::Character()
:m_speed(1.f)
{
    
};
void Character::setSpeed(float speed)
{
    m_speed = speed;
};
float Character::getSpeed() const
{
    return m_speed;
};
