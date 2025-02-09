//
// Created by lihao on 10/02/2025.
//

#include "Character.hpp"

Character::Character(sf::Sprite &sprite): sprite(sprite) {
}

sf::Sprite &Character::getSprite() const {
    return sprite;
}
