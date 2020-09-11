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
    sf::Font& getFont();
    sf::Texture& getLogo();
    sf::Texture& getTexture();
    void changeGameState(GameState::State gameState);
private:
    sf::RenderWindow m_window;
    GameState* m_currentState;
    std::array<GameState*, GameState::Count> m_gameStates;
    sf::Font m_font;
    sf::Texture m_logo;
    sf::Texture m_texture;
    
    
};
#endif /* Game_hpp */
