#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <filesystem>

#include "Player.hpp"
#include "../include/Game.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Epic Game");

    sf::Texture texture;
    if (!texture.loadFromFile("assets/cute_image.jpg")) {
        return -1;
    }

    sf::Sprite sprite(texture);
    sprite.setScale(sf::Vector2f(0.25f, 0.25f));

    sf::FloatRect spriteBounds = sprite.getGlobalBounds();
    sprite.setPosition(sf::Vector2f(400 - spriteBounds.position.x / 2,
                                  300 - spriteBounds.position.y / 2));

    const sf::Font font("assets/arial.ttf");
    sf::Text text(font, "I'M IN A GAME GROMIT!", 50);

    sf::Music music;
    if (!music.openFromFile("assets/nice_music.mp3")) {
        return -1;
    }

    Player player(sprite, 1.0f);

    Game game(window, sprite, text, music);
    game.run();

    return 0;
}
