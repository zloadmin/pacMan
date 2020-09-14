//
//  Maze.hpp
//  PacMan
//
//  Created by Vladimir on 14.09.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//

#ifndef Maze_hpp
#define Maze_hpp

#include <array>
#include <SFML/Graphics.hpp>

class Maze : public sf::Drawable
{
public:
    Maze();
    void loadLevel(std::string name);
    sf::Vector2i getPacManPosition() const;
    std::vector<sf::Vector2i> getGhostPositions() const;
    inline std::size_t positionToIndex(sf::Vector2i position) const;
    inline sf::Vector2i indexToPosition(std::size_t index) const;
    
    
private:
    enum CellData
    {
        Empty,
        Wall,
        Dot,
        SuperDot,
        Bonus
    };
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
    sf::Vector2i m_mazeSize;
    std::vector<CellData> m_mazeData;
    sf::RenderTexture m_renderTexture;
    sf::Vector2i m_pacManPosition;
    std::vector<sf::Vector2i> m_ghostPosition;
};
#endif /* Maze_hpp */
