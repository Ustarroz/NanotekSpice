//
// Created by puilla_e on 01/02/17.
//

#include <algorithm>
#include "Parser.hpp"

nts::Parser::Parser()
{
    this->current = new t_ast_node;
    this->root =    new t_ast_node *;
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

int nts::Parser::checker(nts::t_ast_node const &node, int i)
{
    if (!check)
        check;
    else
        return -1;

    if ((!node.children)[i]->check)
        checker(node, i);
    else if (node.children[++i] != NULL)
    checker(node, ++i);
}

void nts::Parser::parseTree(nts::t_ast_node &root)
{
    if ((*root.children)[0]->lexeme != ".chipsets:"
        && (*root.children)[1]->lexeme != ".links:"
        || (*root.children)[0]->lexeme != ".links:"
        && (*root.children)[1]->lexeme != ".chipset:")
        throw;
    if (root.lexeme == "" && root.value == "")
        throw;
    checker(root, 0);
}

nts::t_ast_node *nts::Parser::createTree()
{
  return *root;
}

void nts::Parser::lexer(std::string input)
{
    std::string::size_type n = 0;
    if (input[0] == ' ')
        input.erase(std::remove(input.begin(), input.end(), ' '), input.end());
    input.erase(std::remove(input.begin(), input.end(), '\t'), input.end());
    input.erase(std::remove(input.begin(), input.end(), '\n'), input.end());
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
            if ((*root)->type == (ASTNodeType) 1)
            {
                if ((*root)->lexeme == ".chipset:")
                {
                    current = *root;
                }
                    create_tree(input.substr(n, 5), (ASTNodeType) 2);
                }
                if ((*root)->lexeme == ".links:")
                {
                    current = *root;
                    create_tree(input.substr(n, 5), (ASTNodeType) 3);
                }
            break;
        }
        default:
        {
            create_tree(input, current->type);
        if (input.find(":") == -1)
        {
            create_tree(input.substr(0, input.find(" ")), current->type);
            create_tree(input.substr(input.find("")), current->type);
            if ((*(*root)->children)[0]->lexeme == ".chipset:")
                current = (*(*root)->children)[0];
            else
                current = (*(*root)->children)[1];
        }
            else
            create_tree(input.substr(0, input.find(" ")), current->type);
            create_tree(input.substr(input.find(" ")), current->type);
            if ((*(*root)->children)[0]->lexeme == ".links:")
            current = (*(*root)->children)[0];
            else
            current = (*(*root)->children)[1];
        }
    }
}

void nts::Parser::create_tree(std::string lexeme, nts::ASTNodeType type) {
    nts::t_ast_node *tmp = new t_ast_node;
    nts::t_ast_node *son = new t_ast_node;
    nts::t_ast_node *daughter = new t_ast_node;

    if (lexeme.find(" ") != -1) {
        tmp->lexeme = lexeme;
        tmp->type = type;
    } else {
        tmp->lexeme = lexeme;
        if (current->lexeme == ".chipset:")
            tmp->type = (ASTNodeType) 2;
        if (current->lexeme == ".links")
            tmp->type = (ASTNodeType) 3;
        //VERIFIER LES PROBLEMES DE PARENTHESES !
        if (lexeme.find("(") != -1 && lexeme.find(")") != -1 && lexeme.find(")") == lexeme.size() - 1) {
            daughter->value = lexeme.substr(lexeme.find("(") + 1, lexeme.find(")") - 1);
        }
        son->lexeme = lexeme.substr(0, lexeme.find(":"));
        son->type = (ASTNodeType) 4;
        daughter->lexeme = lexeme;
        daughter->type = (ASTNodeType) 4;
    }
    current->children->push_back(tmp);
    current = tmp;
}