//
// Created by puilla_e on 01/02/17.
//

#include "Parser.hpp"

nts::Parser::Parser() : _input("")
{

}

void nts::Parser::feed(std::__cxx11::string const &input)
{
  if (input == "" || input[0] == '#')
    return ;
  _input += "\n" + input;
}

void nts::Parser::parseTree(nts::t_ast_node &root)
{

}

nts::t_ast_node *nts::Parser::createTree()
{
  nts::t_ast_node *ret = nullptr;

  if (_input == "")
    return (ret);

  while (_input != "")
    {
      switch (_input[0])
	{
	  case ':':
	    break;
	  case ' ':
	  case '\t':
	    break;
	  case '.':
	    break;
	  default:
	    break;
	}
    }
  return (ret);
}
