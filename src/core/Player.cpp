//
// Created by lihao on 9/02/2025.
//

#include "../include/Player.hpp"

Player::Player(const sf::Sprite &sprite, const float moveSpeed, sf::RenderWindow &window): sprite(sprite),
    moveSpeed(moveSpeed), window(window) {
}

sf::Sprite &Player::getSprite() {
    return sprite;
}

float Player::getMoveSpeed() const {
    return moveSpeed;
}

void Player::move() {
    const sf::Vector2f position = sprite.getPosition();
    const sf::FloatRect spriteBounds = sprite.getGlobalBounds();

    if (isKeyPressed(sf::Keyboard::Key::Left)) {
        if (position.x > 0) {
            sprite.move(sf::Vector2f(-moveSpeed, 0));
        }
    }
    if (isKeyPressed(sf::Keyboard::Key::Right)) {
        if (position.x + spriteBounds.size.x < static_cast<float>(window.getSize().x)) {
            sprite.move(sf::Vector2f(moveSpeed, 0));
        }
    }
    if (isKeyPressed(sf::Keyboard::Key::Up)) {
        if (position.y > 0) {
            sprite.move(sf::Vector2f(0, -moveSpeed));
        }
    }
    if (isKeyPressed(sf::Keyboard::Key::Down)) {
        if (position.y + spriteBounds.size.y < static_cast<float>(window.getSize().y)) {
            sprite.move(sf::Vector2f(0, moveSpeed));
        }
    }
};
