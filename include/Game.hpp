//
// Created by lihao on 9/02/2025.
//

#ifndef GAME_HPP
#define GAME_HPP
#include "Player.hpp"
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


class Game {
public:
    Game(sf::RenderWindow &window, Player &player, sf::Text &text, sf::Music &music);

    void run() const;

private:
    void handleInput() const;

    void render() const;

    sf::RenderWindow &window;
    Player &player;
    sf::Text &text;
    sf::Music &music;
};


#endif //GAME_HPP
