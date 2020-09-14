//
//  Animator.hpp
//  PacMan
//
//  Created by Vladimir on 14.09.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//

#ifndef Animator_hpp
#define Animator_hpp
#include <SFML/Graphics.hpp>

class Animator
{
public:
    Animator();

    void addFrame(sf::IntRect frame);

    void play(sf::Time duration, bool loop);
    bool isPlaying() const;

    void update(sf::Time delta);
    void animate(sf::Sprite& sprite);

private:
    std::vector<sf::IntRect> m_frames;

    bool m_isPlaying;
    sf::Time m_duration;
    bool m_loop;

    unsigned int m_currentFrame;
};

#endif /* Animator_hpp */
