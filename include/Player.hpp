//
// Created by lihao on 9/02/2025.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "SFML/Graphics.hpp"


class Player {
public:
    Player(sf::Sprite  sprite, float moveSpeed);

private:
    sf::Sprite sprite;
    float &moveSpeed;
};


#endif //PLAYER_HPP
