//
// main.cpp for bojou in /home/voyevoda/rendu/cpp/cpp_nanotekspice
//
// Made by voyevoda
// Login   <voyevoda@epitech.net>
//
// Started on  Thu Feb  2 15:19:50 2017 voyevoda
// Last update Thu Feb  2 15:20:49 2017 voyevoda
//

/* Main to try circuit
#include <iostream>
#include "Circuit.hpp"

int	main(int ac, char **av)
{
  if (ac <= 1)
    {
      return 0;
    }
  nts::Circuit cir(nullptr);
  std::string line;
  for (int i = 2; i != ac; i++)
    {
      cir.setInput(av[i]);
    }
  cir.checkCircuit();
  cir.execute_command("simulate");
  cir.execute_command("display");
  while (std::getline(std::cin, line) && cir.execute_command(line));
}
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include "Parser.hpp"
int	main(int ac, char **av)
{
    if (ac != 2)
    {
        nts::t_ast_node *tree;
        nts::Parser object;
        std::ifstream file(av[1]);
        std::string line;
        while (std::getline(file, line))
        {
            std::istringstream ligne(line);
            object.feed(ligne.str());
        }
        tree = object.createTree();
        object.parseTree(tree);
    }
    else
        std::cout << "Wrong usage: ./nanotekspice [config_file] attended" << std::endl;
    return 0;
    }