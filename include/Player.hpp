//
// Created by lihao on 9/02/2025.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "SFML/Graphics.hpp"


class Player {
public:
    Player(sf::Sprite sprite, float moveSpeed, sf::RenderWindow &window);

    sf::Sprite &getSprite();

    float getMoveSpeed() const;

    void move();

private:
    sf::Sprite sprite;
    float moveSpeed;
    sf::RenderWindow &window;
};


#endif //PLAYER_HPP
