//
// Created by lihao on 9/02/2025.
//

#ifndef GAME_HPP
#define GAME_HPP
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"


class Game {
    sf::RenderWindow &window;
    sf::Sprite &sprite;
    sf::Text &text;
    sf::Music &music;

    void handleInput() const {
        constexpr float moveSpeed = 0.5f;
        const sf::Vector2f position = sprite.getPosition();
        const sf::FloatRect spriteBounds = sprite.getGlobalBounds();

        if (isKeyPressed(sf::Keyboard::Key::Left)) {
            if (position.x > 0) {
                sprite.move(sf::Vector2f(-moveSpeed, 0));
            }
        }
        if (isKeyPressed(sf::Keyboard::Key::Right)) {
            if (position.x + spriteBounds.position.length() < static_cast<float>(window.getSize().x)) {
                sprite.move(sf::Vector2f(moveSpeed, 0));
            }
        }
        if (isKeyPressed(sf::Keyboard::Key::Up)) {
            if (position.y > 0) {
                sprite.move(sf::Vector2f(0, -moveSpeed));
            }
        }
        if (isKeyPressed(sf::Keyboard::Key::Down)) {
            if (position.y + spriteBounds.position.length() < static_cast<float>(window.getSize().y)) {
                sprite.move(sf::Vector2f(0, moveSpeed));
            }
        }
    }

    void render() const {
        window.clear();
        window.draw(sprite);
        window.draw(text);
        window.display();
    }

public:
    Game(sf::RenderWindow &window, sf::Sprite &sprite, sf::Text &text, sf::Music &music)
        : window(window)
          , sprite(sprite)
          , text(text)
          , music(music) {
        music.setLooping(true);
        music.play();
    }

    void run() const {
        while (window.isOpen()) {
            while (const std::optional event = window.pollEvent()) {
                if (event->is<sf::Event::Closed>()) {
                    window.close();
                }
            }

            handleInput();
            render();
        }
    }
};


#endif //GAME_HPP
