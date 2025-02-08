//
// Created by lihao on 9/02/2025.
//

#ifndef GAME_HPP
#define GAME_HPP
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


class Game {
public:
    Game(sf::RenderWindow& window, sf::Sprite& sprite, sf::Text& text, sf::Music& music, float moveSpeed);
    void run() const;

private:
    void handleInput() const;
    void render() const;

    sf::RenderWindow& window;
    sf::Sprite& sprite;
    sf::Text& text;
    sf::Music& music;
    float moveSpeed;
};


#endif //GAME_HPP
