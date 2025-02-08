//
// Created by lihao on 9/02/2025.
//

#include <utility>

#include "../include/Player.hpp"

Player::Player(const sf::Sprite &sprite, const float moveSpeed): sprite(sprite), moveSpeed(moveSpeed) {
}

sf::Sprite &Player::getSprite() {
    return sprite;
}

float Player::getMoveSpeed() const {
    return moveSpeed;
};
