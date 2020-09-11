//
//  GameState.cpp
//  PacMan
//
//  Created by Vladimir on 11.09.2020.
//  Copyright © 2020 Vladimir. All rights reserved.
//

#include "GameState.hpp"
#include "Game.hpp"


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
    
}
GetReadyState::GetReadyState(Game* game)
: GameState(game)
{
    
}
PlayingState::PlayingState(Game* game)
: GameState(game)
{
    
}
WonState::WonState(Game* game)
: GameState(game)
{
    
}
LostState::LostState(Game* game)
: GameState(game)
{
    
}


void NoCoinState::insertCoin(){
    
}
void NoCoinState::pressButton(){
    
}
void NoCoinState::moveStick(sf::Vector2i direction){
    
}
void NoCoinState::update(sf::Time delta){
    
}
void NoCoinState::draw(sf::RenderWindow& window){
    
}

void GetReadyState::insertCoin(){
    
}
void GetReadyState::pressButton(){
    
}
void GetReadyState::moveStick(sf::Vector2i direction){
    
}
void GetReadyState::update(sf::Time delta){
    
}
void GetReadyState::draw(sf::RenderWindow& window){
    
}

void PlayingState::insertCoin(){
    
}
void PlayingState::pressButton(){
    
}
void PlayingState::moveStick(sf::Vector2i direction){
    
}
void PlayingState::update(sf::Time delta){
    
}
void PlayingState::draw(sf::RenderWindow& window){
    
}

void WonState::insertCoin(){
    
}
void WonState::pressButton(){
    
}
void WonState::moveStick(sf::Vector2i direction){
    
}
void WonState::update(sf::Time delta){
    
}
void WonState::draw(sf::RenderWindow& window){
    
}

void LostState::insertCoin(){
    
}
void LostState::pressButton(){
    
}
void LostState::moveStick(sf::Vector2i direction){
    
}
void LostState::update(sf::Time delta){
    
}
void LostState::draw(sf::RenderWindow& window){
    
}
