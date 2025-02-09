//
// Created by lihao on 10/02/2025.
//

#ifndef CHARACTERSELECT_HPP
#define CHARACTERSELECT_HPP
#include "Character.hpp"
#include "SFML/Graphics.hpp"

class CharacterSelect {
public:
    CharacterSelect(sf::RenderWindow &window, std::vector<Character> &characters, sf::Text &text);

    void render() const;

    void run() const;

private:
    sf::RenderWindow &window;
    std::vector<Character> &characters;
    sf::Text &text;
};


#endif //CHARACTERSELECT_HPP
