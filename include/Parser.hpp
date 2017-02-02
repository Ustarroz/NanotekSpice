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
    std::string _input;
    //Circuit *_circ;
   public:
    Parser();

    void feed(std::__cxx11::string const &input);

    void parseTree(nts::t_ast_node &root);

    nts::t_ast_node *createTree();
  };
}

#endif //NANOTEKSPICE_PARSER_HPP