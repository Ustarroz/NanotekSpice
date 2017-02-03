//
// Created by puilla_e on 01/02/17.
//

#include <algorithm>
#include "Parser.hpp"

nts::Parser::Parser(t_ast_node *root)
{
  t_ast_node tmp;

  tmp = new(sizeof(t_ast_node));
  this->*root = tmp;
  this->
}

void nts::Parser::feed(std::string const &strong)
{
  std::string::size_type n;
  std::string::size_type space;
  std::string	input;
  t_ast_node	*tmp;
  int i = 0;

  input = strong;
  tmp = new(t_ast_node);
  if (strong == "" || strong[0] == '#')
    return ;
  _input += "\n" + strong;
    {
      if (input[0] == ' ')
	std::replace(input.begin(), input.end(), ' ', '');
        std::replace(input.begin(), input.end(), '\t', '');
      switch (input[0])
	{
	  case '.':
	    {
	     if ((n = input.find(".links:")) == (unsigned long) -1)
	       return;
	     else
	       input.replace(n, 6, "");
	       tmp->lexeme = ".links:";
	       tmp->type = (ASTNodeType) 1;
	       tmp->value = "";
	       root->children->assign(0,tmp);
	       root = tmp;
	      if ((n = input.find(".chipset:")) == (unsigned long) -1)
	    return;
	  else
	    	input.replace(n, 9, "");
	      	tmp->lexeme = ".chipset:";
	      	tmp->type = (ASTNodeType) 1;
	      	tmp->value = "";
	      	root->children->assign(0,tmp);
	      	root = tmp;
	      break;
	    }
	  case 'i':
	    {
	      if ((n = input.find("input")) == (unsigned long) -1)
		{
		  if ((space = input.find(" ")) == (unsigned long) -1)
		    return;
		}
	      while (i != n)
		tmp->lexeme += input.c_str()[i++];
	      if (root->type == (ASTNodeType) 1);
	      {
		if (root->lexeme == ".chipset:")
		  tmp->type = (ASTNodeType) 2;
		if (root->lexeme == ".links:")
		  tmp->type = (ASTNodeType) 3;
		else
		  tmp->type = root->type;
	      }
	      i = 0;
	      std::string::size_type size;
	      for(size = 0; size < input.length(); size++)
		{
		  tmp->lexeme.c_str()[i++] = input.c_str()[size];
		}
	      break;
	    }
	  default:
	    break;
	}
    }
}

void nts::Parser::parseTree(nts::t_ast_node &root)
{

}

nts::t_ast_node *nts::Parser::createTree()
{
  nts::t_ast_node *ret = nullptr;

  return this->root;
}

