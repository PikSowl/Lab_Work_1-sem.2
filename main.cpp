#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <windows.h>


using std::cout;
using namespace std;

void scaling(sf::Text *text){
    if(text->getCharacterSize() < 81){
        Sleep(1000);
        text->setCharacterSize(text->getCharacterSize() * 3);
        std::cout << "aaa";
    }
}

int main()
{

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");

    sf::Font font;
    font.loadFromFile("arial.ttf");

    sf::Text text;
    text.setFont(font);
    text.setString("This text is animated");
    text.setCharacterSize(1);
    text.setFillColor(sf::Color::Red);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined);


    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        scaling(&text);
        window.draw(text);
        window.display();
    }

    return 0;
}

