//
// Created by puilla_e on 03/02/17.
//

#include <algorithm>
#include "GateNAnd.hpp"
#include "Component4011.hpp"

nts::Component4011::Component4011(std::string const &name) : AComponent(name)
{
  this->_comp.push_back(new GateNAnd(1, 2, 3));
  this->_comp.push_back(new GateNAnd(5, 6, 4));
  this->_comp.push_back(new GateNAnd(8, 9, 10));
  this->_comp.push_back(new GateNAnd(12, 13, 11));
}