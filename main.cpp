#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <filesystem>

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "Epic Game");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("assets/cute_image.jpg")) {
        // Handle loading error
        return -1;
    }
    sf::Sprite sprite(texture);
    sprite.setScale(sf::Vector2f(0.25f, 0.25f));

    sf::FloatRect spriteBounds = sprite.getGlobalBounds();

    sprite.setPosition(sf::Vector2f(400 - spriteBounds.position.x / 2, 300 - spriteBounds.position.y / 2));

    // Create a graphical text to display
    const sf::Font font("assets/arial.ttf");
    const sf::Text text(font, "I'M IN A GAME GROMIT!", 50);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("assets/nice_music.mp3")) {
        // Handle loading error
        return -1;
    }

    // Play the music
    music.setLooping(true);
    music.play();

    // Start the game loop
    while (window.isOpen()) {
        constexpr float moveSpeed = 0.5f;
        // Process events
        while (const std::optional event = window.pollEvent()) {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        sf::Vector2f position = sprite.getPosition();
        spriteBounds = sprite.getGlobalBounds();

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

        // Clear screen
        window.clear();

        // Draw the sprite
        window.draw(sprite);

        // Draw the string
        window.draw(text);

        // Update the window
        window.display();
    }
    return 0;
}
