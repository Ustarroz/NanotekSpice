//
// Created by puilla_e on 01/02/17.
//

#include "Parser.hpp"

nts::Parser::Parser() : _input("")
{

}

void nts::Parser::feed(std::__cxx11::string const &input)
{
  if (input == "")
    return;
  _input += "\n" + input;
}

void nts::Parser::parseTree(nts::t_ast_node &root)
{

}

nts::t_ast_node *nts::Parser::createTree()
{

  return nullptr;
}
