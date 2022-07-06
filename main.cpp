#include <SFML/Graphics.hpp>
#include <cstdint>
#include <cstdio>

typedef sf::Vector2f vec2;

int main() {
    const uint32_t win_size = 800;

    sf::CircleShape cursor;
    sf::RenderWindow window(sf::VideoMode(win_size, win_size), "", sf::Style::Close);

    float R = 10;
    while(window.isOpen()) {
        vec2 mpos = (vec2)sf::Mouse::getPosition(window);
        for(sf::Event e; window.pollEvent(e);) {
            if (e.type == sf::Event::Closed) {
                window.close();
            } else if(e.type == sf::Event::MouseWheelMoved) {
                R += e.mouseWheel.delta;
            } else if(e.type == sf::Event::KeyPressed) {
                if(e.key.code == sf::Keyboard::K) puts("pressed key K!");                    
            } else if(e.type == sf::Event::MouseButtonPressed) {
                puts("pressed button!");                    
            }
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