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
#include "GameState.hpp"
#include <array>

class Game {
public:
    Game();
    ~Game();
    void run();
    void changeGameState(GameState::State gameState);
private:
    sf::RenderWindow m_window;
    GameState* m_currentState;
    std::array<GameState*, GameState::Count> m_gameStates;
};
#endif /* Game_hpp */
