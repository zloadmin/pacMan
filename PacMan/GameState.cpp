//
//  GameState.cpp
//  PacMan
//
//  Created by Vladimir on 11.09.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//

#include "GameState.hpp"
#include "Game.hpp"
#include "PacMan.hpp"
#include "Ghost.hpp"

template <typename T>
void centerOrigin(T& drawable) {
    sf::FloatRect bound = drawable.getLocalBounds();
    drawable.setOrigin(bound.width / 2, bound.height / 2);
}
GameState::GameState(Game* game)
:m_game(game)
{
}

Game* GameState::getGame() const
{
    return m_game;
}

NoCoinState::NoCoinState(Game* game)
: GameState(game)
{
    m_sprite.setTexture(game->getLogo());
    m_sprite.setPosition(20, 50);
    
    m_text.setFont(game->getFont());
    m_text.setString("Insert coin!");
    centerOrigin(m_text);
    m_text.setPosition(240, 150);
    m_DisplayText = true;
    
    
}
GetReadyState::GetReadyState(Game* game)
: GameState(game)
{
    m_text.setFont(game->getFont());
    m_text.setString("Press start when you're ready...");
    m_text.setCharacterSize(14);
    
    centerOrigin(m_text);
    m_text.setPosition(240, 240);
    
    
}
PlayingState::PlayingState(Game* game)
: GameState(game)
, m_pacMan(game->getTexture())
, m_ghost(game->getTexture())
{
    m_pacMan.move(100, 100);
    m_ghost.move(200, 200);
}
WonState::WonState(Game* game)
: GameState(game)
{
    m_text.setFont(game->getFont());
    m_text.setString("You won!");
    m_text.setCharacterSize(42);
    centerOrigin(m_text);
    m_text.setPosition(240, 120);
    
}
LostState::LostState(Game* game)
: GameState(game)
{
    m_text.setFont(game->getFont());
    m_text.setString("You lost!");
    m_text.setCharacterSize(42);
    centerOrigin(m_text);
    m_text.setPosition(240, 120);
    
    m_countDownText.setFont(game->getFont());
    m_countDownText.setCharacterSize(12);
    centerOrigin(m_countDownText);
    m_countDownText.setPosition(240, 240);
    
}


void NoCoinState::insertCoin(){
    getGame()->changeGameState(GameState::GetReady);
}
void NoCoinState::pressButton(){
    
}
void NoCoinState::moveStick(sf::Vector2i direction){
    
}
void NoCoinState::update(sf::Time delta){
    
    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer+= delta;
    while (timeBuffer >= sf::seconds(0.5)) {
        m_DisplayText = !m_DisplayText;
        timeBuffer -= sf::seconds(1);
    }
}
void NoCoinState::draw(sf::RenderWindow& window){
    window.draw(m_sprite);
    if(m_DisplayText) window.draw(m_text);
}

void GetReadyState::insertCoin(){
    
}
void GetReadyState::pressButton(){

}
void GetReadyState::moveStick(sf::Vector2i direction){
    if(direction.x == -1)
        getGame()->changeGameState(GameState::Lost);
    else if(direction.x == 1)
        getGame()->changeGameState(GameState::Won);
}
void GetReadyState::update(sf::Time delta){
    
}
void GetReadyState::draw(sf::RenderWindow& window){
    window.draw(m_text);
}

void PlayingState::insertCoin(){
    m_pacMan.die();
    
}
void PlayingState::pressButton(){
    m_ghost.setWeak(sf::seconds(3));
}
void PlayingState::moveStick(sf::Vector2i direction){
    
    
}
void PlayingState::update(sf::Time delta){
    m_pacMan.update(delta);
    m_ghost.update(delta);
}
void PlayingState::draw(sf::RenderWindow& window){
    window.draw(m_pacMan);
    window.draw(m_ghost);
}

void WonState::insertCoin(){
    
}
void WonState::pressButton(){
    
}
void WonState::moveStick(sf::Vector2i direction){
    
}
void WonState::update(sf::Time delta){
    static sf::Time timeBuffer = sf::Time::Zero;
    timeBuffer += delta;
    
    if(timeBuffer.asSeconds() > 5)
        getGame()->changeGameState(GameState::GetReady);
}
void WonState::draw(sf::RenderWindow& window){
    window.draw(m_text);
}

void LostState::insertCoin(){
    
}
void LostState::pressButton(){
    
}
void LostState::moveStick(sf::Vector2i direction){
    
}
void LostState::update(sf::Time delta){
    m_countDown += delta;
    if(m_countDown.asSeconds() >= 10)
        getGame()->changeGameState(GameState::NoCoin);
    
    m_countDownText.setString("Insert a coin to continue... " + std::to_string(10- static_cast<int>(m_countDown.asSeconds())));
}
void LostState::draw(sf::RenderWindow& window){
    window.draw(m_text);
    window.draw(m_countDownText);
}
