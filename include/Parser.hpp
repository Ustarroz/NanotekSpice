//
// Created by puilla_e on 01/02/17.
//

#ifndef NANOTEKSPICE_PARSER_HPP
#define NANOTEKSPICE_PARSER_HPP

#include <string>
#include <vector>
#include "IParser.hpp"

namespace nts
{
  class Parser : public nts::IParser
  {
    t_ast_node *root;
    t_ast_node *current;
    std::vector<std::string> component_name;
   public:

    Parser();
      Parser(const Parser &other);
    ~Parser();
      Parser& operator=(const Parser &other);

    void feed(std::string const &input);
    void parseTree(nts::t_ast_node &root);
    nts::t_ast_node *createTree();
    void lexer(std::string input);
    void create_tree(std::string lexeme, nts::ASTNodeType type);
    std::vector<struct s_ast_node*> * create_links(std::string lexeme, nts::ASTNodeType type);
    std::vector<struct s_ast_node*> * create_components(std::string lexeme, nts::ASTNodeType type);
    int checker(t_ast_node &node, int i);
    t_ast_node * getRoot() const;
      t_ast_node * getCurrent() const;
      std::vector getComponent() const;
  };
}

#endif //NANOTEKSPICE_PARSER_HPP
