#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <windows.h>


using std::cout;
using namespace std;
namespace ps {
    class AnimatedText {
    private:
        string copy_line;
        string current_line = "";
        float timer;
        int i = 0;
    public:
        sf::Text text;
        sf::Font font;

        const void Initialization(string * line, int * duration) {
            copy_line = *line;

            font.loadFromFile("arial.ttf");
            text.setFont(font);
            text.setCharacterSize(96);
            text.setFillColor(sf::Color::Red);
            text.setStyle(sf::Text::Bold);
            text.setString("debug");

            timer = float(* duration)/copy_line.size()*1000;

        }
        const void Animator(){
            if(i < copy_line.size()){
                current_line.push_back(copy_line[i]);
                text.setString(current_line);
                Sleep(timer);
                i++;
            }
        }
    };
}

int main()
{
    string line;
    int duration;

    cout << "What line do you want to animate" << endl;
    getline(cin, line);
    cout << "Type in length of animation in seconds"<< endl;
    cin >> duration;
    cout << "Now open Animation window"<< endl;

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Animation window");

    ps::AnimatedText ani;
    ani.Initialization(&line, &duration);
    Sleep(750);

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        ani.Animator();
        window.clear();
        window.draw(ani.text);
        window.display();
    }

    return 0;
}

