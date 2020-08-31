//
//  Game.hpp
//  PacMan
//
//  Created by Vladimir on 31.08.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//

#ifndef Game_hpp
#define Game_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
class Game {
public:
    Game();
    void run();
    void insertCoin();
    void pressButton();
    void moveStick(sf::Vector2i direction);
     
    
    
private:
    sf::RenderWindow m_window;
};
#endif /* Game_hpp */
