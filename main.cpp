#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <filesystem>

int main() {
    // Create the main window
    sf::RenderWindow window(sf::VideoMode({800, 600}), "SFML window");

    // Load a sprite to display
    sf::Texture texture;
    if (!texture.loadFromFile("assets/cute_image.jpg")) {
        // Handle loading error
        return -1;
    }
    const sf::Sprite sprite(texture);

    // Create a graphical text to display
    const sf::Font font("assets/arial.ttf");
    const sf::Text text(font, "Hello SFML", 50);

    // Load a music to play
    sf::Music music;
    if (!music.openFromFile("assets/nice_music.mp3")) {
        // Handle loading error
        return -1;
    }

    // Play the music
    music.play();

    // Start the game loop
    while (window.isOpen()) {
        // Process events
        while (const std::optional event = window.pollEvent()) {
            // Close window: exit
            if (event->is<sf::Event::Closed>())
                window.close();
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
