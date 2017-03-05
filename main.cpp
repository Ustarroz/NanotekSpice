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
#include <sstream>
#include "Parser.hpp"
#include "Circuit.hpp"

int	main(int ac, char **av) {
  nts::t_ast_node *tree;
  nts::Parser object;
  std::string line;

  if (ac < 1)
    {
      std::cerr << "Wrong usage: " << av[0]
		<< " circuit_file.nts input_name=input_value" << std::endl;
      return 0;
    }
  std::ifstream file(av[1]);

  if (file.is_open())
    {
      while (std::getline(file, line))
	{
	  std::istringstream ligne(line);
	  object.feed(ligne.str());
	}
      tree = object.createTree();
      object.parseTree(*tree);
    }
  else
    {
      std::cerr << "error: can't open file" << std::endl;
      return 0;
    }
  nts::Circuit cir(tree);
  std::string cmd;
  for (int i = 2; i < ac; i++)
    {
      cir.setInput(av[i]);
    }
  cir.checkCircuit();
  cir.execute_command("simulate");
  cir.execute_command("display");
  while (std::getline(std::cin, cmd) && cir.execute_command(cmd));
  return 0;
}