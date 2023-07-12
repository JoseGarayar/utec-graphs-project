#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "Graph/Models/airport.h"
#include "Graph/graph.h"

void showRoute(vector<Vertex<Airport, float>*> points){

    try
    {
  
    
        sf::RenderWindow window =  sf::RenderWindow(sf::VideoMode(1024, 768), "Sistema de coordenadas");
        window.setVerticalSyncEnabled(false);
        sf::Font font;
        if (!font.loadFromFile("/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf")) { // Reemplaza "arial.ttf" por la ruta y el nombre de tu archivo de fuente        
            throw out_of_range("Error al cargar la fuente.");      
        }

        sf::Text text;
        text.setFont(font);
        text.setCharacterSize(10);
        text.setFillColor(sf::Color::Red);

        sf::CircleShape point(5);
        point.setFillColor(sf::Color::Red);

        while (window.isOpen())
            {
                sf::Event event;
                while (window.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window.close();
                }

                window.clear();

                // Dibuja los puntos y los textos
                for (std::size_t i = 0; i < points.size(); ++i) {
                    float x = (std::stof(points[i]->data.longitude) + 180.0f) * (window.getSize().x / 360.0f);
                    float y = (90.0f - std::stof(points[i]->data.latitude)) * (window.getSize().y / 180.0f);

                    point.setPosition(x, y);
                    window.draw(point);

                    text.setString(points[i]->data.city );
                    text.setCharacterSize(14);
                    text.setPosition(x + 10, y - 10);
                    window.draw(text);

                    text.setString("(" + points[i]->data.latitude + ", " + points[i]->data.longitude + ")");
                    text.setCharacterSize(11);
                    text.setPosition(x , y + 10);
                    window.draw(text);

                    if (i > 0) {
                        float prevX = (std::stof(points[i - 1]->data.longitude) + 180.0f) * (window.getSize().x / 360.0f);
                        float prevY = (90.0f - std::stof(points[i - 1]->data.latitude)) * (window.getSize().y / 180.0f);

                        sf::Vertex line[] = {
                            sf::Vertex(sf::Vector2f(prevX, prevY), sf::Color::Red),
                            sf::Vertex(sf::Vector2f(x, y), sf::Color::Red)
                        };

                        window.draw(line, 2, sf::Lines);
                    }
                }

                window.display();
            }
                /* code */
        }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}