//
// Created by puilla_e on 03/02/17.
//

#include <algorithm>
#include "GateNOr.hpp"
#include "Component4001.hpp"

nts::Component4001::Component4001(std::string const &name) : AComponent(name)
{
  this->_comp.push_back(new GateNOr(1, 2, 3));
  this->_comp.push_back(new GateNOr(5, 6, 4));
  this->_comp.push_back(new GateNOr(8, 9, 10));
  this->_comp.push_back(new GateNOr(12, 13, 11));
}