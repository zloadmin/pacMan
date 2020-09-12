//
//  Bonus.hpp
//  PacMan
//
//  Created by Vladimir on 12.09.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//

#ifndef Bonus_hpp
#define Bonus_hpp

#include <SFML/Graphics.hpp>

class Bonuse : public sf::Drawable, public sf::Transformable
{
    enum Fruit {
        Banana,
        Apple,
        Cherry
    };
public:
    Bonuse(sf::Texture& texture);
    void setFruite(Fruit fruit);
private:
    sf::Sprite m_visual;
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif /* Bonus_hpp */
