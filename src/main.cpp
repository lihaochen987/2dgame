#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <filesystem>

#include "CharacterSelect.hpp"
#include "Player.hpp"
#include "../include/Game.hpp"

int main() {
    // Screen
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Epic Game");


    sf::Texture texture;
    if (!texture.loadFromFile("assets/wallace.jpg")) {
        return -1;
    }
    sf::Sprite wallaceSprite(texture);
    const sf::Font font("assets/arial.ttf");


    // Character select
    auto wallace = Character(wallaceSprite);
    std::vector characters{wallace};
    sf::Text characterSelectText(font, "Choose your character", 30);
    CharacterSelect characterSelect(window, characters, characterSelectText);
    characterSelect.run();

    wallaceSprite.setScale(sf::Vector2f(0.25f, 0.25f));

    sf::FloatRect spriteBounds = wallaceSprite.getGlobalBounds();
    wallaceSprite.setPosition(sf::Vector2f(400 - spriteBounds.size.x / 2,
                                           300 - spriteBounds.size.y / 2));

    sf::Text text(font, "I'M IN A GAME GROMIT!", 50);

    sf::Music music;
    if (!music.openFromFile("assets/wallace_and_gromit_theme.mp3")) {
        return -1;
    }
    music.setLooping(true);
    music.play();

    Player player(wallaceSprite, 0.5f, window);

    // Game start
    Game game(window, player, text, music);
    game.run();

    return 0;
}
