/*
** EPITECH PROJECT, 2020
** main.c
** File description:
** main.c
*/

#include <iostream>
#include <fstream>
#include <string>

int read_file(char *name, char *exec)
{
    std :: ifstream file(name);
    if (file) {
        std :: string line;
        while (getline(file, line))
            std :: cout << line << std :: endl;
    } else {
        std :: cerr << "my_cat: "<< name << ": No such file or directory" << std :: endl;
        return (84);
    }
    file.close();
    return (0);
}

int main(int ac, char **av)
{
    if (ac < 2) {
        std ::  cerr << "my_cat: Usage: " << av[0] << " file [...]" << std :: endl;
        return (84);
    }
    for (int i = 1; i < ac; i++) {
        if (read_file(av[i], av[0]) == 84)
            return (84);
    }
    return (0);
}