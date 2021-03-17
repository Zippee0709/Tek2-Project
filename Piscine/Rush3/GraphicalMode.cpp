/*
** EPITECH PROJECT, 2020
** cpp_rush3_2019
** File description:
** GraphicalMode
*/

#include "GraphicalMode.hpp"
#include "TextBox.hpp"
#include "GraphicBox.hpp"
#include <map>
#include <string>

GraphicalMode::GraphicalMode()
{
}

GraphicalMode::~GraphicalMode()
{
}

void GraphicalMode::setImage(std::string file)
{
    texture.loadFromFile(file);
    sprite.setTexture(texture);
    sprite.setColor(sf::Color(255,255,255,128));
}

sf::Text GraphicalMode::setText(std::string message, int x, int y)
{
    font.loadFromFile("srcs/Lobster_1.3.otf");
    text.setFont(font);
    text.setString(message);
    text.setCharacterSize(24);
    text.setPosition(x, y);
    return text;
}

void GraphicalMode::window()
{
    sf::RenderWindow window(sf::VideoMode(400, 1100), "SFML works!", sf::Style::Titlebar);
    TextBox userName({400, 100}, {0, 0}, info.getUsername(), "Username : ");
    TextBox hostName({400, 100}, {0, 100}, info.getHostname(), "Hostname : ");
    TextBox kernelVersion({400, 100}, {0, 200}, info.getKernel(), "Kernel : ");
    TextBox dateTime({400, 100}, {0, 300}, info.getDateTime(), "DateTime : ");
    TextBox os({400, 100}, {0, 400}, info.getOs(), "Os : ");

    float test;
    int size = info.getConfNbrProc();
    std::map<int, GraphicBox> cpuArr;

    for (int i = 1; i <= size; i++) {
        test = (i * 100.00);
        std::string title("CPU ");
            
        title.append(std::to_string(i - 1));
        GraphicBox gb({400, 100}, {0, 400 + test}, title);
        gb.setRectangle();
        cpuArr.insert(std::map<int, GraphicBox>::value_type(i, gb));
    }

    setImage("srcs/background.jpg");

    userName.setRectangle();
    userName.drawText();
    hostName.setRectangle();
    hostName.drawText();
    kernelVersion.setRectangle();
    kernelVersion.drawText();
    dateTime.setRectangle();
    dateTime.drawText();
    os.setRectangle();
    os.drawText();
    /*  */
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
        }
        info.update();
        userName.setText(info.getUsername());
        hostName.setText(info.getHostname());
        kernelVersion.setText(info.getKernel());
        dateTime.setText(info.getDateTime());
        os.setText(info.getOs());
        window.clear();
        int counter = 0;
        std::map<std::string, std::string>cpu_map = info.getCPUinfo();
        for (auto &x : cpuArr) {
            std::string str("CPU Mhz ");
            
            str.append(std::to_string(counter));
            sf::RectangleShape graph({std::stof(cpu_map[str])/10, 10});
            graph.setFillColor(sf::Color(100, 250, 50));
            graph.setPosition(0, x.second.getRectangle().getPosition().y + 75);
            window.draw(graph);
            window.draw(x.second.getTitle());
            x.second.draw(window);
            counter++;
        }
        window.draw(sprite);
        userName.draw(window);
        hostName.draw(window);
        kernelVersion.draw(window);
        dateTime.draw(window);
        os.draw(window);
        window.display();
    }
}