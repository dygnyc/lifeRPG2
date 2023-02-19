#include <iostream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Player.h"

using namespace std;

int main()
{

    // Create the main window
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML window");

    // Create a graphical text to display
    sf::Font font;
    if (!font.loadFromFile("VCR_MONO.ttf"))
        return EXIT_FAILURE;

    sf::Text messageText;
    sf::Text statsText;
    sf::Text actionText;
    // default text positions
    sf::Vector2f messagePos(10, 300);
    sf::Vector2f actionPos(10, 400);
    sf::Vector2f statsPos(10, 10);

    messageText.setFont(font);
    messageText.setCharacterSize(48);
    messageText.setFillColor(sf::Color::White);
    messageText.setPosition(messagePos);

    statsText.setFont(font);
    statsText.setCharacterSize(48);
    statsText.setFillColor(sf::Color::White);
    statsText.setPosition(statsPos);

    actionText.setFont(font);
    actionText.setCharacterSize(48);
    actionText.setFillColor(sf::Color::White);
    actionText.setPosition(actionPos);

    Player gamePlayer;
    string statsTextString;
    string actionTextString;

    // Start the game loop
    while (window.isOpen())
    {
        // Process events
        sf::Event event;
        while (window.pollEvent(event))
        {
            // Close window: exit
            if (event.type == sf::Event::Closed)
                window.close();

            messageText.setString("Do you want to: \n(W)ork (S)hop (Q)uit?");

            if (event.type == sf::Event::KeyPressed)
            {

                if (event.key.code ==sf::Keyboard::W)
                {
                    gamePlayer.nextDay();
                    gamePlayer.work();

                    actionTextString = "You went to work\nand earned: " + 
                    to_string(gamePlayer.getSalary());

                    actionText.setString(actionTextString);
                }

                else if (event.key.code ==sf::Keyboard::S)
                {
                    gamePlayer.nextDay();
                    gamePlayer.buyStuff();
                    actionTextString = "You went to shopping\nand spent: " + 
                    to_string(gamePlayer.getSalary());
                    actionText.setString(actionTextString);
                }
                else if (event.key.code ==sf::Keyboard::Q)
                {

                    window.close();
                    exit;
                }
            }

            statsTextString = gamePlayer.getName() + '\n' +
                              "day: " + to_string(gamePlayer.getDay()) + '\n' +
                              "money: " + to_string(gamePlayer.getMoney()) + '\n' +
                              "salary: " + to_string(gamePlayer.getSalary()) + '\n' +
                              "stuff: " + to_string(gamePlayer.getStuff());

            statsText.setString(statsTextString);
        }

        // Clear screen
        window.clear();

        // Draw the string
        window.draw(messageText);
        window.draw(actionText);
        window.draw(statsText);

        // Update the window
        window.display();
    }

    exit;
    return 0;
}