//
// Created by lihao on 10/02/2025.
//

#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "SFML/Graphics.hpp"


class Character {
public:
    Character(sf::Sprite &sprite);

    sf::Sprite &getSprite() const;

private:
    sf::Sprite &sprite;
};


#endif //CHARACTER_HPP
