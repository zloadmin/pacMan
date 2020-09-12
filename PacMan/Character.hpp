//
//  Character.hpp
//  PacMan
//
//  Created by Vladimir on 12.09.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//

#ifndef Character_hpp
#define Character_hpp

#include <SFML/Graphics.hpp>
class Character: public sf::Drawable, public sf::Transformable
{
public:
    Character();
    void setSpeed(float speed);
    float getSpeed() const;
private:
    float m_speed;
};
#endif /* Character_hpp */
