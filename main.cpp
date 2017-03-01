//
// main.cpp for bojou in /home/voyevoda/rendu/cpp/cpp_nanotekspice
//
// Made by voyevoda
// Login   <voyevoda@epitech.net>
//
// Started on  Thu Feb  2 15:19:50 2017 voyevoda
// Last update Thu Feb  2 15:20:49 2017 voyevoda
//
#include <iostream>
#include <fstream>

int	main(int ac, char **av)
{
    if (ac != 2)
        std::ifstream file;
    file.open(av[1]);
    file.close();
    std::string tmp;
    while(std::getline(file, tmp)) {
}
