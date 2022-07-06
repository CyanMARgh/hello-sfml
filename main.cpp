#include <SFML/Graphics.hpp>
#include <cstdint>

typedef sf::Vector2f vec2;

int main() {
    const uint16_t win_size = 800;

    sf::CircleShape cursor;
    sf::RenderWindow window(sf::VideoMode(win_size, win_size), "", sf::Style::Close);

    float R = 10;
    while(window.isOpen()) {
        vec2 mpos = (vec2)sf::Mouse::getPosition(window);
        for(sf::Event e; window.pollEvent(e);) {
            if (e.type == sf::Event::Closed) window.close();
            else if(e.type == sf::Event::MouseWheelMoved) R += e.mouseWheel.delta;
        }

        cursor.setRadius(R);
        cursor.setOrigin(R, R);
        cursor.setPosition(mpos);

        window.clear();
        window.draw(cursor);
        window.display();
    }

    return 0;
}