//
// Created by puilla_e on 01/02/17.
//

#include <algorithm>
#include "Parser.hpp"

nts::Parser::Parser()
{
  nts::t_ast_node *first;

  first = new nts::t_ast_node;
  this->root = first;
}

void nts::Parser::feed(std::string const &strong)
{
  std::string	input;

  input = strong;
  if (strong == "" || strong[0] == '#')
    return ;
  _input += "\n" + strong;
   lexer(strong);
}

void nts::Parser::parseTree(nts::t_ast_node &root)
{

}

nts::t_ast_node *nts::Parser::createTree()
{
  //nts::t_ast_node *ret = nullptr;

  return this->root;
}

void nts::Parser::lexer(std::string input)
{
    std::string::size_type n = 0;

    if (input[0] == ' ')
        std::replace(input.begin(), input.end(), ' ', '');
    std::replace(input.begin(), input.end(), '\t', '');
    std::replace(input.begin(), input.end(), '\n', '');
    switch (input[0])
    {
        case '.':
        {
            if ((n = input.find(".links:")) == (unsigned long) -1)
                return;
            else
                input.replace(n, 6, "");
                create_tree(".links:", (ASTNodeType) 1);
            if ((n = input.find(".chipset:")) == (unsigned long) -1)
                return;
            else
                 input.replace(n, 9, "");
                 create_tree(".chipset:", (ASTNodeType) 1);
            break;
        }
        case 'i':
        {
            if (root->type == (ASTNodeType) 1);
            {
                if (root->lexeme == ".chipset:")
                {
                    //RESET CURSEUR
                }
                    create_tree(input.substr(n, 5), (ASTNodeType) 2);
                }
                if (root->lexeme == ".links:")
                {
                    // RESET CURSEUR
                    create_tree(input.substr(n, 5), (ASTNodeType) 3);
                }
            break;
        }
        default:
        {
            create_tree(input, root->type);
        if (input.find(":") == -1)
        {
        create_tree(input.substr(0, input.find(" ")), root->type);
            create_tree(input.substr(input.find("")), root->type);
            //RESET CURSEUR VERS .CHIPSET
        }
            else
            create_tree(input.substr(0, input.find(" ")), root->type);
            create_tree(input.substr(input.find(" ")), root->type);
            //RESET CURSEUR VERS .LINKS
        }
            break;
    }
}

void nts::Parser::create_tree(std::string lexeme, nts::ASTNodeType type)
{
    nts::t_ast_node	                    *tmp = nullptr;
    nts::t_ast_node                     *son = nullptr;
    nts::t_ast_node                     *daughter = nullptr;

    tmp ,son, daughter = new nts::t_ast_node;
    if (lexeme.find(" ") != -1)
    {
        tmp->lexeme = lexeme;
        tmp->type = type;
    }
    else
    {
        tmp->lexeme = lexeme;
        if (root->lexeme == ".chipset:")
            tmp->type = (ASTNodeType) 2;
        if (root->lexeme == ".links")
            tmp->type = (ASTNodeType) 3;
        if (lexeme.find("(") != -1 && lexeme.find(")") != -1 && lexeme.find(")") == lexeme.size() -1);
        {
            daughter->value = lexeme.substr(lexeme.find("(") + 1, lexeme.find(")") - 1);
        }
        son->lexeme = lexeme.substr(0, lexeme.find(":"));
        son->type = (ASTNodeType) 4;
        daughter->lexeme = lexeme;
        daughter->type = (ASTNodeType) 4;
    }
    root->children->push_back(tmp);
    root = tmp;
}

