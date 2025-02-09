//
// Created by lihao on 9/02/2025.
//

#include "../include/Game.hpp"

void Game::render() const {
    window.clear();
    window.draw(player.getSprite());
    window.draw(text);
    window.display();
}

Game::Game(sf::RenderWindow &window, Player &player, sf::Text &text, sf::Music &music)
    : window(window)
      , player(player)
      , text(text)
      , music(music) {
}

void Game::run() const {
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        player.move();
        render();
    }
}
