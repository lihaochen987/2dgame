//
// Created by lihao on 9/02/2025.
//

#include <utility>

#include "../include/Player.hpp"

Player::Player(sf::Sprite sprite, const float moveSpeed): sprite(std::move(sprite)), moveSpeed(moveSpeed) {
};

