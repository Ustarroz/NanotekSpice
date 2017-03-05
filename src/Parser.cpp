//
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
    this->root->type = (ASTNodeType) -1;
}

void nts::Parser::feed(std::string const &strong)
{
  if (strong == "" || strong[0] == '#')
    return ;
   lexer(strong);
}

int nts::Parser::checker(nts::t_ast_node &node, int i)
{
    std::cout<< node.lexeme <<  " i = " << i <<std::endl;
       if (!node.check)
        node.check = true;
    else
        return -1;
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
            throw Error("Lexer: Synthax error", -1);
        }
        default:
        {
            if (current->type == nts::ASTNodeType::SECTION && current->lexeme == ".chipsets:")
                create_tree(line.substr(0, line.find(" ")), nts::ASTNodeType::COMPONENT);
            else if (current->type == nts::ASTNodeType::SECTION && current->lexeme == ".links:")
                create_tree(line.substr(0, line.find(" ")), nts::ASTNodeType::SECTION);
            else if (current->type == nts::ASTNodeType::COMPONENT || current->type == nts::ASTNodeType::LINK)
                        create_tree(line.substr(0, line.find(" ")), current->type);
            if (line.find(":") == -1)
                create_tree(line.substr(line.find(" ")), current->type);
            else
            {
                create_tree(line, nts::ASTNodeType::STRING);
                create_tree(line , nts::ASTNodeType::NEWLINE);
            }
        }
    }
}

void nts::Parser::create_tree(std::string lexeme, nts::ASTNodeType type)
{
    nts::t_ast_node *tmp = new nts::t_ast_node;
    nts::t_ast_node *daughter = new nts::t_ast_node;
    nts::t_ast_node *son = new nts::t_ast_node;
    nts::t_ast_node *value = new nts::t_ast_node;

            tmp->lexeme = lexeme;
            tmp->type = type;
            if (lexeme.find("(") != -1 && lexeme.find(")") != -1 && lexeme.find(")") == lexeme.size() - 1)
            {
                daughter->value = lexeme.substr(lexeme.find("(") + 1, lexeme.find(")") - 1);
                daughter->type = (ASTNodeType) 4;
                current->children->push_back(daughter);
            }
        else if ((lexeme.find_first_of('(') == std::string::npos && lexeme.find_first_of(')') != std::string::npos) ||
                (lexeme.find_first_of('(') != std::string::npos && lexeme.find_first_of(')') == std::string::npos))
            throw Error("Lexer: error, Synthax errror", -1);

    if (type == (ASTNodeType) 0)
    {
        son->lexeme = lexeme.substr(0, lexeme.find(":") -1);
        son->type = (ASTNodeType) 4;
        daughter->lexeme = lexeme.substr(lexeme.find(":") + 1, lexeme.find(" ") - 1);
        daughter->type = (ASTNodeType) 4;
        (*current->children)[0]->children->push_back(son);
        (*current->children)[0]->children->push_back(daughter);
        lexeme.replace(0, lexeme.find(" ") - 1, "");
        tmp->lexeme = lexeme.substr(lexeme.find(" ") + 1, lexeme.find(":") - 1);
        tmp->type = (ASTNodeType) 4;
        value->lexeme = lexeme.substr(lexeme.find(":") + 1);
        value->type = (ASTNodeType) 4;
        (*current->children)[1]->children->push_back(tmp);
        (*current->children)[1]->children->push_back(value);
    }

    if (lexeme.find(":") != -1 && lexeme.find(" ") != -1 && type != (ASTNodeType) 0)
    {
        son->lexeme = lexeme.substr(0, lexeme.find(" "));
        son->type = (ASTNodeType) 3;
        daughter->lexeme = lexeme.substr(lexeme.find(" ") + 1);
        daughter->type = (ASTNodeType) 3;
    }

    if (current->children == NULL)
        current->children = new std::vector<t_ast_node *>;
    current->children->push_back(tmp);
    if ((*current->children).size() != 0 && type != (ASTNodeType) 3)
        current = tmp;
}