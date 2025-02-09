//
// Created by lihao on 10/02/2025.
//

#include "CharacterSelect.hpp"

CharacterSelect::CharacterSelect(sf::RenderWindow &window, std::vector<Character> &characters,
                                 sf::Text &text): window(window), characters(characters), text(text) {
}

void CharacterSelect::render() const {
    window.clear();
    window.draw(characters[0].getSprite());
    window.draw(text);
    window.display();
}

void CharacterSelect::run() const {
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }

        render();
    }
}
