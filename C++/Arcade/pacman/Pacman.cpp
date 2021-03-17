/*
** EPITECH PROJECT, 2020
** pac
** File description:
** man
*/

#include "Pacman.hpp"

void Game::createMap(std::string const &filename)
{
    std::ifstream file(filename);
    std :: string line;
    std::string data = "";

    if (file) {
        while (getline(file, line))
            data += line + "\n";
    } else {
        std :: cerr << "Error: "<< filename << " not found !" << std :: endl;
        return;
    }
    file.close();
    parseDataInMap(data);
}

void Game::parseDataInMap(std::string const &data)
{
    int x = 0;
    int y = 0;
    int max_x = 0;
    int max_y = 0;

    for (char c: data) {
        if (c != '\n' && c != '\0')
            _map[x][y] = c;
        else {
            _map[x][y] = '\0';
            x += 1;
            max_y = y - 1;
            y = 0;
        }
        y += 1;
    }
    max_x = x - 1;
    _mapSize = std::make_pair(max_x, max_y);
}

void Game::displayMap() {
    for (auto x : _map ) {
        for (auto y : x.second) {
            if (y.second == 'p')
                printw(".");
            else if (y.second == 'P')
                printw("o");
            else
                printw("%c", y.second);
        }
        printw("\n");
    }
}

void Game::cmdDisplayMap() {
    for (auto x : _map ) {
        for (auto y : x.second) {
            if (y.second == 'p')
                std::cout << "·";
            else if (y.second == 'P')
                std::cout << "o";
            else
                std::cout << y.second;
        }
        std::cout << std::endl;
    }
}

Game gameLoop(Game &game)
{
    static int press;
    if ((press = getch()) == 'z' || press == 's' || press == 'q' || press == 'd' || press == '\n')
    {
        if (press == 'z')
            game.pac.setDirection(Pacman::Direction::UP);
        if (press == 's')
            game.pac.setDirection(Pacman::Direction::DOWN);
        if (press == 'q')
            game.pac.setDirection(Pacman::Direction::LEFT);
        if (press == 'd')
            game.pac.setDirection(Pacman::Direction::RIGHT);
        if (press == '\n')
           game.setGameStatus(Game::Status::END);
    }
    else
        press = 'j';
    int Y = game.pac.getX();
    int X = game.pac.getY();
    char newPos;
    if (game.pac.getDirection() == Pacman::Direction::LEFT && game._map[Y][X - 1] != 'X') {
        game._map[Y][X] = ' ';
        game.pac.setPos(X - 1, Y);
        newPos = game._map[Y][X - 1];
        game._map[Y][X - 1] = 'C';
    } else if (game.pac.getDirection() == Pacman::Direction::RIGHT && game._map[Y][X + 1] != 'X') {
        game._map[Y][X] = ' ';
        game.pac.setPos(X + 1, Y);
        newPos = game._map[Y][X + 1];
        game._map[Y][X + 1] = 'C';
    } else if (game.pac.getDirection() == Pacman::Direction::UP && game._map[Y - 1][X] != 'X') {
        game._map[Y][X] = ' ';
        game.pac.setPos(X, Y - 1);
        newPos = game._map[Y - 1][X];
        game._map[Y - 1][X] = 'C';
    } else if (game.pac.getDirection() == Pacman::Direction::DOWN && game._map[Y + 1][X] != 'X') {
        game._map[Y][X] = ' ';
        game.pac.setPos(X, Y + 1);
        newPos = game._map[Y + 1][X];
        game._map[Y + 1][X] = 'C';
    }
    if (newPos == 'G')
        game.setGameStatus(Game::Status::END);
    return game;
}

int main()
{
    Game game;

    //game.cmdDisplayMap();
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    while(game.getGameStatus() == Game::Status::PLAYING) {
        clear();
        game.displayMap();
        refresh();
        usleep(150000);
        gameLoop(game);
    }
    endwin();
    return(0);
}