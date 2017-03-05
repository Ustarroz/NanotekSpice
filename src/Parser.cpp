// Created by puilla_e on 01/02/17.
//
#include <iostream>
#include <algorithm>
#include "Parser.hpp"
#include "Error.hpp"

nts::Parser::Parser()
{
  this->root = new t_ast_node;
  this->current = root;
  current->children = new std::vector<nts::t_ast_node *>;
  this->root->type = nts::ASTNodeType::DEFAULT;

}

void nts::Parser::feed(std::string const &strong)
{
  if (strong == "" || strong[0] == '#')
    return ;
  lexer(strong);
}

int nts::Parser::checker(nts::t_ast_node &node, int i)
{
    if (!node.check)
        node.check = true;
    else
        throw Error("An unexpected error as occured", 1);
    if (node.type == nts::ASTNodeType::COMPONENT)
    {
        int j = 0;
        std::vector<std::string>::iterator it;
        it = component_name.begin();
        while (it != component_name.end())
            if (*it == (*node.children)[1]->lexeme)
                j++;
        if (j >= 2)
            throw Error("Lexeme: Same component name used twice", -1);
    }
  std::cout<< node.lexeme <<  " i = " << i <<std::endl;

  if (((node.children) != NULL) && !(*node.children)[i]->check)
    checker((*(*node.children)[i]), i);
  else if (node.children!= NULL && i + 1 <= (*node.children).size() && !(*node.children)[i + 1]->check)
    checker((*(*node.children)[i]), i + 1);
  return 0;
}

void nts::Parser::parseTree(nts::t_ast_node &root)
{
  if ((*root.children)[0]->lexeme != ".chipsets:"
      && ((*root.children)[0]->lexeme != ".links:"))
    throw Error("Lexer: Information file not complete", -1);
  if ((*root.children)[0]->lexeme == "")
    throw Error ("Lexer: Information file not complete", -1);
  checker(root, 0);
}

nts::t_ast_node *nts::Parser::createTree()
{
  return root;
}

static bool space_supr(char c1, char c2)
{
  return c1 == ' ' && c2 == ' ';
}

static char tab_to_space(char ch)
{
  return ch == '\t' ? ' ' : ch;
}

void nts::Parser::lexer(std::string input)
{
  std::string     line;

  std::transform(line.begin(), line.end(), line.begin(), &tab_to_space);
  std::unique_copy(input.begin(), input.end(), std::back_inserter(line), &space_supr);
  if (line[0] == ' ')
    line = line.substr(1);
  line.erase(std::remove(line.begin(), line.end(), '\n'), line.end());
  switch (line[0])
    {
      case '.':
	{
	  if (line == ".links:")
	    {
	      create_tree(".links:", nts::ASTNodeType::SECTION);
	      break;
	    }
	  else if (line == ".chipsets:")
	    {
	      create_tree(".chipsets:", nts::ASTNodeType::SECTION);
	      break;
	    }
	  else
	    throw Error("Lexer: Syntax error", -1);
	}
      default:
	{
	  if (current->type == nts::ASTNodeType::SECTION && current->lexeme == ".chipsets:")
	    create_tree(line.substr(0, line.find(" ")), nts::ASTNodeType::COMPONENT);
	  else if (current->type == nts::ASTNodeType::SECTION && current->lexeme == ".links:")
	    create_tree(line, nts::ASTNodeType::LINK);
	  else
	    throw Error("Lexer: Syntax error", -1);
	}
    }
}

std::vector<struct s_ast_node*> * nts::Parser::create_components(std::string lexeme, nts::ASTNodeType type)
{
  std::vector<struct s_ast_node*> *tmp;
  t_ast_node *node;
  std::string substr;
  size_t pos;

  switch (type)
    {
      case (nts::ASTNodeType::COMPONENT):
	{
	  tmp = new std::vector<struct s_ast_node*>;
	  if ((pos = lexeme.find_first_of(' ')) == std::string::npos)
	    throw Error("Lexer: no component name", -1);
	  substr = lexeme.substr(0, pos);
	  node = new t_ast_node(create_links(substr, ASTNodeType::STRING));
	  node->lexeme = substr;
	  node->type = ASTNodeType::STRING;
	  tmp->push_back(node);
	  substr = lexeme.substr(pos + 1);
        component_name.push_back(substr);
	  node = new t_ast_node(create_links(substr, ASTNodeType::STRING));
	  node->lexeme = substr;
	  node->type = ASTNodeType::STRING;
	  tmp->push_back(node);
	  break;
	}
      default:
	{
	  tmp = nullptr;
	  break;
	}
    }
  return (tmp);
}

std::vector<struct s_ast_node*> * nts::Parser::create_links(std::string lexeme, nts::ASTNodeType type)
{
  std::vector<struct s_ast_node*> *tmp;
  t_ast_node *node;
  std::string substr;
  size_t pos;

  switch (type)
    {
      case (nts::ASTNodeType::LINK):
	{
	  tmp = new std::vector<struct s_ast_node*>;
	  if ((pos = lexeme.find_first_of(' ')) == std::string::npos)
	    throw Error("Lexer: only one links end", -1);
	  substr = lexeme.substr(0, pos);
	  node = new t_ast_node(create_links(substr, ASTNodeType::LINK_END));
	  node->lexeme = substr;
	  node->type = ASTNodeType::LINK_END;
	  tmp->push_back(node);
	  substr = lexeme.substr(pos + 1);
	  node = new t_ast_node(create_links(substr, ASTNodeType::LINK_END));
	  node->lexeme = substr;
	  node->type = ASTNodeType::LINK_END;
	  tmp->push_back(new t_ast_node(create_links(substr, ASTNodeType::LINK_END)));
	  break;
	}
      case (nts::ASTNodeType::LINK_END):
	{
	  tmp = new std::vector<struct s_ast_node*>;
	  if ((pos = lexeme.find_first_of(':')) == std::string::npos)
	    throw Error("Lexer: only one links end", -1);
	  substr = lexeme.substr(0, pos);
	  node = new t_ast_node(create_links(substr, ASTNodeType::STRING));
	  node->lexeme = substr;
	  node->type = ASTNodeType::STRING;
	  tmp->push_back(node);
	  substr = lexeme.substr(pos + 1);
	  node = new t_ast_node(create_links(substr, ASTNodeType::STRING));
	  node->lexeme = substr;
	  node->type = ASTNodeType::STRING;
	  tmp->push_back(node);
	  break;
	}
      default:
	{
	  tmp = nullptr;
	  break;
	}
    }
  return (tmp);
}

void nts::Parser::create_tree(std::string lexeme, nts::ASTNodeType type)
{
  nts::t_ast_node *node;

  switch (type)
    {
      case (ASTNodeType::SECTION):
	{
	  if (this->root->children->size() == 1 && (*this->root->children)[0]->lexeme == lexeme)
	    {
	      throw Error("Lexer: same name section", -1);
	    }
	  if (this->root->children->size() == 2)
	    {
	      throw Error("Lexer: too much section", -1);
	    }
	  node = new nts::t_ast_node;
	  node->children = new std::vector<struct s_ast_node*>;
	  this->current = node;
	  this->root->children->push_back(node);
	}
      case (ASTNodeType::LINK) :
	{
	  node = new nts::t_ast_node(create_links(lexeme, type));
	  this->current->children->push_back(node);
	  break;
	}
      case (ASTNodeType::COMPONENT) :
	{
	  node = new nts::t_ast_node(create_components(lexeme, type));
	  this->current->children->push_back(node);
	  break;
	}
      default:
	throw Error("Lexer: unknown children", -1);
    }
  node->lexeme = lexeme;
  node->type = type;
  node->value = "";
}