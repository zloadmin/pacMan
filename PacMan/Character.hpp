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
#include "Maze.hpp"

class Character: public sf::Drawable, public sf::Transformable
{
public:
    Character();
    
    virtual void update(sf::Time delta);
    
    void setMaze(Maze* maze);
    
    void setSpeed(float speed);
    float getSpeed() const;
    
    void setDirection(sf::Vector2i drection);
    sf::Vector2i getDirection() const;
    
private:
    float m_speed;
    sf::Vector2i m_currentDerection;
    sf::Vector2i m_nextDerection;
    Maze* m_maze;
    
};
#endif /* Character_hpp */
